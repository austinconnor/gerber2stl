#include "math_utils.hh"

float MathUtils::Atan2(float x, float y){
    return (float)Atan2(x,y);
}

Shape MathUtils::GenerateCircle(float radius){
    std::vector<Point> points;
    Point center(0,0);

    for(float angle = 0; angle <= 2*M_PI; angle += (2*M_PI)/MathUtils::circleResolution){
        points.push_back(Point(center.x + radius*cos(angle), center.y + radius*sin(angle)));
    }

    Shape ret(points);

    return ret;
}

Shape MathUtils::GenerateRectangle(float width, float height){
    std::vector<Point> points;
    Point center(0,0);

    Point p1(center.x - width/2, center.y + height/2);
    Point p2(center.x + width/2, center.y + height/2);
    Point p3(center.x + width/2, center.y - height/2);
    Point p4(center.x - width/2, center.y - height/2);

    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);

    Shape ret(points);

    return ret;
}

Shape MathUtils::GenerateObround(float width, float height){

    std::vector<Shape> shapes;

    Shape rect = GenerateRectangle(width-height, height);
    Shape lcircle = GenerateCircle(height/2).setCenter(-1*(width-height)/2, 0);
    Shape rcircle = GenerateCircle(height/2).setCenter((width-height)/2, 0);

    shapes.push_back(lcircle);
    shapes.push_back(rect);
    shapes.push_back(rcircle);

    //merge points together
    //TODO: ADD CONVEX HULL METHOD
    Shape ret = MergeShapes(shapes).convexHull();
}

Shape MathUtils::MergeShapes(std::vector<Shape> shapes){

    std::vector<Point> points;
    
    for(Shape s : shapes){
        for(Point p : s.points){
            points.push_back(p);
        }
    }

    return Shape(points);
}

Point::Point(float x, float y){
    this->x = x;
    this->y = y;
}

Line::Line(Point p1, Point p2){
    this->p1 = p1;
    this->p2 = p2;
}

Line::Line(float x1, float y1, float x2, float y2){
    Line(Point(x1,y1), Point(x2,y2));
}

Shape::Shape(std::vector<Point> points){
    this->points = points;
}
