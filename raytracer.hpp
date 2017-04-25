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

	~Raytracer();

	void generateImage(Geometry& geo);

	QImage getImage();

private:
	vector< vector<Pixel> > image;

	//add helper methods that need image access here

};

//double dist(Line3d line);


#endif