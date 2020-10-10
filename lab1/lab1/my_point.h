#pragma once
#include "my_override_functions_and_operators.h"
/**
* Namespace for two-dimensional points
*/
namespace tdp//two-dimensional points
{
	/**
	* \brief Two-dimensional points
	* 
	* The following operators are overridden for this structure: 
	* <, >, <=, >=, ==, !=, +, -, *, <<
	*/
	struct Point
	{
		double x;/**<First coordinate*/
		double y;/**<Second coordinate*/
		/**
		* Default constructor
		*/
		Point();
		/**
		* Parameterized constructor
		*/
		Point(double x, double y);
		/**
		* \brief Random constructor
		* 
		* Creates the point with first and second coordinate <= 'maxValue'
		*/
		Point(double maxValue);
		/**
		* Copy constructor
		*/
		Point(const Point& point);
	};
	/**
	* \brief Comparison the point by coordinates
	* 
	* First, compares the first coordinates, if they are equal, then compares the second
	* \param first is first operand
	* \param second is second operand
	* \return true if 'first' < 'second'
	* \return false if 'first' >= 'second'
	*/
	bool operator < (Point first, Point second);
	/**
	* \brief Comparison the points by coordinates
	*
	* First, compares the first coordinates, if they are equal, then compares the second
	* \param first is first operand
	* \param second is second operand
	* \return - true if 'first' > 'second'
	* \return - false if 'first' <= 'second'
	*/
	bool operator > (Point first, Point second);
	/**
	* \brief Comparison the points by coordinates
	*
	* First, compares the first coordinates, if they are equal, then compares the second
	* \param first is first operand
	* \param second is second operand
	* \return - true if 'first' <= 'second'
	* \return - false if 'first' > 'second'
	*/
	bool operator <= (Point first, Point second);
	/**
	* \brief Comparison the points by coordinates
	*
	* First, compares the first coordinates, if they are equal, then compares the second
	* \param first is first operand
	* \param second is second operand
	* \return - true if 'first' >= 'second'
	* \return - false if 'first' < 'second'
	*/
	bool operator >= (Point first, Point second);
	/**
	* \brief Comparison the points by coordinates
	*
	* Compares the first coordinates and compares the second
	* \param first is first operand
	* \param second is second operand
	* \return - true if 'first' == 'second'
	* \return - false if 'first' != 'second'
	*/
	bool operator == (Point first, Point second);
	/**
	* \brief Comparison the points by coordinates
	*
	* Compares the first coordinates and compares the second
	* \param first is first operand
	* \param second is second operand
	* \return - true if 'first' != 'second'
	* \return - false if 'first' == 'second'
	*/
	bool operator != (Point first, Point second);
	/**
	* \brief Adding two points
	*
	* Adds first coordinates and adds second coordinates
	* \param first is first operand
	* \param second is second operand
	* \return - Point that is the result of adding two points
	*/
	Point operator + (Point first, Point second);
	/**
	* \brief Subtraction two points
	*
	* Subtracts first coordinates and Subtracts second coordinates
	* \param first is first operand
	* \param second is second operand
	* \return - Point that is the result of subtraction two points
	*/
	Point operator - (Point first, Point second);
	/**
	* \brief Multiplication point by scalar
	*
	* Multiply the first coordinate by scalar and Multiply the second coordinate by scalar
	* \param scalar is first operand
	* \param point is second operand
	* \return - Point that is the result of multiplication point by scalar
	*/
	Point operator * (double scalar, Point point);
	/**
	* \brief Override std::cout <<
	*
	* Adds the first and second coordinates separated by a comma in parentheses to 'out'. 
	* Example (1.03, 4.22)
	* \param out is first operand
	* \param point is second operand
	* \return - out
	*/
	std::ostream& operator << (std::ostream& out, Point point);
	/**
	* \brief It like function std::to_string
	* 
	* Translate Point into std::string
	* \param value is two-dimensional point
	* \return - the line in which the point will be written
	*/
	std::string toTheString(Point value);
	/**
	* \brief Finding the dictance
	* 
	* Finds the distance between 'first' and 'second'
	* 
	* See [Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance "Information in Wikipedia")
	* 
	* \param first is first point
	* \param second is second point
	* \return - distance between points
	*/
	double distanceBetweenPoints(Point first, Point second);
}
namespace tdp
{
	Point::Point() : x(0), y(0) {}
	Point::Point(double x, double y): x(x), y(y) {}
	Point::Point(double maxValue) : x(ofo::randomValue(maxValue)), y(ofo::randomValue(maxValue)) {}
	Point::Point(const Point& point)
	{
		x = point.x;
		y = point.y;
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
		return (first.x == doctest::Approx(second.x) && first.y == doctest::Approx(second.y));
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
	Point operator * (double scalar, Point point)
	{
		return Point(point.x * scalar, point.y * scalar);
	}
	std::ostream& operator << (std::ostream& out, Point point)
	{
		return out << "(" << point.x << ", " << point.y << ")";
	}
	std::string toTheString(Point value)
	{
		return "( " + ofo::toTheString(value.x) + ", " + ofo::toTheString(value.y) + " )";
	}
	double distanceBetweenPoints(Point first, Point second)
	{		
		return sqrt(pow(second.x - first.x, 2) + pow(second.y - first.y, 2));
	}
}