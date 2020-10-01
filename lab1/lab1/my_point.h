#pragma once
#include "my_override_functions_and_operators.h"

namespace tdp//three-dimensional points
{
	struct Point
	{
		double x;
		double y;
		double z;
		Point();
		Point(double x, double y, double z);
		Point(double maxValue);//creates random point
	};
	bool operator < (Point first, Point second);
	bool operator > (Point first, Point second);
	bool operator <= (Point first, Point second);
	bool operator >= (Point first, Point second);
	bool operator == (Point first, Point second);
	bool operator != (Point first, Point second);
	Point operator + (Point first, Point second);
	Point operator - (Point first, Point second);
	Point operator * (Point first, Point second);
	Point operator / (Point first, Point second);
	std::string toString(Point value);
}
namespace tdp
{
	Point::Point()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Point::Point(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Point::Point(double maxValue)
	{
		x = ofo::randomValue(maxValue);
		y = ofo::randomValue(maxValue);
		z = ofo::randomValue(maxValue);
	}
	bool operator < (Point first, Point second)
	{
		if (first.x < second.x) return true;
		else if (first.x > second.x) return false;
		if (first.y < second.y) return true;
		else if (first.y > second.y) return false;
		if (first.z < second.z) return true;
		else if (first.z > second.z) return false;
		return false;
	}
	bool operator > (Point first, Point second)
	{
		if (first.x > second.x) return true;
		else if (first.x < second.x) return false;
		if (first.y > second.y) return true;
		else if (first.y < second.y) return false;
		if (first.z > second.z) return true;
		else if (first.z < second.z) return false;
		return false;
	}
	bool operator <= (Point first, Point second)
	{
		if (first.x < second.x) return true;
		else if (first.x > second.x) return false;
		if (first.y < second.y) return true;
		else if (first.y > second.y) return false;
		if (first.z < second.z) return true;
		else if (first.z > second.z) return false;
		return true;
	}
	bool operator >= (Point first, Point second)
	{
		if (first.x > second.x) return true;
		else if (first.x < second.x) return false;
		if (first.y > second.y) return true;
		else if (first.y < second.y) return false;
		if (first.z > second.z) return true;
		else if (first.z < second.z) return false;
		return true;
	}
	bool operator == (Point first, Point second)
	{
		return (first.x == second.x && first.y == second.y && first.z == second.z);
	}
	bool operator != (Point first, Point second)
	{
		return (first.x != second.x || first.y != second.y || first.z != second.z);
	}
	Point operator + (Point first, Point second)
	{
		return Point(first.x + second.x, first.y + second.y, first.z + second.z);
	}
	Point operator - (Point first, Point second)
	{
		return Point(first.x - second.x, first.y - second.y, first.z - second.z);
	}
	Point operator * (Point first, Point second)
	{
		return Point(first.x * second.x, first.y * second.y, first.z * second.z);
	}
	Point operator / (Point first, Point second)
	{
		return Point(first.x / second.x, first.y / second.y, first.z / second.z);
	}
	std::string toString(Point value)
	{
		return "( " + std::to_string(value.x) + ", " + std::to_string(value.y) + ", " + std::to_string(value.z) + " )";
	}
}