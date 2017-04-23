#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <QJsonDocument>
#include <string>

class Geometry
{
public:
	Geometry(std::string filetext);

	~Geometry();

	//put publicly accessable environment here

private:
}

void validate(QJsonDocument& env);
bool isValidCoord(QJsonObject& obj);
bool isValidCoord(QJsonObject& obj);
bool isValidRadius(QJsonValue& val);
bool isValidIntensity(QJsonValue& val);
bool isValidLambert(QJsonValue& val);
bool isValidColor(QJsonObject& obj);
bool isValidSize(QJsonArray& arr);
bool isValidRes(QJsonArray& arr);

#endif