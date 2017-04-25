#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <QJsonDocument>
#include <string>
#include <vector>

enum Type {sphere, plane, none};

struct Point
{
	double x;
	double y;
	double z;
};

double dotProduct(Point p1, Point p2);

Point subPts(Point p1, Point p2);

Point multPt(Point p, double factor);

Point addPts(Point p1, Point p2);

double dist(Point p1, Point p2);

bool solveQuadratic(double a, double b, double c, double& t1, double& t2);

struct Vec3d
{
	Point startpt;
	Point dirpt;
	double magnitude()
	{
		Point zero;
		zero.x = 0;
		zero.y = 0;
		zero.z = 0;
		return dist(zero, dirpt);
	}

	void normalize()
	{
		double mag = magnitude();
		if (mag != 0)
		{
			dirpt = multPt(dirpt, 1/mag);
		}
	}
};

struct Light
{
	Point location;
	double intensity;
};

struct Shape
{
	Type type;
	Point center;
	Point normal;
	double radius;
	int r;
	int g;
	int b;
	double lambert;
	bool intersect(Point start, Point direction, double tLimit, double& t)
	{
		if (type == sphere)
		{
			double t1, t2;
			Point pt = subPts(start, center);
			double a = dotProduct(direction, direction);
			double b = 2 * dotProduct(direction, pt);
			double c = dotProduct(pt, pt) - (radius * radius);
			if (!solveQuadratic(a, b, c, t1, t2))
			{
				return false;
			}
			if (t1 > t2)
			{
				double temp = t1;
				t1 = t2;
				t2 = temp;
			}
			if (t1 < tLimit)
			{
				t1 = t2;
				if (t1 < tLimit)
				{
					return false;
				}
			}
			Vec3d testtemp;
			testtemp.dirpt = multPt(direction, t1);
			if (testtemp.magnitude() > 0.0001)
			{
				t = t1;
				return true;
			}
			return false;			
		}
		else if (type == plane)
		{
			double denominator = dotProduct(normal,direction); 
		    if (denominator > 1e-6 || denominator < -1e-6) 
		    { 
		        Point centerstart = subPts(center, start); 
		        t = dotProduct(centerstart, normal) / denominator; 
		        return (t >= tLimit); 
		    }
    		return false; 
		}
		else
		{
			return false;
		}
	}
};

struct Camera
{
	Point center;
	Point normal;
	double focus;
	double sizeX;
	double sizeY;
	double resX;
	double resY;
};

class Geometry
{
public:
	Geometry(std::string filetext);

	~Geometry();

	//put publicly accessable environment here
	std::vector<Light> lights;
	std::vector<Shape> shapes;

	Camera camera;
private:
};

void validate(QJsonDocument& env);
bool isValidCoord(QJsonValue val);
bool isValidRadius(QJsonValue val);
bool isValidIntensity(QJsonValue val);
bool isValidLambert(QJsonValue val);
bool isValidColor(QJsonValue val);
bool isValidSize(QJsonValue val);
bool isValidRes(QJsonValue val);

#endif