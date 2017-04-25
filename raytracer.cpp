#include "raytracer.hpp"
#include <QImage>
#include <QColor>
#include <QPoint>
#include <cmath>
#include <iostream>

Raytracer::Raytracer()
{

}

Raytracer::~Raytracer()
{
	
}

void Raytracer::generateImage(Geometry& geo)
{
	//first make the empty image with the right dimensions
	Pixel zero;
	zero.r = 0;
	zero.g = 0;
	zero.b = 0;
	vector<Pixel> zerovec;
	zerovec.resize(geo.camera.sizeY, zero);
	image.resize(geo.camera.sizeX, zerovec);
	double maxValue = 0;
	//second, iterate over the whole matrix to make the thing
	Vec3d f2p;
	f2p.startpt = multPt(subPts(geo.camera.center, geo.camera.normal), geo.camera.focus);
	for (int pixY = 0; pixY < geo.camera.sizeY; ++pixY)
	{
		for (int pixX = 0; pixX < geo.camera.sizeX; ++pixX)
		{
			//third, in each iteration, do the calculation stuff
			double minT;
			Shape closestObj;
			closestObj.type = none;
			double tempX = geo.camera.center.x + (geo.camera.resX * (pixX - (geo.camera.sizeX/2)));
			double tempY = geo.camera.center.y + (geo.camera.resY * (pixY - (geo.camera.sizeY/2)));
			double tempZ = geo.camera.center.z;
			f2p.dirpt.x = tempX - f2p.startpt.x;
			f2p.dirpt.y = tempY - f2p.startpt.y;
			f2p.dirpt.z = tempZ - f2p.startpt.z;
			double tLimit = f2p.magnitude();
			f2p.normalize();
			for (int i = 0; i < geo.shapes.size(); ++i)
			{
				double t;
				if (geo.shapes[i].intersect(f2p.startpt, f2p.dirpt, tLimit, t))
				{
					if (i == 0 || t < minT)
					{
						minT = t;
						closestObj = geo.shapes[i];
					}
				}
			}
			if (closestObj.type != none)
			{
				Vec3d vec2light;
				vec2light.startpt.x = f2p.startpt.x + f2p.dirpt.x * minT;
				vec2light.startpt.y = f2p.startpt.y + f2p.dirpt.y * minT;
				vec2light.startpt.z = f2p.startpt.z + f2p.dirpt.z * minT;
				double scaleFactor = 0;
				for (int i = 0; i < geo.lights.size(); ++i)
				{
					vec2light.dirpt.x = geo.lights[i].location.x - vec2light.startpt.x;
					vec2light.dirpt.y = geo.lights[i].location.y - vec2light.startpt.y;
					vec2light.dirpt.z = geo.lights[i].location.z - vec2light.startpt.z;
					vec2light.normalize();
					bool clear = true;
					for (int j = 0; j < geo.shapes.size(); ++j)
					{
						double tester;
						if (geo.shapes[j].intersect(vec2light.startpt, vec2light.dirpt, 0, tester))
						{
							if (tester > 0.0001)
							{
								clear = false;
								break;
							}
						}
					}
					if (clear)
					{
						if (closestObj.type == sphere)
						{
							closestObj.normal = subPts(vec2light.startpt, closestObj.center);
							Vec3d tempv3d;
							tempv3d.dirpt = closestObj.normal;
							tempv3d.normalize();
							closestObj.normal = tempv3d.dirpt;
						}
						if (dotProduct(closestObj.normal, vec2light.dirpt) > 0)
						{
							scaleFactor += dotProduct(closestObj.normal, vec2light.dirpt) * closestObj.lambert * geo.lights[i].intensity;
						}
					}
				}
				image[pixX][pixY].r = scaleFactor * closestObj.r;
				image[pixX][pixY].g = scaleFactor * closestObj.g;
				image[pixX][pixY].b = scaleFactor * closestObj.b;
				if (image[pixX][pixY].r > maxValue)
				{
					maxValue = image[pixX][pixY].r;
				}
				if (image[pixX][pixY].g > maxValue)
				{
					maxValue = image[pixX][pixY].g;
				}
				if (image[pixX][pixY].b > maxValue)
				{
					maxValue = image[pixX][pixY].b;
				}
			}
		}
	}
	if (maxValue > 0)
	{
		for (int y = 0; y < image[0].size(); ++y)
		{
			for (int x = 0; x < image.size(); ++x)
			{
				image[x][y].r = image[x][y].r * (255/maxValue);
				image[x][y].g = image[x][y].g * (255/maxValue);
				image[x][y].b = image[x][y].b * (255/maxValue);
			}
		}
	}
}

QImage Raytracer::getImage()
{
	if (image.size() > 0 && image[0].size() > 0)
	{
		QImage newImage(image.size(), image[0].size(), QImage::Format_RGB32);
		for (int y = 0; y < newImage.height(); ++y)
		{
			for (int x = 0; x < newImage.width(); ++x)
			{
				/*if (image[x][y].r > 0)
				{
					std::cout << "r: " << image[x][y].r << ", g: " << image[x][y].g << ", b: " << image[x][y].b << std::endl;
				}*/
				QColor color(image[x][y].r, image[x][y].g, image[x][y].b);
				newImage.setPixel(x, y, color.rgb());
			}
		}
		return newImage;
	}
	QImage defaultImage;
	return defaultImage;
}

