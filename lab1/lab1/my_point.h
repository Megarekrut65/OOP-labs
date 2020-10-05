#pragma once
#include "my_override_functions_and_operators.h"

namespace tdp//two-dimensional points
{
	struct Point
	{
		double x;
		double y;
		Point();
		Point(double x, double y);
		Point(double maxValue);//creates random point
		double vectorModule();//if point(x, y) is vector(x, y), don't std::vector, then |vector| = vectorModule()
	};
	bool operator < (Point first, Point second);
	bool operator > (Point first, Point second);
	bool operator <= (Point first, Point second);
	bool operator >= (Point first, Point second);
	bool operator == (Point first, Point second);
	bool operator != (Point first, Point second);
	Point operator + (Point first, Point second);
	Point operator - (Point first, Point second);
	Point operator * (double value, Point point);
	std::ostream& operator << (std::ostream& out, Point point);
	std::string toString(Point value);
	double distanceBetweenPoints(Point first, Point second);
}
namespace tdp
{
	Point::Point() : x(0), y(0) {}
	Point::Point(double x, double y): x(x), y(y) {}
	Point::Point(double maxValue) : x(ofo::randomValue(maxValue)), y(ofo::randomValue(maxValue)) {}
	double Point::vectorModule()
	{
		return sqrt(x * x + y * y);
	}
	bool operator < (Point first, Point second)
	{
		if (first.x < second.x) return true;
		else if (first.x > second.x) return false;
		if (first.y < second.y) return true;
		else if (first.y > second.y) return false;

		return false;
	}
	bool operator > (Point first, Point second)
	{
		if (first.x > second.x) return true;
		else if (first.x < second.x) return false;
		if (first.y > second.y) return true;
		else if (first.y < second.y) return false;

		return false;
	}
	bool operator <= (Point first, Point second)
	{
		if (first.x < second.x) return true;
		else if (first.x > second.x) return false;
		if (first.y < second.y) return true;
		else if (first.y > second.y) return false;

		return true;
	}
	bool operator >= (Point first, Point second)
	{
		if (first.x > second.x) return true;
		else if (first.x < second.x) return false;
		if (first.y > second.y) return true;
		else if (first.y < second.y) return false;

		return true;
	}
	bool operator == (Point first, Point second)
	{
		return (first.x == second.x && first.y == second.y);
	}
	bool operator != (Point first, Point second)
	{
		return (first.x != second.x || first.y != second.y);
	}
	Point operator + (Point first, Point second)
	{
		return Point(first.x + second.x, first.y + second.y);
	}
	Point operator - (Point first, Point second)
	{
		return Point(first.x - second.x, first.y - second.y);
	}
	Point operator * (double value, Point point)
	{
		return Point(point.x * value, point.y * value);
	}
	std::ostream& operator << (std::ostream& out, Point point)
	{
		return out << "(" << point.x << ", " << point.y << ")";
	}
	std::string toString(Point value)
	{
		return "( " + std::to_string(value.x) + ", " + std::to_string(value.y) + " )";
	}
	double distanceBetweenPoints(Point first, Point second)
	{		
		return sqrt(pow(second.x - first.x, 2) + pow(second.y - first.y, 2));
	}
}