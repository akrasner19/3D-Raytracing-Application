#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include "geometry.hpp"
#include <QImage>
#include <vector>

using std::vector;

/*
struct Vec3d
{
	Point unitvec;
};*/

struct Pixel
{
	int r;
	int g;
	int b;
};

class Raytracer
{
public:
	Raytracer();

	Raytracer(size_t threadnum);

	~Raytracer();

	void generateImage(Geometry& geo);

	QImage getImage();

	void raytrace(Geometry geo, size_t threadindex);

private:
	vector< vector<Pixel> > image;

	size_t threadcount;

	vector<double> maxVals;
	//add helper methods that need image access in here

};

//double dist(Line3d line);


#endif