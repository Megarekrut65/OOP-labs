#pragma once
#include "my_point.h"

using namespace tdp;

namespace fop//figures on the plane
{
	enum class FiguresType
	{
		CIRCLE,
		LINE,
		POINT
	};
	class Figure
	{
	private:
		Point* puncturedPoint;
		double findDistanceFromLineToPoint(Figure line, Point point);	
		std::vector<Point> intersectionOfCircleAndLine(Figure circle, Figure line);		
		std::vector<Point> intersectionOfTwoLines(Figure line1, Figure line2);
		std::vector<Point> intersectionOfTwoCirclesByCoordinates(double x1, double x2, double y1, double y2, double radius1, double radius2);
		std::vector<Point> intersectionOfTwoCircles(Figure circle1, Figure circle2);
		Figure createPerpendicularLine(Figure line, Point point);
		Point symmetricalMappingOfPointByLine(Figure line, Point point);
		Point inversionTransformationOfPointByCircle(Figure circle, Point point);
	public:
		FiguresType type;
		Point first;//for circle it is centre point
		Point second;
		Figure();
		Figure(FiguresType type, Point first, Point second);
		Figure(Point maxValue);//creates random figure
		Figure(const Figure& figure);
		~Figure();
		bool havePoint(Point point);
		std::vector<Point> findPointsOfIntersection(Figure figure);
		Figure inversionTransformationByCircle(Figure circle);
		Figure symmetricalMappingByLine(Figure line);
		friend std::string toTheString(const Figure& value);
	};	
	struct Equation//a*x + b * y  = ñ
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
	std::string toTheString(FiguresType value);
	Figure randomValue(const Figure& maxValue);
	std::vector<Point> solveSystemOfLineEquations(Equation equation1, Equation equation2);
	std::vector<double> solveQuadraticEquation(double coefficientP, double coefficientQ, double coefficientD);
}
namespace fop
{
	//Figure
	//private
	double Figure::findDistanceFromLineToPoint(Figure line, Point point)
	{
		if (line.type != FiguresType::LINE) return -1;
		Equation equation{ line };
		return abs(equation.a * point.x + equation.b * point.y - equation.c)
			/ sqrt(equation.a * equation.a + equation.b * equation.b);
	}
	/*Intersection Figure::intersectionOfCircleAndLine(Figure circle, Figure line)
	{
		if (circle.type == FiguresType::LINE && line.type == FiguresType::CIRCLE)
			return intersectionOfCircleAndLine(line, circle);
		if (circle.type != FiguresType::CIRCLE || line.type != FiguresType::LINE) return Intersection();
		double distance = findDistanceFromLineToPoint(line, circle.first);
		double radius = distanceBetweenPoints(circle.first, circle.second);
		if (distance > radius) return Intersection();
		double distanceSquare = pow(distance, 2), radiusSquare = pow(radius, 2);
		std::vector<Point> points;
		if (distanceSquare == doctest::Approx(radiusSquare))
		{
			points = { {distance + circle.first.x, circle.first.y} };
		}
		else
		{
			points = { {distance + circle.first.x, sqrt(radiusSquare - distanceSquare) + circle.first.y},
						{distance + circle.first.x, -1 * sqrt(radiusSquare - distanceSquare) + circle.first.y} };
		}
		return Intersection(points);
	}*/
	std::vector<Point> Figure::intersectionOfCircleAndLine(Figure circle, Figure line)
	{
		if (circle.type == FiguresType::LINE && line.type == FiguresType::CIRCLE)
			return intersectionOfCircleAndLine(line, circle);
		if (circle.type != FiguresType::CIRCLE || line.type != FiguresType::LINE)
			return {};
		double distance = findDistanceFromLineToPoint(line, circle.first);
		double radius = distanceBetweenPoints(circle.first, circle.second);
		if (distance > radius) return {};
		Equation equation1{ line };
		//Py^2 + Qy + D = 0
		double coefficientP = 0, coefficientQ = 0, coefficientD = 0;
		if (equation1.a == 0)
		{
			coefficientP = 1;
			coefficientD = pow(circle.first.x, 2) + pow(equation1.c / equation1.b - circle.first.y, 2) - pow(radius, 2);
			coefficientQ = -2 * circle.first.x;
		}
		else
		{
			coefficientP = pow(equation1.b / equation1.a, 2) + 1;
			coefficientD = pow((equation1.c - equation1.a * circle.first.x) / equation1.a, 2)
				+ pow(circle.first.y,2) - pow(radius, 2);
			coefficientQ = -2 * equation1.b * (equation1.c - equation1.a * circle.first.x) / pow(equation1.a, 2) - 2 * circle.first.y;
		}
		std::vector<double> y = solveQuadraticEquation(coefficientP, coefficientQ, coefficientD);
		switch (y.size())
		{
		case 0: return {};
			  break;
		case 1: if(equation1.a != 0) return  { { equation1.c / equation1.a - (equation1.b / equation1.a) * y[0], y[0]} };
			    else return  { { y[0], equation1.c / equation1.b} };
			  break;
		case 2: if (equation1.a != 0) return { {equation1.c / equation1.a - (equation1.b / equation1.a) * y[0], y[0]}
					 ,{ equation1.c / equation1.a - (equation1.b / equation1.a) * y[1], y[1]} };
			    else return { { y[0], equation1.c / equation1.b}
					 ,{ y[1], equation1.c / equation1.b } };
			  break;
		}
		return {};
	}
	std::vector<Point> Figure::intersectionOfTwoLines(Figure line1, Figure line2)
	{
		if (line1.type != FiguresType::LINE || line2.type != FiguresType::LINE) return {};
		Equation equation1{ line1 }, equation2{ line2 };
		return solveSystemOfLineEquations(equation1, equation2);
	}
	std::vector<Point> Figure::intersectionOfTwoCirclesByCoordinates(double x1, double x2, double y1, double y2, double radius1, double radius2)
	{
		//x = B*y + C
		double coefficientB = -1 * (y2 - y1) / (x2 - x1);
		double coefficientC = (pow(radius1, 2) - pow(radius2, 2) - pow(x1, 2)
			+ pow(x2, 2) - pow(y1, 2) + pow(y2, 2))
			/ (2 * (x2 - x1));
		//P*y^2 + Q*y + D = 0
		double coefficientP = pow(coefficientB, 2) + 1;
		double coefficientQ = 2 * (coefficientB * (coefficientC - x1) - y1);
		double coefficientD = pow(coefficientC - x1, 2) + pow(y1, 2) - pow(radius1, 2);
		std::vector<double> y = solveQuadraticEquation(coefficientP, coefficientQ, coefficientD);
		switch (y.size())
		{
		case 0: return {};
			  break;
		case 1: return { { coefficientB * y[0] + coefficientC, y[0]} };
			  break;
		case 2: return { {coefficientB * y[0] + coefficientC, y[0]}
					 ,{ coefficientB * y[1] + coefficientC, y[1]} };
			  break;
		}

		return {};
	}
	std::vector<Point> Figure::intersectionOfTwoCircles(Figure circle1, Figure circle2)
	{
		if (circle1.type != FiguresType::CIRCLE
			|| circle2.type != FiguresType::CIRCLE) return {};
		double radius1 = distanceBetweenPoints(circle1.first, circle1.second);
		double radius2 = distanceBetweenPoints(circle2.first, circle2.second);
		// (x - x1)^2 + (y - y1)^2 = radius1^2
		// (x - x2)^2 + (y - y2)^2 = radius2^2
		double x1 = circle1.first.x, y1 = circle1.first.y
			, x2 = circle2.first.x, y2 = circle2.first.y;
		if (x1 != doctest::Approx(x2))
		{
			std::vector<Point> points = intersectionOfTwoCirclesByCoordinates(x1, x2, y1, y2, radius1, radius2);
			return points;
		}
		else if (y1 != doctest::Approx(y2))
		{
			std::vector<Point> points = intersectionOfTwoCirclesByCoordinates(y1, y2, x1, x2, radius1, radius2);
			for (std::size_t i = 0; i < points.size(); i++)
			{
				double temp = points[i].x;
				points[i].x = points[i].y;
				points[i].y = temp;
			}
			return points;
		}
		return {};
	}
	Figure Figure::createPerpendicularLine(Figure line, Point point)
	{
		if (line.type != FiguresType::LINE) return Figure();
		Equation equation1{ line }, equation2;
		equation2.a = line.second.x - line.first.x;
		equation2.b = line.second.y - line.first.y;
		equation2.c = point.x * equation2.a + point.y * equation2.b;
		std::vector<Point> points = solveSystemOfLineEquations(equation1, equation2);
		if (points.size() != 1) return Figure();
		return Figure(FiguresType::LINE, point, points[0]);
	}
	Point Figure::symmetricalMappingOfPointByLine(Figure line, Point point)
	{
		if (line.type != FiguresType::LINE) return point;
		Figure perpendicularLine = createPerpendicularLine(line, point);//perpendicularLine.second ª line

		return (2 * perpendicularLine.second - point);
	}
	Point Figure::inversionTransformationOfPointByCircle(Figure circle, Point point)
	{
		if (circle.type != FiguresType::CIRCLE) return point;
		constexpr double max = std::numeric_limits<double>::max();
		constexpr double min = std::numeric_limits<double>::min();
		if (point == circle.first) return Point(max, max);
		if ((point.x == doctest::Approx(max) || point.x == doctest::Approx(min))
			&& (point.y == doctest::Approx(max) || point.y == doctest::Approx(min)))
			return circle.first;
		double x0 = circle.first.x, y0 = circle.first.y;
		double radius = distanceBetweenPoints(circle.first, circle.second);
		double divisor = (pow(point.x - x0, 2) + pow(point.y - y0, 2));
		double x = x0 + (pow(radius, 2) * (point.x - x0)) / divisor;
		double y = y0 + (pow(radius, 2) * (point.y - y0)) / divisor;

		return Point(x, y);
	}
	//public
	Figure::Figure()
		: puncturedPoint(nullptr), type(FiguresType::CIRCLE), first(Point()), second(Point()){}
	Figure::Figure(FiguresType type, Point first, Point second)
	{		
		puncturedPoint = nullptr;
		if (first == second) this->type = FiguresType::POINT;
		else this->type = type;
		this->first = first;
		this->second = second;
	}
	Figure::Figure(Point maxValue)
	{
		puncturedPoint = nullptr;
		int number = rand() % 2;
		if (number == 0) type = FiguresType::CIRCLE;
		else type = FiguresType::LINE;
		first = Point(maxValue.x);
		second = Point(maxValue.y);	
		if (first == second) first.x++;
	}
	Figure::Figure(const Figure& figure)
	{
		if (figure.puncturedPoint)
		{
			puncturedPoint = new Point(*figure.puncturedPoint);
		}
		else puncturedPoint = nullptr;
		type = figure.type;
		first = figure.first;
		second = figure.second;
	}
	Figure::~Figure()
	{
		if (puncturedPoint) delete puncturedPoint;
		puncturedPoint = nullptr;
		type = FiguresType::CIRCLE;
		first = Point();
		second = Point();
	}
	bool Figure::havePoint(Point point)
	{
		if (puncturedPoint && (*puncturedPoint == point)) return false;
		switch (type)
		{
		case FiguresType::CIRCLE:
		{
			double x = point.x - first.x, y = point.y - first.y;
			double radius = distanceBetweenPoints(first, second);
			return ((pow(x, 2) + pow(y,2)) == doctest::Approx(pow(radius, 2)));
		}
			break;
		case FiguresType::LINE:
		{
			Equation equation{ *this };
			if ((equation.a * point.x + equation.b * point.y - equation.c) == doctest::Approx(0)) return true;
			return false;
		}
			break;
		case FiguresType::POINT: return (point == first);
			break;
		}	
		return false;
	}
	Figure Figure::inversionTransformationByCircle(Figure circle)
	{
		if (circle.type != FiguresType::CIRCLE) return *this;
		Point first = this->first, second = this->second;
		if (this->type != FiguresType::POINT && this->second == circle.first)
		{
			second = 2 * first - second;
		}
		if (this->type == FiguresType::LINE && this->first == circle.first)
		{
			first = 2 * second - first;
		}
		Point x = inversionTransformationOfPointByCircle(circle, first);
		Point y = inversionTransformationOfPointByCircle(circle, second);
		if (this->type != FiguresType::POINT && this->havePoint(circle.first))
		{
			switch (this->type)
			{
			case FiguresType::CIRCLE:
			{
				Figure line{ FiguresType::LINE, x, y };
				line.puncturedPoint = new Point(circle.first);
				return line;
			}
			break;
			case FiguresType::LINE: return *this;
				break;
			default:
				break;
			}
		}
		else
		{
			Figure result{ FiguresType::CIRCLE, x, y };
			switch (this->type)
			{
			case FiguresType::CIRCLE: return result;
				break;
			case FiguresType::LINE:
			{
				result.puncturedPoint = new Point(circle.first);
				return result;
			}
			break;
			default:
				break;
			}
		}
		return Figure(FiguresType::POINT, x, y);
	}
	Figure Figure::symmetricalMappingByLine(Figure line)
	{
		if (line.type != FiguresType::LINE) return *this;

		return Figure(this->type, symmetricalMappingOfPointByLine(line, this->first)
			, symmetricalMappingOfPointByLine(line, this->second));
	}
	std::vector<Point> Figure::findPointsOfIntersection(Figure figure)
	{
		if (this->type != figure.type)
		{
			return intersectionOfCircleAndLine(*this, figure);
		}
		if (this->type == FiguresType::CIRCLE)
		{
			return intersectionOfTwoCircles(*this, figure);
		}

		return intersectionOfTwoLines(*this, figure);
	}
	//functions	and operators for Figure
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
	std::string toTheString(FiguresType value)
	{
		if (value == FiguresType::CIRCLE) return "Circle";
		if (value == FiguresType::LINE) return "Line";
		return "Point";
	}
	std::string toTheString(const Figure& value)
	{
		std::string result = "Figure: {type: " + toTheString(value.type) + ", ";
		if (value.type == FiguresType::CIRCLE) result += "centre point";
		else result += "first point";
		result += ": " + toTheString(value.first);
		if (value.type != FiguresType::POINT) result += ", second point: " + toTheString(value.second);
		if (value.puncturedPoint) result += ", punctured point: " + toTheString(*value.puncturedPoint);
		result +=" }";

		return result;
	}
	Figure randomValue(const Figure& maxValue)
	{
		return Figure(maxValue.first);
	}
	//Equation
	Equation::Equation() :a(0), b(0), c(0) {}
	Equation::Equation(Figure figure)
	{
		a = 0;
		b = 0;
		c = 0;
		if (figure.type == FiguresType::LINE)
		{
			a = figure.second.y - figure.first.y;
			b = figure.first.x - figure.second.x;
			c = a * figure.first.x + figure.first.y * b;
		}
	}
	//other functions
	std::vector<Point> solveSystemOfLineEquations(Equation equation1, Equation equation2)
	{
		double determinant = equation1.a * equation2.b - equation2.a * equation1.b;
		if (determinant == doctest::Approx(0)) return {};
		double determinant1 = equation1.c * equation2.b - equation2.c * equation1.b;
		double determinant2 = equation1.a * equation2.c - equation2.a * equation1.c;
		double x = determinant1 / determinant;
		double y = determinant2 / determinant;
		return { {x, y} };
	}
	std::vector<double> solveQuadraticEquation(double coefficientP, double coefficientQ, double coefficientD)
	{
		if (coefficientP == doctest::Approx(0))
		{
			return { -1 * coefficientD / coefficientQ };
		}
		double discriminant = pow(coefficientQ, 2) - 4 * coefficientP * coefficientD;
		if (discriminant < 0) return {};
		if (discriminant == doctest::Approx(0))
		{
			return { -1 * coefficientQ / (2 * coefficientP) };
		}
		double sqrtDiscriminant = sqrt(discriminant);
		return { (-1 * coefficientQ - sqrtDiscriminant) / (2 * coefficientP)
			, (-1 * coefficientQ + sqrtDiscriminant) / (2 * coefficientP) };
	}
}