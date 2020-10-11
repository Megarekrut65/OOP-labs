#pragma once
#include "my_point.h"

using namespace tdp;

/**
* Namespace for Figure on the plane
*/
namespace fop//figures on the plane
{
	/**
	* \brief Enum for Figure
	* 
	* Preserves the types of some geometric shapes:
	* - CIRCLE;
	* 
	* - LINE;
	* 
	* - POINT;
	*/
	enum class FiguresType
	{
		CIRCLE,
		LINE,
		POINT
	};
	/**
	* \brief Class for representing such geometric shapes as circle, line and point
	* 
	* The following operators are overridden for this structure: 
	* <, >, <=, >=, ==, !=, +, -
	* 
	* There are some operation for these shapes here
	*/
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
		FiguresType type;/**<Type of figure*/
		Point first;/**<The first point belonging to the figure(for circle it is centre point)*/
		Point second;/**<The second point belonging to the figure*/
		/**
		* Default constructor
		*/
		Figure();
		/**
		* \brief Parameterized constructor
		* 
		* If the points are equal then the figure will automatically have 'type' = POINT. 
		* If 'type' is POINT then points become equal
		*/
		Figure(FiguresType type, Point first, Point second);
		/**
		* \brief Random constructor
		* 
		* Creates figure with random 'type' and random points. 
		* Points will be less than 'maxValue'
		*/
		Figure(Point maxValue);
		/**
		* \brief Copy Constructor
		*
		* Default copy constructor copies the pointers to 'puncturedPoint',
		* so I added own copy constructor to copy the value of 'puncturedPoint'
		*/
		Figure(const Figure& figure);
		/**
		* \brief Destructor
		*
		* Deletes 'puncturedPoint'
		*/
		~Figure();
		/**
		* \brief Checking for belonging of a point to a figure
		* 
		* Each type has a different test: 
		* 
		* - for CIRCLE it checks whether the 'point' is the solution of the equation of the circle;
		* 
		* - for LINE - whether it is the solution of the equation of the line;
		*
		* - for POINT it checks whether these points are equal.
		* \param point that belongs or does not belong to the figure
		* \return - true if the point belongs to a figure
		* \return - false if the point doesn't belong to a figure
		*/
		bool havePoint(Point point);
		/**
		* \brief Finding intersection
		* 
		* Finds points of intersection of 'this' figure and 'figure'. Works for CIRCLE and LINE only. For POINT use 'havePoint'
		* 
		* Number of points can be different. Zero, one, two or infinite number.
		* \param figure is another figure that crosses 'this' or not
		* \return - array with points of intersection of two figures
		*/
		std::vector<Point> findPointsOfIntersection(Figure figure);
		/**
		* \brief Inversion transformation
		* 
		* Creates the figure that is inversion transformation of 'this' by the 'circle'. 
		* See [Inversion transformation](https://en.wikipedia.org/wiki/Inversion_transformation "Information in Wikipedia")
		* 
		* If type of 'circle' isn't CIRCLE then created figure will be 'this'.
		* Function works for CIRCLE, LINE, POINT as type of 'this'
		* 
		* For some created figures can be punctured point that will be in 'puncturedPoint'
		* 
		* \param circle relative to which the inversion will occur
		* \return - created figure
		*/
		Figure inversionTransformationByCircle(Figure circle);
		/**
		* \brief Symmetrical mapping
		* 
		* Creates the figure that is a symmetrical representation of 'this' figure 
		* relative to the 'line'. 
		* See [Symmetry in mathematics](https://en.wikipedia.org/wiki/Symmetry_in_mathematics "Information in Wikipedia")
		* 
		* If type of 'line' isn't LINE then created figure will be 'this'.
		* Function works for CIRCLE, LINE, POINT as type of 'this'
		* 
		* \param line relative to which the symmetrical mapping will occur
		* \return - created figure
		*/
		Figure symmetricalMappingByLine(Figure line);
		/**
		* \brief Friend function like std::to_string
		* 
		* Translate Figure into std::string. 
		* For all types of figures result will be different
		* 
		* \param value is figure that will be translated to std::string
		* \return - result of Translation
		*/
		friend std::string toTheString(const Figure& value);
	};	
	/**
	* \brief Struct for making linear equation for LINE
	* 
	* See [Linear equation](https://en.wikipedia.org/wiki/Linear_equation "Information in Wikipedia")
	* 
	* There is equation as a*x + b*y = c
	*/
	struct Equation
	{
		double a;/**<first coefficient of equation*/
		double b;/**<second coefficient of equation*/
		double c;/**<third coefficient of equation*/
		/**
		* Default constructor
		*/
		Equation();
		/**
		* The constructor for creating linear equation for 'figure' with type LINE (Figure).
		* If type of 'figure' isn't LINE then equation will be as 0*x + 0*y = 0
		*/
		Equation(Figure figure);
	};
	/**
	* \brief Comparison the figures by points and type
	* 
	* This comparison is quite specific. 
	* The Subtraction between the first and second points of each figure are compared
	* \param figure1 is first operand
	* \param figure2 is second operand
	* \return - true if 'figure1' < 'figure2'
	* \return - false if 'figure1' >= 'figure2'
	*/
	bool operator < (Figure figure1, Figure figure2);
	/**
	* \brief Comparison the figures by points and type
	*
	* This comparison is quite specific.
	* The Subtraction between the first and second points of each figure are compared
	* \param figure1 is first operand
	* \param figure2 is second operand
	* \return - true if 'figure1' > 'figure2'
	* \return - false if 'figure1' <= 'figure2'
	*/
	bool operator > (Figure figure1, Figure figure2);
	/**
	* \brief Comparison the figures by points and type
	*
	* This comparison is quite specific.
	* The Subtraction between the first and second points of each figure are compared
	* \param figure1 is first operand
	* \param figure2 is second operand
	* \return - true if 'figure1' <= 'figure2'
	* \return - false if 'figure1' > 'figure2'
	*/
	bool operator <= (Figure figure1, Figure figure2);
	/**
	* \brief Comparison the figures by points and type
	*
	* This comparison is quite specific.
	* The Subtraction between the first and second points of each figure are compared
	* \param figure1 is first operand
	* \param figure2 is second operand
	* \return - true if 'figure1' >= 'figure2'
	* \return - false if 'figure1' < 'figure2'
	*/
	bool operator >= (Figure figure1, Figure figure2);
	/**
	* \brief Comparison the figures by points and type
	*
	* This comparison is quite specific.
	* The Subtraction between the first and second points of each figure are compared
	* \param figure1 is first operand
	* \param figure2 is second operand
	* \return - true if 'figure1' == 'figure2'
	* \return - false if 'figure1' != 'figure2'
	*/
	bool operator == (Figure figure1, Figure figure2);
	/**
	* \brief Comparison the figures by points and type
	*
	* This comparison is quite specific.
	* The Subtraction between the first and second points of each figure are compared
	* \param figure1 is first operand
	* \param figure2 is second operand
	* \return - true if 'figure1' != 'figure2'
	* \return - false if 'figure1' == 'figure2'
	*/
	bool operator != (Figure figure1, Figure figure2);
	/**
	* \brief Adding two figures
	*
	* This Adding is quite specific.
	* Adds 'figure1.first' to 'figure2.first' and 'figure1.second' to 'figure2.second' 
	* and type will be 'type' of larger figure
	* \param figure1 is first operand
	* \param figure2 is second operand
	* \return - result of adding two figures
	*/
	Figure operator + (Figure figure1, Figure figure2);
	/**
	* \brief Subtraction two figures
	*
	* This Adding is quite specific.
	* Subtracts 'figure2.first' from 'figure1.first' and 'figure2.second' from 'figure1.second'
	* and type will be 'type' of larger figure
	* \param figure1 is first operand
	* \param figure2 is second operand
	* \return - result of Subtraction two figures
	*/
	Figure operator - (Figure figure1, Figure figure2);
	/**
	* std::to_string for enum class FiguresType
	*/
	std::string toTheString(FiguresType value);
	/**
	* \brief Function for creating random figure
	*
	* Uses in graph (gm::GraphMatrix and gs::GraphStructure)
	* \param maxValue is the maximum value that a point can take
	* \return - random figure
	*/
	Figure randomValue(const Figure& maxValue);
	/**
	* \brief The function for solving a system of linear equations
	* 
	* The equations as a*x + b*y = c
	* 
	* The number of solutions can be zero or one
	* \param equation1 is first linear equation
	* \param equation2 is second linear equation
	* \return - array with points that satisfy the system
	*/
	std::vector<Point> solveSystemOfLineEquations(Equation equation1, Equation equation2);
	/**
	* \brief The function for solving quadratic equation
	* 
	* The equation as P*x^2 + Q*x + D = 0
	* 
	* The number of solutions can be zero, one or two
	* \param coefficientP is first coefficient in equation
	* \param coefficientQ is second coefficient in equation
	* \param coefficientD is third coefficient in equation
	* \return - array with solutions
	*/
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
		if (type == FiguresType::POINT)
		{			
			this->second = first;
		}
		else
		{
			this->second = second;
		}		
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