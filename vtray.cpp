// implement vtray main here
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <QImage>
#include <QString>

#include "geometry.hpp"
#include "raytracer.hpp"
#include "json_parsing_error.hpp"

using std::string;
using std::stringstream;
using std::endl;
using std::cerr;

int main(int argc, char*argv[])
{
	if (argc == 3)
	{
		string infilename(argv[1]);

		std::ifstream infile(infilename);
		if (!infile.is_open())
		{
			cerr << "Error: File could not be opened" << endl;
			return EXIT_FAILURE;
		}
		char c;
		stringstream ss;
		while (infile.get(c))
		{
			ss << c;
		}
		infile.close();
		try
		{
			string outfilename(argv[2]);
			QString picname = QString::fromStdString(outfilename);
			//make geometry
			Geometry geo(ss.str());
			//do all calculation and output stuff in here
			Raytracer rt;
			rt.generateImage(geo);

			QImage pic = rt.getImage();
			if (pic.isNull())
			{
				cerr << "Error: Image unable to be generated." << endl;
				return EXIT_FAILURE;
			}
			pic.save(picname);

			//temp testing shit
			//std::cout << geo.lights.size() << " lights" << endl;
			//std::cout << geo.shapes.size() << " shapes" << endl;
		}
		catch (JSONParsingError& error)
		{
			cerr << error.what() << endl;
			return EXIT_FAILURE;
		}
	}
	else if (argc == 5)
	{
		string cmdtag(argv[1]);
		string threadcount(argv[2]);
		string infilename(argv[3]);

		int numthreads = stoi(threadcount);
		if (cmdtag != "-t")
		{
			cerr << "Error: invalid tag, use \"-t\"" << endl;
			return EXIT_FAILURE;
		}
		if (numthreads <= 0)
		{
			cerr << "Error: invalid number of threads" << endl;
			return EXIT_FAILURE;
		}
		size_t tc = numthreads;
		std::ifstream infile(infilename);
		if (!infile.is_open())
		{
			cerr << "Error: File could not be opened" << endl;
			return EXIT_FAILURE;
		}
		char c;
		stringstream ss;
		while (infile.get(c))
		{
			ss << c;
		}
		infile.close();
		try
		{
			string outfilename(argv[4]);
			QString picname = QString::fromStdString(outfilename);
			//make geometry
			Geometry geo(ss.str());
			//do all calculation and output stuff in here
			Raytracer rt(tc);
			rt.generateImage(geo);
			QImage pic = rt.getImage();
			if (pic.isNull())
			{
				cerr << "Error: Image unable to be generated." << endl;
				return EXIT_FAILURE;
			}
			pic.save(picname);

			//temp testing shit
			//std::cout << geo.lights.size() << " lights" << endl;
			//std::cout << geo.shapes.size() << " shapes" << endl;
		}
		catch (JSONParsingError& error)
		{
			cerr << error.what() << endl;
			return EXIT_FAILURE;
		}

	}
	else
	{
		cerr << "Error: invalid number of arguments" << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}