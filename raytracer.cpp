#include "raytracer.hpp"
#include <QImage>
#include <QColor>
#include <QPoint>
#include <cmath>
#include <iostream>
#include <list>
#include <thread>
#include <future>
#include <utility>

Raytracer::Raytracer(size_t threadnum)
{
	threadcount = threadnum;
	maxVals.resize(threadcount, 0);
}

Raytracer::Raytracer()
{
	threadcount = 1;
	maxVals.resize(threadcount, 0);
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
	vector<std::thread> threads;
	//vector<std::future> futs;
	//second, iterate over the whole matrix to make the thing
	//size_t threadindex = 0;
	for (size_t threadindex = 0; threadindex < threadcount; ++threadindex)
	{
		//std::promise<double> p;
		//threads.push_back(std::thread(&Raytracer::getMaxValue, this, std::move(p), geo, threadindex));
		threads.push_back(std::thread(&Raytracer::raytrace, this, geo, threadindex));
	}
	for (size_t i = 0; i < threads.size(); ++i)
	{
		threads[i].join();
	}
	for (size_t n = 0; n < maxVals.size(); ++n)
	{
		//std::cout << maxVals[n] << std::endl;
		if (maxVals[n] > maxValue)
		{
			maxValue = maxVals[n];
		}
	}
	if (maxValue > 0)
	{
		for (size_t y = 0; y < image[0].size(); ++y)
		{
			for (size_t x = 0; x < image.size(); ++x)
			{
				image[x][y].r = double(image[x][y].r) * 255.0 / maxValue;
				//std::cout << image[x][y].r << " ";
				//if (image[x][y].r > 255) {image[x][y].r = 0;}
				image[x][y].g = double(image[x][y].g) * 255.0 / maxValue;
				//std::cout << image[x][y].g << " ";
				//if (image[x][y].g > 255) {image[x][y].g = 0;}
				image[x][y].b = double(image[x][y].b) * 255.0 / maxValue;
				//std::cout << image[x][y].b << std::endl;
				//if (image[x][y].b > 255) {image[x][y].b = 0;}
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

void Raytracer::raytrace(Geometry geo, size_t threadindex)
{
	Vec3d f2p;
	double maxValue = 0;
	f2p.startpt = multPt(subPts(geo.camera.center, geo.camera.normal), geo.camera.focus);
	for (int pixY = 0; pixY < geo.camera.sizeY; ++pixY)
	{
		for (int pixX = threadindex; pixX < geo.camera.sizeX; pixX += threadcount)
		{
			//third, in each iteration, do the calculation stuff
			double minT = 10e10;
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
			for (size_t i = 0; i < geo.shapes.size(); ++i)
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
				Shape cameraPlane;
				cameraPlane.type = plane;
				cameraPlane.normal = geo.camera.normal;
				cameraPlane.center = geo.camera.center;
				for (size_t i = 0; i < geo.lights.size(); ++i)
				{
					vec2light.dirpt = subPts(geo.lights[i].location, vec2light.startpt);
					vec2light.normalize();
					if (closestObj.type == sphere)
					{
						closestObj.normal = subPts(vec2light.startpt, closestObj.center);
						if (closestObj.radius > 0)
						{
							closestObj.normal = multPt(closestObj.normal, double(1/closestObj.radius));
						}
					}
					double dp = dotProduct(closestObj.normal, vec2light.dirpt);
					if (dp >= 0)
					{
						//std::cout << "Starting next light check" << std::endl;
						bool clear = true;
						double camPlaneDist;
						bool lightBehindCamera = cameraPlane.intersect(vec2light.startpt, vec2light.dirpt, 0, camPlaneDist);
						for (size_t j = 0; j < geo.shapes.size(); ++j)
						{
							double tester;
							if (geo.shapes[j].intersect(vec2light.startpt, vec2light.dirpt, 0, tester))
							{
								if (lightBehindCamera)
								{
									if (tester > 0.00001 && tester <= camPlaneDist)
									{
										clear = false;
										break;
									}
								}
								else
								{
									if (tester > 0.00001)
									{
										clear = false;
										break;
									}
								}
							}
						}
						if (clear)
						{
							//std::cout << "Closest Object Normal: " << closestObj.normal.x << "," << closestObj.normal.y << "," << closestObj.normal.z << std::endl;
							scaleFactor += dp * closestObj.lambert * geo.lights[i].intensity;
							//std::cout << "it is in fact clear and the scaleFactor is now: " << scaleFactor << std::endl;
						}
						/*else
						{
							//std::string otype = (closestObj.type == sphere) ? "sphere" : "plane";
							//std::cout << "Shaded object: " << otype << std::endl;
							std::cout << "bruh it's not clear" << std::endl;
						}*/
					}
					/*else
					{
						//std::string otype = (closestObj.type == sphere) ? "sphere" : "plane";
						//std::cout << "Shaded object: " << otype << std::endl;
					}*/
					
				}
				/*if (scaleFactor > 0)
				{
					std::cout << "yo lit fam scaleFactor is greater than zero boiiiiiii" << std::endl;
				}*/
				if (scaleFactor < 0)
				{
					//std::cout << "your scaleFactor is negative this should not be happening" << std::endl;
					scaleFactor = 0;
				}
				//std::cout << "scaleFactor: " << scaleFactor << std::endl;
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
	maxVals[threadindex] = maxValue;
}

//void Raytracer::getMaxValue(std::promise<double>&& p, Geometry& geo, size_t& threadindex)
//{
	//p.set_value(raytrace(geo, threadindex));
//}