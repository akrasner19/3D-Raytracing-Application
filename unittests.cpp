#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
// IMPORTANT NOTE:
// These are just a few examples from my solution and **should be removed**.
// Depending on your code design your class and functions names would differ

#include "geometry.hpp"
#include "raytracer.hpp"
#include "json_parsing_error.hpp"
#include <string>
#include <QImage>

/*TEST_CASE( "Test Basic Geometry: Vec3d ", "[geometry]" ) {

  Vec3d a(2,0,0), b(0,4,0);
  
  REQUIRE(a.x == Approx(2));
  REQUIRE(a.y == Approx(0));
  REQUIRE(a.z == Approx(0));

  REQUIRE(b.x == Approx(0));
  REQUIRE(b.y == Approx(4));
  REQUIRE(b.z == Approx(0));

  double adotb = dot(a,b);
  REQUIRE(adotb == Approx(0));

  Vec3d anorm = norm(a);
  REQUIRE(anorm.x == Approx(1));
  REQUIRE(anorm.y == Approx(0));
  REQUIRE(anorm.z == Approx(0));

  Vec3d bnorm = norm(b);
  REQUIRE(bnorm.x == Approx(0));
  REQUIRE(bnorm.y == Approx(1));
  REQUIRE(bnorm.z == Approx(0));
}*/

TEST_CASE("Test Validation Function For Camera", "[geometry]")
{
	{
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(ok);
	}

	{ //3 bad
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": \"bad\", \"y\": \"bad\", \"z\": \"bad\"}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //2 bad
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": \"bad\", \"z\": \"bad\"}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //1 bad
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": \"bad\"}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //3 bad
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": \"bad\", \"y\": \"bad\", \"z\": \"bad\"}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //2 bad
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": \"bad\", \"z\": \"bad\"}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //1 bad
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": \"bad\"}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //test bad focus
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": \"bad\", "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //test 2 bad res 
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [\"bad\", \"bad\"], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //test 2 neg res 
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [-1, -1], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //bad size
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [\"bad\", \"bad\"] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //neg size
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [-1,-1] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //float size
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [1.5,1.5] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}
}

TEST_CASE("Test Validation Function For Lights", "[geometry]")
{
	/*
	{
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}
	*/

	{ //bad intensity
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": \"bad\", "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //neg intensity
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": -1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //test 3 bad location
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": \"bad\", \"y\": \"bad\", \"z\": \"bad\"} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //test 2 bad location
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": \"bad\", \"z\": \"bad\"} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //test 1 bad location
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": \"bad\"} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}
}

TEST_CASE("Test Validation Function For Object Sphere", "[geometry]")
{
	/*
	{
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}
	*/

	{ //1 bad center
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ " 
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": \"bad\"}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //2 bad center
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ " 
		            "\"center\": { \"x\": 0, \"y\": \"bad\", \"z\": \"bad\"}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //3 bad center
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ " 
		            "\"center\": { \"x\": \"bad\", \"y\": \"bad\", \"z\": \"bad\"}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //bad colors
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": \"bad\", \"g\": \"bad\", \"r\": \"bad\"}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //float colors
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 1.5, \"g\": 1.5, \"r\": 1.5}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //neg colors
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": -5, \"g\": -5, \"r\": -5}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //too high colors
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 300, \"g\": 300, \"r\": 300}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //bad lambert
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": \"bad\", "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //neg lambert
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": -1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //too high lambert
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 2, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //bad radius
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": \"bad\", "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //neg radius
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": -1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

}

TEST_CASE("Test Validation Function For Object Plane", "[geometry]")
{
	/*
	{
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}
	*/

	{ //good plane
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(ok);
	}

	{ //1 bad center
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": \"bad\"}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //2 bad center
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": \"bad\", \"z\": \"bad\"}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //3 bad center
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": \"bad\", \"y\": \"bad\", \"z\": \"bad\"}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{// 1 bad normal
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": \"bad\"}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{// 2 bad normal
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": \"bad\", \"z\": \"bad\"}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{// 3 bad normal
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": \"bad\", \"y\": \"bad\", \"z\": \"bad\"}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //neg color
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": -1, \"g\": -1, \"r\": -1}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //past max color
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 300, \"g\": 300, \"r\": 300}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //non int color
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 1.5, \"g\": 1.5, \"r\": 1.5}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //bad color
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": \"bad\", \"g\": \"bad\", \"r\": \"bad\"}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //bad lambert
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": \"bad\", "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //neg lambert
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": -1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}

	{ //high lambert
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 5, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}
}

TEST_CASE("Test Running Program", "[raytracer]")
{
	{
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
			Raytracer rt;
			rt.generateImage(geo);
			QImage pic = rt.getImage();
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(ok);
	}

	{ //good plane
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": 0} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 0, \"g\": 0, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
			Raytracer rt;
			rt.generateImage(geo);
			QImage pic = rt.getImage();
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(ok);
	}

	{ //good plane with light in the back and 2 threads
		std::string str =	
		"{ "
			"\"camera\": { "
		        "\"center\": { \"x\": 0, \"y\": 0, \"z\": 0}, "
		        "\"focus\": 10, "
		        "\"normal\": { \"x\": 0, \"y\": 0, \"z\": 1}, "
		        "\"resolution\": [0.01, 0.01], "
		        "\"size\": [256,256] "
		    "}, "
		    "\"lights\": [ "
		        "{ "
		            "\"intensity\": 1, "
		            "\"location\": { \"x\": 5, \"y\": -5, \"z\": -2} "
		        "} "
		    "], "
		    "\"objects\": [ "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 255, \"g\": 255, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"normal\": { \"x\": 5, \"y\": -5, \"z\": 0}, "
		            "\"type\": \"plane\" "
		        "}, "
		        "{ "
		            "\"center\": { \"x\": 0, \"y\": 0, \"z\": 5}, "
		            "\"color\": {\"b\": 128, \"g\": 128, \"r\": 255}, "
		            "\"lambert\": 1, "
		            "\"radius\": 1, "
		            "\"type\": \"sphere\" "
		        "} "
		    "] "
		"}";

		bool ok = true;
		try
		{
			Geometry geo(str);
			Raytracer rt(2);
			rt.generateImage(geo);
			QImage pic = rt.getImage();
		}
		catch(JSONParsingError&)
		{
			ok = false;
		}
		REQUIRE(ok);
	}
}