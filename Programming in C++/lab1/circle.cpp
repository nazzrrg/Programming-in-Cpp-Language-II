#include "circle.h"

const double PI = 3.14159;

Circle::Circle()
{
    radius = 0;
    center.x = 0;
    center.y = 0;
}
Circle::Circle(double rad, double x, double y)
{
    radius = rad;
    center.x = x;
    center.y = y;
}
double Circle::getRadius()
{
    return radius;
}
double Circle::getCenterX()
{
    return center.x;
}
double Circle::getCenterY()
{
    return center.y;
}
void Circle::setRadius(double r)
{
    radius = r;
}
void Circle::setCenter(double x, double y)
{
    center.x = x;
    center.y = y;
}
double Circle::getLength()
{
    return 2*PI*radius;
}
double Circle::getSquare()
{
    return PI*radius*radius;
}

void moveCenter(Circle& c, double x, double y) {
   c.setCenter(c.getCenterX() + x, c.getCenterY() + y);
}
void moveCenter(Circle* c, double x, double y) {
    c->setCenter(c->getCenterX() + x, c->getCenterY() + y);
}