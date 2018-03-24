//Definicja znajduje się w pliku Point.cpp
#include <cmath>
#include <iostream>
#include "Square.h"
using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using namespace std;
geometry::Point::Point():x_(0),y_(0){
}

geometry::Point::~Point(){
}
geometry::Point::Point(double x, double y){
    x_ = x;
    y_ = y;
}
double geometry::Point:: GetX() const
{
    return x_;
}
double geometry::Point:: GetY() const
{
    return y_;
}
geometry::Square::Square(geometry::Point a_, geometry::Point b_, geometry::Point c_, geometry::Point d_){
    a = a_;
    b = b_;
    c = c_;
    d = d_;
}
double geometry::Square::Circumference ()
{
    double ab;
    if(sqrt((d.GetX() - a.GetX())* (d.GetX() - a.GetX())  + (d.GetY() - a.GetY()) * (d.GetY() - a.GetY())) == sqrt((c.GetX() - b.GetX())* (c.GetX() - b.GetX())  + (c.GetY() - b.GetY()) * (c.GetY() - b.GetY())))
    {
        ab = sqrt((b.GetX() - a.GetX())* (b.GetX() - a.GetX())  + (b.GetY() - a.GetY()) * (b.GetY() - a.GetY()));
        return 4 * ab;
    }
    else
    {
        return 0;
    }

}
double geometry::Square::Area()
{
    if(sqrt((d.GetX() - a.GetX())* (d.GetX() - a.GetX())  + (d.GetY() - a.GetY()) * (d.GetY() - a.GetY())) == sqrt((c.GetX() - b.GetX())* (c.GetX() - b.GetX())  + (c.GetY() - b.GetY()) * (c.GetY() - b.GetY())))
    {
        auto bok = sqrt((b.GetX() - a.GetX())* (b.GetX() - a.GetX())  + (b.GetY() - a.GetY()) * (b.GetY() - a.GetY()));
        return bok * bok;
    }
    else
    {
        return 0;
    }
}


