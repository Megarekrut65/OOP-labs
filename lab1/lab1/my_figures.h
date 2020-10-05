#pragma once
#include "my_point.h"

using namespace tdp;

namespace fop//figures on the plane
{
	enum class FiguresType
	{
		Circle,
		Line,
		Point
	};
	struct Figure
	{
	private:
		Point* puncturedPoint;
	public:
		FiguresType type;
		Point first;//for circle it is centre point
		Point second;
		Figure();
		Figure(FiguresType type, Point first, Point second);
		Figure(Point maxValue);//creates random figure
		Figure(const Figure& figure);
		~Figure();
		bool have(Point point);
		friend std::string toTheString(const Figure& value);
		friend Figure inversionTransformationOfFigureByCircle(Figure circle, Figure figure);
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
	double distanceFromLineToPoint(Figure line, Point point);
	Intersection pointsOfIntersection(Figure figure1, Figure figure2);
	Intersection intersectionOfCircleAndLine(Figure circle, Figure line);
	Intersection solveSystemOfLineEquations(Equation equation1, Equation equation2);
	Intersection intersectionOfTwoLines(Figure line1, Figure line2);
	std::vector<double> solveQuadraticEquation(double coefficientP, double coefficientQ, double coefficientD);
	std::vector<Point> intersectionOfTwoCirclesByCoordinates(double x1, double x2, double y1, double y2, double radius1, double radius2);
	Intersection intersectionOfTwoCircles(Figure circle1, Figure circle2);
	Figure createPerpendicularLine(Figure line, Point point);
	Point symmetricalMappingOfPointByLine(Figure line, Point point);
	Figure symmetricalMappingOfFigureByLine(Figure line, Figure figure);
	Point inversionTransformationOfPointByCircle(Figure circle, Point point);
}
namespace fop
{
	//Figure
	Figure::Figure()
		: puncturedPoint(nullptr), type(FiguresType::Circle), first(Point()), second(Point()){}
	Figure::Figure(FiguresType type, Point first, Point second)
	{		
		puncturedPoint = nullptr;
		if (first == second) this->type = FiguresType::Point;
		else this->type = type;
		this->first = first;
		this->second = second;
	}
	Figure::Figure(Point maxValue)
	{
		puncturedPoint = nullptr;
		int number = rand() % 2;
		if (number == 0) type = FiguresType::Circle;
		else type = FiguresType::Line;
		first = Point(maxValue);
		second = Point(maxValue);	
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
		type = FiguresType::Circle;
		first = Point();
		second = Point();
	}
	bool Figure::have(Point point)
	{
		switch (type)
		{
		case FiguresType::Circle:
		{
			double x = point.x - first.x, y = point.y - first.y;
			double radius = distanceBetweenPoints(first, second);
			return ((pow(x, 2) + pow(y,2)) == doctest::Approx(pow(radius, 2)));
		}
			break;
		case FiguresType::Line:
		{
			Equation equation{ *this };
			if ((equation.a * point.x + equation.b * point.y + equation.c) == 0) return true;
			return false;
		}
			break;
		case FiguresType::Point: return (point == first);
			break;
		}	
		return false;
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
	std::string toTheString(FiguresType value)
	{
		if (value == FiguresType::Circle) return "Circle";
		if (value == FiguresType::Line) return "Line";
		return "Point";
	}
	std::string toTheString(const Figure& value)
	{
		std::string result = "Figure: {type: " + toTheString(value.type) + ", ";
		if (value.type == FiguresType::Circle) result += "centre point";
		else result += "first point";
		result += " : " + toTheString(value.first);
		if (value.type != FiguresType::Point) result += ", second point: " + toTheString(value.second);
		if (value.puncturedPoint) result += ", punctured point: " + toTheString(*value.puncturedPoint);
		result +=" }";

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
		for (std::size_t i = 0; i < numberOfPoints; i++) std::cout << points[i] << " ";
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
			c = a * figure.first.x + figure.first.y * b;
		}
	}
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
		if (distanceSquare == doctest::Approx(radiusSquare))
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
	Intersection solveSystemOfLineEquations(Equation equation1, Equation equation2)
	{
		double determinant = equation1.a * equation2.b - equation2.a * equation1.b;
		if (determinant == doctest::Approx(0)) return Intersection();
		double determinant1 = equation1.c * equation2.b - equation2.c * equation1.b;
		double determinant2 = equation1.a * equation2.c - equation2.a * equation1.c;
		double x = determinant1 / determinant;
		double y = determinant2 / determinant;
		return Intersection(false, 1, { {x, y} });
	}
	Intersection intersectionOfTwoLines(Figure line1, Figure line2)
	{
		if (line1.type != FiguresType::Line || line2.type != FiguresType::Line) return Intersection();
		Equation equation1{ line1 }, equation2{ line2 };
		return solveSystemOfLineEquations(equation1, equation2);
	}
	std::vector<double> solveQuadraticEquation(double coefficientP, double coefficientQ, double coefficientD)
	{
		if (coefficientP == doctest::Approx(0))
		{
			return {-1 * coefficientD / coefficientQ};
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
	std::vector<Point> intersectionOfTwoCirclesByCoordinates(double x1, double x2, double y1, double y2, double radius1, double radius2)
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
		std::cout << "y.size = " << y.size() << std::endl;
		switch (y.size())
		{
		case 0: return {};
			break;
		case 1: return { { coefficientB * y[0] + coefficientC, y[0]} };
			break;
		case 2: return {{coefficientB * y[0] + coefficientC, y[0]}
					 ,{ coefficientB * y[1] + coefficientC, y[1]} };
			break;
		}

		return {};
	}
	Intersection intersectionOfTwoCircles(Figure circle1, Figure circle2)
	{
		if (circle1.type != FiguresType::Circle 
			|| circle2.type != FiguresType::Circle) return Intersection();
		double radius1 = distanceBetweenPoints(circle1.first, circle1.second);
		double radius2 = distanceBetweenPoints(circle2.first, circle2.second);
		// (x - x1)^2 + (y - y1)^2 = radius1^2
		// (x - x2)^2 + (y - y2)^2 = radius2^2
		double x1 = circle1.first.x, y1 = circle1.first.y
			, x2 = circle2.first.x, y2 = circle2.first.y;
		if (x1 != doctest::Approx(x2))
		{
			std::vector<Point> points = intersectionOfTwoCirclesByCoordinates(x1, x2, y1, y2, radius1, radius2);
			return Intersection(false, points.size(), points);
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
			return Intersection(false, points.size(), points);
		}
		return Intersection();
	}
	Intersection pointsOfIntersection(Figure figure1, Figure figure2)
	{
		if (figure1.type != figure2.type)
		{
			return intersectionOfCircleAndLine(figure1, figure2);
		}
		if (figure1.type == FiguresType::Circle)
		{
			return intersectionOfTwoCircles(figure1, figure2);
		}

		return intersectionOfTwoLines(figure1, figure2);
	}
	Figure createPerpendicularLine(Figure line, Point point)
	{
		if (line.type != FiguresType::Line) return Figure();
		Equation equation1{line}, equation2;
		equation2.a = line.second.x - line.first.x;
		equation2.b = line.second.y - line.first.y;
		equation2.c = point.x * equation2.a + point.y * equation2.b;
		Intersection intersection = solveSystemOfLineEquations(equation1, equation2);
		if (intersection.points.size() != 1) return Figure();
		return Figure(FiguresType::Line, point, intersection.points[0]);
	}
	Point symmetricalMappingOfPointByLine(Figure line, Point point)
	{
		if (line.type != FiguresType::Line) return point;
		Figure perpendicularLine = createPerpendicularLine(line, point);//perpendicularLine.second ª line

		return (2 * perpendicularLine.second - point);
	}
	Figure symmetricalMappingOfFigureByLine(Figure line, Figure figure)
	{
		if (line.type != FiguresType::Line) return figure;

		return Figure(figure.type, symmetricalMappingOfPointByLine(line, figure.first)
								 , symmetricalMappingOfPointByLine(line, figure.second));
	}
	Point inversionTransformationOfPointByCircle(Figure circle, Point point)
	{
		if (circle.type != FiguresType::Circle) return point;
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
	Figure inversionTransformationOfFigureByCircle(Figure circle, Figure figure)
	{
		if (circle.type != FiguresType::Circle) return figure;
		if (figure.type != FiguresType::Point && figure.second == circle.first)
		{
			figure.second = 2 * figure.first - figure.second;
		}
		if (figure.type == FiguresType::Line && figure.first == circle.first)
		{
			figure.first = 2 * figure.second - figure.first;
		}
		Point x = inversionTransformationOfPointByCircle(circle, figure.first);
		Point y = inversionTransformationOfPointByCircle(circle, figure.second);
		if (figure.type != FiguresType::Point && figure.have(circle.first))
		{
			switch (figure.type)
			{
			case FiguresType::Circle:
			{
				Figure line{ FiguresType::Line, x, y};
				line.puncturedPoint = new Point(circle.first);
				return line;
			}
				break;
			case FiguresType::Line: return figure;
				break;
			default:
				break;
			}
		}
		else
		{
			Figure result{ FiguresType::Circle, x, y };
			switch (figure.type)
			{
			case FiguresType::Circle: return result;
			break;
			case FiguresType::Line:
			{				
				result.puncturedPoint = new Point(circle.first);
				return result;
			}
				break;
			default:
				break;
			}
		}
		return Figure(FiguresType::Point, x, y);
	}
}