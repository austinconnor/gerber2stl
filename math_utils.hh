#pragma once
#include <math.h>
#include <algorithm>
#include <vector>


class Point{
public:
    float x,y;
    Point(){};
    Point(float x, float y);

};

class Line{
public:
    Point p1, p2;

    Line(){};
    Line(Point p1, Point p2);
    Line(float x1, float y1, float x2, float y2);
    bool intersects(Line line);

};

class Shape{
public:
    std::vector<Point> points;
    std::vector<Line> lines;

    Shape(std::vector<Point> points);
    Shape setCenter(float x, float y);

};

class MathUtils{
public:
    //amount of points in a circle
    static const int circleResolution = 20;

    static float Atan2(float x, float y);
    static double RadiansToDegrees(float rads);
    static double DegreesToRadians(float degrees);
    static Shape GenerateCircle(float radius);
    static Shape GenerateRectangle(float width, float height);
    static Shape GenerateObround(float width, float height);
    static Shape MergeShapes(std::vector<Shape> shapes);

};


