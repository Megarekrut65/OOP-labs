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
		Figure line{ FiguresType::LINE, {0, 3}, {3, -1} };
		std::vector<Point> points = circle.findPointsOfIntersection(line);
		CHECK(points.size() == 2);
		CHECK(points[0] == Point(-2, 6));
		CHECK(points[1] == Point(4, -2));
	}
	SUBCASE("zero or many points with other circle")
	{

	}
	SUBCASE("one point with other circle")
	{

	}
	SUBCASE("two points with other circle")
	{

	}

}