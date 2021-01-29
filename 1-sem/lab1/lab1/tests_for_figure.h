#pragma once
#include "doctest.h"
#include "my_figures.h"

using namespace fop;

TEST_CASE("testing the finding points of intersection of circle and other figures")
{
	Figure circle{ FiguresType::CIRCLE, {1, 2}, {5, 5} };
	SUBCASE("zero points with line")
	{
		Figure line{ FiguresType::LINE, {10, 0}, {8, -2} };
		std::vector<Point> points = circle.findPointsOfIntersection(line);
		CHECK(points.size() == 0);//points.size() == 0 when the figures coincide or do not intersect
	}
	SUBCASE("one point with line")
	{
		Figure line{ FiguresType::LINE, {6, 0}, {6, 10} };
		std::vector<Point> points = circle.findPointsOfIntersection(line);
		CHECK(points.size() == 1);
		CHECK(points[0] == Point(6, 2));
	}
	SUBCASE("two points with line")
	{
		Figure line{ FiguresType::LINE, {-2, 6}, {4, -2} };
		std::vector<Point> points = circle.findPointsOfIntersection(line);
		CHECK(points.size() == 2);
		CHECK(points[0] == Point(4, -2));
		CHECK(points[1] == Point(-2, 6));
	}
	SUBCASE("zero or many points with other circle")
	{
		Figure circle1{ FiguresType::CIRCLE, {2, 3}, {3, 3} };
		std::vector<Point> points = circle.findPointsOfIntersection(circle1);
		CHECK(points.size() == 0);
	}
	SUBCASE("one point with other circle")
	{
		Figure circle1{ FiguresType::CIRCLE, {8, 2}, {10, 2} };
		std::vector<Point> points = circle.findPointsOfIntersection(circle1);
		CHECK(points.size() == 1);
		CHECK(points[0] == Point(6, 2));
	}
	SUBCASE("two points with other circle")
	{
		Figure circle1{ FiguresType::CIRCLE, {6, 2}, {2, 3} };
		std::vector<Point> points = circle.findPointsOfIntersection(circle1);
		CHECK(points.size() == 2);
		CHECK(points[0] == Point(4.3, -1.75633));
		CHECK(points[1] == Point(4.3, 5.75633));
	}

}
TEST_CASE("testing the finding points of intersection of line and other figures")
{
	Figure line{ FiguresType::LINE, {1, 2}, {5, 6} };
	SUBCASE("zero points with other line")
	{
		Figure line1{ FiguresType::LINE, {2, 1}, {3, 2} };
		std::vector<Point> points = line.findPointsOfIntersection(line1);
		CHECK(points.size() == 0);//points.size() == 0 when the figures coincide or do not intersect
	}
	SUBCASE("one point with other line")
	{
		Figure line1{ FiguresType::LINE, {1, 4}, {3, 2} };
		std::vector<Point> points = line.findPointsOfIntersection(line1);
		CHECK(points.size() == 1);
		CHECK(points[0] == Point(2, 3));
	}
	SUBCASE("zero points with circle")
	{
		Figure circle{ FiguresType::CIRCLE, {-1, 4}, {-2, 4} };
		std::vector<Point> points = line.findPointsOfIntersection(circle);
		CHECK(points.size() == 0);
	}
	SUBCASE("one point with circle")
	{
		Figure circle{ FiguresType::CIRCLE, {4, 1}, {2, 3} };
		std::vector<Point> points = line.findPointsOfIntersection(circle);
		CHECK(points.size() == 1);
		CHECK(points[0] == Point(2, 3));
	}
	SUBCASE("two points with circle")
	{
		Figure circle{ FiguresType::CIRCLE, {0, 1}, {-2, -1} };
		std::vector<Point> points = line.findPointsOfIntersection(circle);
		CHECK(points.size() == 2);
		CHECK(points[0] == Point(-2, -1));
		CHECK(points[1] == Point(2, 3));
	}
}
TEST_CASE("testing the symmetrical mapping of point by line")
{
	Figure line{ FiguresType::LINE, {4, 0}, {4, 1} };
	SUBCASE("for point")
	{
		Figure point1{ FiguresType::POINT, {2, 3}, {2, 3} };
		Figure point2 = point1.symmetricalMappingByLine(line);
		CHECK(point2.type == FiguresType::POINT);
		CHECK(point2.first == Point(6, 3));
		CHECK(point2.second == Point(6, 3));
	}
	SUBCASE("for circle")
	{
		Figure circle1{ FiguresType::CIRCLE, {2, 3}, {6, 0} };
		Figure circle2 = circle1.symmetricalMappingByLine(line);
		CHECK(circle2.type == FiguresType::CIRCLE);
		CHECK(circle2.first == Point(6, 3));
		CHECK(circle2.second == Point(2, 0));
	}
	SUBCASE("for other line")
	{
		Figure line1{ FiguresType::LINE, {3, 3}, {5, 5} };
		Figure line2 = line1.symmetricalMappingByLine(line);
		CHECK(line2.type == FiguresType::LINE);
		CHECK(line2.first == Point(5, 3));
		CHECK(line2.second == Point(3, 5));
	}
}
TEST_CASE("testing the inversion transformation by circle")
{
	Figure circle{ FiguresType::CIRCLE, {-3, 3}, {-3, -2} };
	SUBCASE("for point on the circle")
	{
		Figure point1{ FiguresType::POINT, {2, 3}, {2, 3} };
		Figure point2 = point1.inversionTransformationByCircle(circle);
		CHECK(point2.type == FiguresType::POINT);
		CHECK(point2.first == Point(2, 3));
		CHECK(point2.second == Point(2, 3));
	}
	SUBCASE("for point outside the circle")
	{
		Figure point1{ FiguresType::POINT, {3, 4}, {3, 4} };
		Figure point2 = point1.inversionTransformationByCircle(circle);
		CHECK(point2.type == FiguresType::POINT);
		CHECK(point2.first == Point(1.05405, 3.67568));
		CHECK(point2.second == Point(1.05405, 3.67568));
		Figure point3 = point2.inversionTransformationByCircle(circle);
		CHECK(point3.type == FiguresType::POINT);
		CHECK(point3.first == Point(3, 4));
		CHECK(point3.second == Point(3, 4));
	}
	SUBCASE("for other circle that not crossing the centre of circle")
	{
		Figure circle1{ FiguresType::CIRCLE, {6, 4}, {4, 3} };
		CHECK(!circle1.havePoint({ -3, 3 }));
		Figure circle2 = circle1.inversionTransformationByCircle(circle);
		CHECK(circle2.type == FiguresType::CIRCLE);
		CHECK(circle2.first == Point(-0.256098, 3.30488));
		CHECK(circle2.second == Point(0.571429, 3));
	}
	SUBCASE("for other circle that crossing the centre of circle")
	{
		Figure circle1{ FiguresType::CIRCLE, {2, 3}, {-3, 3} };
		CHECK(circle1.havePoint({ -3, 3 }));
		Figure circle2 = circle1.inversionTransformationByCircle(circle);
		CHECK(circle2.type == FiguresType::LINE);
		CHECK(circle2.first == Point(2, 3));
		CHECK(circle2.second == Point(-0.5, 3));		
		CHECK(!circle2.havePoint({ -3, 3 }));
	}
	SUBCASE("for other line that not crossing the centre of circle")
	{
		Figure line1{ FiguresType::LINE, {9, 2}, {10, 4} };
		CHECK(!line1.havePoint({ -3, 3 }));
		Figure line2 = line1.inversionTransformationByCircle(circle);
		CHECK(line2.type == FiguresType::CIRCLE);
		CHECK(line2.first == Point(-0.931034, 2.82759));
		CHECK(line2.second == Point(-1.08824, 3.14706));	
		CHECK(!line2.havePoint({ -3, 3 }));
	}
	SUBCASE("for other line that crossing the centre of circle")
	{
		Figure line1{ FiguresType::LINE, {-4, 2}, {-1, 5} };
		CHECK(line1.havePoint({ -3, 3 }));
		Figure line2 = line1.inversionTransformationByCircle(circle);
		CHECK(line2.type == FiguresType::LINE);
		CHECK(line2.first == Point(-4, 2));
		CHECK(line2.second == Point(-1, 5));
		CHECK(line2.havePoint({ -3, 3 }));
	}
}