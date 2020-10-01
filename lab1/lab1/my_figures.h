#pragma once
#include "my_point.h"

using namespace tdp;

namespace fop//figures on the plane
{
	enum class FiguresType
	{
		Circle,
		Line
	};
	struct Figure
	{
		FiguresType type;
		Point first;//for circle it is centre point
		Point second;
		Figure();
		Figure(FiguresType type, Point first, Point second);
		Figure(Point maxValue);//creates random figure
	};
	struct TheCircle
	{
		Point centre;
		Point second;
		double radius;
	};
	struct TheLine
	{
		Point first;
		Point second;
		Point directingVector;
	};
	bool operator < (Figure figure1, Figure figure2);
	bool operator > (Figure figure1, Figure figure2);
	bool operator <= (Figure figure1, Figure figure2);
	bool operator >= (Figure figure1, Figure figure2);
	bool operator == (Figure figure1, Figure figure2);
	bool operator != (Figure figure1, Figure figure2);
	Figure operator + (Figure figure1, Figure figure2);
	Figure operator - (Figure figure1, Figure figure2);
	std::string toString(FiguresType value);
	std::string toString(const Figure& value);
	Figure randomValue(const Figure& maxValue);
	std::vector<Point> pointsOfIntersection(Figure figure1, Figure figure2);
}
namespace fop
{
	Figure::Figure(): type(FiguresType::Circle), first(Point()), second(Point()){}
	Figure::Figure(FiguresType type, Point first, Point second) : type(type), first(first), second(second) {}
	Figure::Figure(Point maxValue)
	{
		int number = rand() % 2;
		if (number == 0) type = FiguresType::Circle;
		else type = FiguresType::Line;
		first = Point(maxValue);
		second = Point(maxValue);	
	}
	bool operator < (Figure figure1, Figure figure2)
	{
		return ((figure1.second - figure1.first) < (figure2.second - figure2.first));
	}
	bool operator > (Figure figure1, Figure figure2)
	{
		return ((figure1.second - figure1.first) > (figure2.second - figure2.first));
	}
	bool operator <= (Figure figure1, Figure figure2)
	{
		return ((figure1.second - figure1.first) <= (figure2.second - figure2.first));
	}
	bool operator >= (Figure figure1, Figure figure2)
	{
		return ((figure1.second - figure1.first) >= (figure2.second - figure2.first));
	}
	bool operator == (Figure figure1, Figure figure2)
	{
		return ((figure1.second - figure1.first) == (figure2.second - figure2.first));
	}
	bool operator != (Figure figure1, Figure figure2)
	{
		return ((figure1.second - figure1.first) != (figure2.second - figure2.first));
	}
	Figure operator + (Figure figure1, Figure figure2)
	{
		return Figure(figure1 > figure2 ? figure1.type : figure2.type,figure1.first + figure2.first , figure1.second + figure2.second);
	}
	Figure operator - (Figure figure1, Figure figure2)
	{
		return Figure(figure1 > figure2 ? figure1.type : figure2.type, figure1.first - figure2.first, figure1.second - figure2.second);
	}
	std::string toString(FiguresType value)
	{
		if (value == FiguresType::Circle) return "Circle";
		return "Line";
	}
	std::string toString(const Figure& value)
	{
		std::string result = "Figure: {type: " + toString(value.type)
			+ ", first point: " + toString(value.first) 
			+ ", second point: " + toString(value.second) + " }";

		return result;
	}
	Figure randomValue(const Figure& maxValue)
	{
		return Figure(maxValue);
	}
	std::vector<Point> pointsOfIntersection(Figure figure1, Figure figure2)
	{

	}
}