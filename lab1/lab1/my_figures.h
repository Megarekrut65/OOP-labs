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
	struct Intersection
	{
		bool infinity;
		std::size_t numberOfPoints;
		std::vector<Point> points;
		Intersection();
		Intersection(bool infinity, std::size_t numberOfPoints, const std::vector<Point>& points);
		void print();
	};
	struct Equation//a*x + b * y + c = 0
	{
		double a;
		double b;
		double c;
		Equation();
		Equation(Figure figure);
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
	double distanceFromLineToPoint(Figure line, Point point);
	Intersection pointsOfIntersection(Figure figure1, Figure figure2);
	Intersection intersectionOfCircleAndLine(Figure circle, Figure line);
	Intersection intersectionOfTwoLine(Figure line1, Figure line2);
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
	//Intersection
	Intersection::Intersection(): infinity(false), numberOfPoints(0), points({}) {}
	Intersection::Intersection(bool infinity, std::size_t numberOfPoints, const std::vector<Point>& points)
		: infinity(infinity), numberOfPoints(numberOfPoints), points(points) {}
	void Intersection::print()
	{
		if (infinity)
		{
			std::cout << "Figures have an infinite number of points of intersection!" << std::endl;
			return;
		}
		std::cout << "Number of points of intersection: " << numberOfPoints << std::endl << "Points: " ;
		for (std::size_t i = 0; i < numberOfPoints; i++) std::cout << points[i] << ", ";
	}
	//Equation
	Equation::Equation():a(0), b(0), c(0) {}
	Equation::Equation(Figure figure)
	{
		a = 0;
		b = 0;
		c = 0;
		if (figure.type == FiguresType::Line)
		{
			a = figure.second.y - figure.first.y;
			b = figure.first.x - figure.second.x;
			c = -1 * (a * figure.first.x + figure.first.y * b);
		}
	}
	//functions
	double distanceFromLineToPoint(Figure line, Point point)
	{
		if (line.type != FiguresType::Line) return -1;
		Equation equation{ line };
		return abs(equation.a * point.x + equation.b * point.y + equation.c)
			/ sqrt(equation.a * equation.a + equation.b * equation.b);
	}
	Intersection intersectionOfCircleAndLine(Figure circle, Figure line)
	{
		if (circle.type == FiguresType::Line && line.type == FiguresType::Circle)
			return intersectionOfCircleAndLine(line, circle);
		if (circle.type != FiguresType::Circle || line.type != FiguresType::Line) return Intersection();
		double distance = distanceFromLineToPoint(line, circle.first);
		double radius = distanceBetweenPoints(circle.first, circle.second);
		if (distance > radius) return Intersection();
		double distanceSquare = pow(distance, 2), radiusSquare = pow(radius, 2);
		std::vector<Point> points;
		if (distanceSquare == radiusSquare)
		{
			points = { {distance + circle.first.x, circle.first.y} };
		}
		else
		{
			points = { {distance + circle.first.x, sqrt(radiusSquare - distanceSquare) + circle.first.y},
						{distance + circle.first.x, -1 * sqrt(radiusSquare - distanceSquare) + circle.first.y} };
		}
		return Intersection(false, points.size(), points);
	}
	Intersection intersectionOfTwoLine(Figure line1, Figure line2)
	{
		if (line1.type != FiguresType::Line || line2.type != FiguresType::Line) return Intersection();
		Equation equation1{ line1 }, equation2{ line2 };
		double y = 0, x1 = 0, x2 = 0;
		y = (equation2.a * (equation1.c / equation1.a) - equation2.c) 
			/ (-1 * equation2.a * equation1.b/equation1.a + equation2.b);
		x1 = -1 * (equation1.b * y + equation1.c)/equation1.a;
		x2 = -1 * (equation2.b * y + equation2.c) / equation2.a;
		if (x1 != x2) std::cout << "\nx1 != x2!\n";

		return Intersection(false, 1, { {x1, y} });
	}
	Intersection pointsOfIntersection(Figure figure1, Figure figure2)
	{
		switch (figure1.type)
		{
		case FiguresType::Circle:
		{

		}
			break;
		case FiguresType::Line:
		{

		}
			break;
		}
		return {};
	}
}