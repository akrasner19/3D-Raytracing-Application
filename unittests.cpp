#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
// IMPORTANT NOTE:
// These are just a few examples from my solution and **should be removed**.
// Depending on your code design your class and functions names would differ

#include "geometry.hpp"
#include "json_parsing_error.hpp"
#include <string>

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
		try{
			Geometry geo(str);
		}
		catch(JSONParsingError& error)
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
		catch(JSONParsingError& error)
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
		catch(JSONParsingError& error)
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
		catch(JSONParsingError& error)
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
		catch(JSONParsingError& error)
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
		catch(JSONParsingError& error)
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
		catch(JSONParsingError& error)
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
		catch(JSONParsingError& error)
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
		catch(JSONParsingError& error)
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
		catch(JSONParsingError& error)
		{
			ok = false;
		}
		REQUIRE(!ok);
	}
}