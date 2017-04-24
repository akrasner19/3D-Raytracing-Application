#include "geometry.hpp"
#include "json_parsing_error.hpp"

#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QString>
#include <string>

Geometry::Geometry(std::string filetext)
{
	QString qstr = QString::fromStdString(filetext);
	QJsonParseError pErr;
	QJsonDocument env = QJsonDocument::fromJson(qstr.toUtf8(), &pErr);
	if (pErr.error != QJsonParseError::NoError)
	{
		std::string eMessage = "Error: " + pErr.errorString().toStdString();
		throw JSONParsingError(eMessage);
	}
	//validate the datas
	validate(env);
	//fill class fields
	//camera
	QJsonObject tempcam = env.object().value("camera").toObject();
	this->camera.center.x = tempcam.value("center").toObject().value("x").toDouble();
	this->camera.center.y = tempcam.value("center").toObject().value("y").toDouble();
	this->camera.center.z = tempcam.value("center").toObject().value("z").toDouble();

	this->camera.normal.x = tempcam.value("normal").toObject().value("x").toDouble();
	this->camera.normal.y = tempcam.value("normal").toObject().value("y").toDouble();
	this->camera.normal.z = tempcam.value("normal").toObject().value("z").toDouble();

	this->camera.focus = tempcam.value("focus").toDouble();
	this->camera.sizeX = tempcam.value("size").toArray().at(0).toDouble();
	this->camera.sizeY = tempcam.value("size").toArray().at(1).toDouble();
	this->camera.resX = tempcam.value("resolution").toArray().at(0).toDouble();
	this->camera.resY = tempcam.value("resolution").toArray().at(1).toDouble();

	QJsonArray temparr = env.object().value("lights").toArray();
	for (int i = 0; i < temparr.size(); ++i)
	{
		Light newLight;
		QJsonObject temploc = temparr.at(i).toObject().value("location").toObject();
		newLight.location.x = temploc.value("x").toDouble();
		newLight.location.y = temploc.value("y").toDouble();
		newLight.location.z = temploc.value("z").toDouble();

		newLight.intensity = temparr.at(i).toObject().value("intensity").toDouble();

		this->lights.push_back(newLight);
	}

	temparr = env.object().value("objects").toArray();
	for (int i = 0; i < temparr.size(); ++i)
	{
		Shape newShape;
		QJsonObject temppoint = temparr.at(i).toObject().value("center").toObject();
		newShape.center.x = temppoint.value("x").toDouble();
		newShape.center.y = temppoint.value("y").toDouble();
		newShape.center.z = temppoint.value("z").toDouble();

		temppoint = temparr.at(i).toObject().value("color").toObject();
		newShape.r = temppoint.value("r").toInt();
		newShape.g = temppoint.value("g").toInt();
		newShape.b = temppoint.value("b").toInt();

		newShape.lambert = temparr.at(i).toObject().value("lambert").toDouble();

		if (temparr.at(i).toObject().value("type").toString() == "sphere")
		{
			newShape.type = sphere;
			newShape.radius = temparr.at(i).toObject().value("radius").toDouble();
		}
		else if (temparr.at(i).toObject().value("type").toString() == "plane")
		{
			newShape.type = plane;

			temppoint = temparr.at(i).toObject().value("normal").toObject();
			newShape.normal.x = temppoint.value("x").toDouble();
			newShape.normal.y = temppoint.value("y").toDouble();
			newShape.normal.z = temppoint.value("z").toDouble();
		}
	}
}

Geometry::~Geometry()
{

}

void validate(QJsonDocument& env)
{
	//camera checks
	if (!isValidCoord(env.object().value("camera").toObject().value("center")) ||
		!isValidCoord(env.object().value("camera").toObject().value("normal")) ||
		!env.object().value("camera").toObject().value("focus").isDouble() ||
		!isValidSize(env.object().value("camera").toObject().value("size")) ||
		!isValidRes(env.object().value("camera").toObject().value("resolution")) )
	{
		throw JSONParsingError("Error: invalid data in camera values");
	}
	
	//lights checks
	for (int i = 0; i < env.object().value("lights").toArray().size(); ++i)
	{
		if (!isValidIntensity(env.object().value("lights").toArray().at(i).toObject().value("intensity")) ||
			!isValidCoord(env.object().value("lights").toArray().at(i).toObject().value("location")) )
		{
			throw JSONParsingError("Error: invalid data in lights values");
		}
	}

	//objects checks
	for (int i = 0; i < env.object().value("objects").toArray().size(); ++i)
	{
		if (env.object().value("objects").toArray().at(i).toObject().value("type").toString() == "sphere")
		{
			if (!isValidCoord(env.object().value("objects").toArray().at(i).toObject().value("center")) 	||
				!isValidColor(env.object().value("objects").toArray().at(i).toObject().value("color"))		||
				!isValidLambert(env.object().value("objects").toArray().at(i).toObject().value("lambert"))	||
				!isValidRadius(env.object().value("objects").toArray().at(i).toObject().value("radius")) 	)
			{
				throw JSONParsingError("Error: invalid data in objects sphere values");
			}
		}
		else if (env.object().value("objects").toArray().at(i).toObject().value("type").toString() == "plane")
		{
			if (!isValidCoord(env.object().value("objects").toArray().at(i).toObject().value("center"))		||
				!isValidColor(env.object().value("objects").toArray().at(i).toObject().value("color"))		||
				!isValidLambert(env.object().value("objects").toArray().at(i).toObject().value("lambert")) 	||
				!isValidCoord(env.object().value("objects").toArray().at(i).toObject().value("normal"))		)
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

bool isValidCoord(QJsonValue val)
{
	QJsonObject obj = val.toObject();
	if (!obj.value("x").isDouble() ||
		!obj.value("y").isDouble() ||
		!obj.value("z").isDouble())
	{
		return false;
	}
	return true;
}

bool isValidRadius(QJsonValue val)
{
	if (val.isDouble() && val.toDouble() >= 0)
	{
		return true;
	}
	return false;
}

bool isValidIntensity(QJsonValue val)
{
	if (val.isDouble() && val.toDouble() >= 0)
	{
		return true;
	}
	return false;
}

bool isValidLambert(QJsonValue val)
{
	if (val.isDouble() && 
		val.toDouble() >= 0 &&
		val.toDouble() <= 1)
	{
		return true;
	}
	return false;
}

bool isValidColor(QJsonValue val)
{
	QJsonObject obj = val.toObject();
	bool good = true;
	if (!obj.value("r").isDouble() || 
		!(obj.value("r").toDouble() == obj.value("r").toInt()) ||
		!(obj.value("r").toDouble() >= 0) ||
		!(obj.value("r").toDouble() <= 255))
	{
		good = false;
	}
	if (!obj.value("g").isDouble() || 
		!(obj.value("g").toDouble() == obj.value("g").toInt()) ||
		!(obj.value("g").toDouble() >= 0) ||
		!(obj.value("g").toDouble() <= 255))
	{
		good = false;
	}
	if (!obj.value("b").isDouble() || 
		!(obj.value("b").toDouble() == obj.value("b").toInt()) ||
		!(obj.value("b").toDouble() >= 0) ||
		!(obj.value("b").toDouble() <= 255))
	{
		good = false;
	}
	return good;
}

bool isValidSize(QJsonValue val)
{
	QJsonArray arr = val.toArray();
	bool good = true;
	if (!arr.at(0).isDouble() ||
		!(arr.at(0).toDouble() == arr.at(0).toInt()) ||
		!(arr.at(0).toDouble() > 0))
	{
		good = false;
	}
	if (!arr.at(1).isDouble() ||
		!(arr.at(1).toDouble() == arr.at(1).toInt()) ||
		!(arr.at(1).toDouble() > 0))
	{
		good = false;
	}
	return good;
}

bool isValidRes(QJsonValue val)
{
	QJsonArray arr = val.toArray();
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