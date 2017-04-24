#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <QJsonDocument>
#include <string>
#include <vector>

enum Type {sphere, plane};

struct Point
{
	double x;
	double y;
	double z;
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