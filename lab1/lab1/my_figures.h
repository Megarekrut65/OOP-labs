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
	struct Equation//a*x + b * y  = ñ
	{
	private:
		bool isDependent(double value1, double value2);
	public:
		double a;
		double b;
		double c;
		Equation();
		Equation(Figure figure);
		bool checkDependency(Equation equation);
	};
	//bool operator == (Equation equation1, Equation equation2);
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
	Figure::Figure(FiguresType type, Point first, Point second)
	{
		this->type = type;
		if (first == second)
		{
			std::cout << "Error: This figure is point " << first << std::endl;
			first.x++;
			this->first = first;
		}
		else this->first = first;
		this->second = second;
	}
	Figure::Figure(Point maxValue)
	{
		int number = rand() % 2;
		if (number == 0) type = FiguresType::Circle;
		else type = FiguresType::Line;
		first = Point(maxValue);
		second = Point(maxValue);	
		if (first == second) first.x++;
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
		if (infinity || numberOfPoints == 0)
		{
			std::cout << "Figures coincide or do not intersect!" << std::endl;
			return;
		}
		std::cout << "Number of points of intersection: " << numberOfPoints << std::endl << "Points: " ;
		for (std::size_t i = 0; i < numberOfPoints; i++) std::cout << points[i] << ", ";
	}
	//Equation
	//private
	bool Equation::isDependent(double value1, double value2)
	{
		if (value1 == 0 && value2 == 0) return true;
		if (value1 == 0 || value2 == 0) return false;
		double fraction = value1 / value2;
		if (round(fraction) == fraction) return true;

		return false;
	}
	//public
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
			c = a * figure.first.x + figure.first.y * b;
		}
		std::cout << a << "x + " << b << "y + " << c << " = 0\n";
	}
	bool Equation::checkDependency(Equation equation)
	{
		if (isDependent(a, equation.a)&& isDependent(b, equation.b)&& isDependent(c, equation.c)) return true;

		return false;
	}
	/*bool operator == (Equation equation1, Equation equation2)
	{
		return ((equation1.a == doctest::Approx(equation2.a)) 
			&& (equation1.b == doctest::Approx(equation2.b))
			&& (equation1.c == doctest::Approx(equation2.c)));
	}*/
	//functions
	double distanceFromLineToPoint(Figure line, Point point)
	{
		if (line.type != FiguresType::Line) return -1;
		Equation equation{ line };
		return abs(equation.a * point.x + equation.b * point.y - equation.c)
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
		double determinant = equation1.a * equation2.b - equation2.a * equation1.b;
		if (determinant == 0) return Intersection();
		double determinant1 = equation1.c * equation2.b - equation2.c * equation1.b;
		double determinant2 = equation1.a * equation2.c - equation2.a * equation1.c;
		double x = determinant1 / determinant;
		double y = determinant2 / determinant;
		return Intersection(false, 1, { {x, y} });
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