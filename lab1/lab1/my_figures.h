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
	struct EquationOfFigure//ax + by + c = 0
	{
		double coefficientAtY;
		double coefficientAtX;
		double constantC;
		EquationOfFigure();
		EquationOfFigure(double coefficientAtY, double coefficientAtX, double constantC);
	};
	class TheCircle
	{
	private:
		Point centre;
		Point second;
		double radius;
	public:
	};
	class TheLine
	{
	private:
		Point first;
		Point second;
	public:
		TheLine();
		TheLine(Point first, Point second);
		double distanceToPoint(Point point);
	};
	std::vector<Point> pointsOfIntersection(Figure figure1, Figure figure2);
}
namespace fop
{
	//Figure
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
	//EquationOfFigure
	EquationOfFigure::EquationOfFigure(): coefficientAtY(0), coefficientAtX(0), constantC(0){}
	EquationOfFigure::EquationOfFigure(double coefficientAtY, double coefficientAtX, double constantC)
		: coefficientAtY(coefficientAtY), coefficientAtX(coefficientAtX), constantC(constantC) {}
	//TheLine
	TheLine::TheLine(): first(Point()), second(Point()) {}
	TheLine::TheLine(Point first, Point second) : first(first), second(second) {}
	double TheLine::distanceToPoint(Point point)   //y - y1    x - x1
	{                                              //_______ = _______ or ax + by + c = 0
		double coefficientAtX = second.y - first.y;//y2 - y1   x2 - x1
		double coefficientAtY = first.x - second.x;
		double constantC = coefficientAtX * first.x + first.y * coefficientAtY;
		return abs(coefficientAtX * point.x + coefficientAtY * point.y - constantC) 
				/ sqrt(coefficientAtX * coefficientAtX + coefficientAtY * coefficientAtY);
	}
	//functions
	std::vector<Point> pointsOfIntersection(Figure figure1, Figure figure2)
	{
		return { {} };
	}
}