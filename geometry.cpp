#include "geometry.hpp"
#include "json_parsing_error.hpp"

#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <string>

Geometry::Geometry(std::string filetext)
{
	QByteArray bar = QByteArray::fromStdString(filetext);
	QJsonDocument env;
	QJsonParseError * pErr;
	env = QJsonDocument::fromJson(bar, pErr);
	if (pErr->error != QJsonParseError::NoError)
	{
		std::string eMessage = "Error: " + pErr->errorString().toStdString();
		throw JSONParsingError(eMessage);
	}
	//validate the datas
	validate(env);

}

Geometry::~Geometry()
{

}

void validate(QJsonDocument& env)
{
	//camera checks
	if (!isValidCoord(env.object().value("camera").value("center")) ||
		!isValidCoord(env.object().value("camera").value("normal")) ||
		!env.object().value("camera").value("focus").isDouble() ||
		!isValidSize(env.object().value("camera").value("size")) ||
		!isValidRes(env.object().value("camera").value("resolution")))
	{
		throw JSONParsingError("Error: invalid data in camera values");
	}

	//lights checks
	for (int i = 0, i < env.object().value("lights").size(); ++i)
	{
		if (!isValidIntensity(env.object().value("lights")[i].value("intensity")) ||
			!isValidCoord(env.object().value("lights")[i].value("location")) )
		{
			throw JSONParsingError("Error: invalid data in lights values");
		}
	}

	//objects checks
	for (int i = 0, i < env.object().value("objects").size(); ++i)
	{
		if (env.object().value("objects")[i].value("type").toString() == "sphere")
		{
			if (!isValidCoord(env.object().value("objects")[i].value("center")) 	||
				!isValidColor(env.object().value("objects")[i].value("color"))		||
				!isValidLambert(env.object().value("objects")[i].value("lambert"))	||
				!isValidRadius(env.object().value("objects")[i].value("radius")) 	)
			{
				throw JSONParsingError("Error: invalid data in objects sphere values");
			}
		}
		else if (env.object().value("objects")[i].value("type").toString() == "plane")
		{
			if (!isValidCoord(env.object().value("objects")[i].value("center"))		||
				!isValidColor(env.object().value("objects")[i].value("color"))		||
				!isValidLambert(env.object().value("objects")[i].value("lambert")) 	||
				!isValidCoord(env.object().value("objects")[i].value("normal"))		)
			{
				throw JSONParsingError("Error: invalid data in objects plane values");
			}
		}
		else
		{
			throw JSONParsingError("Error: invalid data in objects type");
		}
	}
}

bool isValidCoord(QJsonObject& obj)
{
	if (!obj.value("x").isDouble() ||
		!obj.value("y").isDouble() ||
		!obj.value("z").isDouble())
	{
		return false;
	}
	return true;
}

bool isValidRadius(QJsonValue& val)
{
	if (val.isDouble() && val.toDouble() >= 0)
	{
		return true;
	}
	return false;
}

bool isValidIntensity(QJsonValue& val)
{
	if (val.isDouble() && val.toDouble() >= 0)
	{
		return true;
	}
	return false;
}

bool isValidLambert(QJsonValue& val)
{
	if (val.isDouble() && 
		val.toDouble() >= 0 &&
		val.toDouble() <= 1)
	{
		return true;
	}
	return false;
}

bool isValidColor(QJsonObject& obj)
{
	bool good = true;
	if (!obj.value("r").isDouble() || 
		!(obj.value("r").toDouble() == val.toInt()) ||
		!(obj.value("r").toDouble() >= 0) ||
		!(obj.value("r").toDouble() <= 255))
	{
		good = false;
	}
	if (!obj.value("g").isDouble() || 
		!(obj.value("g").toDouble() == val.toInt()) ||
		!(obj.value("g").toDouble() >= 0) ||
		!(obj.value("g").toDouble() <= 255))
	{
		good = false;
	}
	if (!obj.value("b").isDouble() || 
		!(obj.value("b").toDouble() == val.toInt()) ||
		!(obj.value("b").toDouble() >= 0) ||
		!(obj.value("b").toDouble() <= 255))
	{
		good = false;
	}
	return good;
}

bool isValidSize(QJsonArray& arr)
{
	bool good = true;
	if (!arr[0].isDouble() ||
		!(arr[0].toDouble() == val.toInt()) ||
		!(arr[0].toDouble() > 0))
	{
		good = false;
	}
	if (!arr[1].isDouble() ||
		!(arr[1].toDouble() == val.toInt()) ||
		!(arr[1].toDouble() > 0))
	{
		good = false;
	}
	return good;
}

bool isValidRes(QJsonArray& arr)
{
	bool good = true;
	if (!arr[0].isDouble() || !(arr[0].toDouble() > 0))
	{
		good = false;
	}
	if (!arr[1].isDouble() || !(arr[1].toDouble() > 0))
	{
		good = false;
	}
	return good;
}

//extra validators if we need to validate every element of the file
/*
	//a bunch of ifs that are failure conditions
	if (!env.isObject() ||
		!env.object().contains("objects") ||
		!env.object().contains("lights") ||
		!env.object().contains("camera"))
	{
		throw JSONParsingError("Error: missing critical elements of valid file");
	}
	//tests camera contents
	if (!env.object().contains("objects") ||
		!env.object().contains("lights") ||
		!env.object().contains("camera") ||
		)
	{
		throw JSONParsingError("Error: missing critical elements of valid file");
	}
*/