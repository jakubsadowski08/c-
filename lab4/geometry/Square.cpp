//Definicja znajduje się w pliku Point.cpp
#include <cmath>
#include <ostream>
#include "Square.h"
using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
geometry::Point::~Point(){
    cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
    cout << endl;
}
geometry::Square::Square(geometry::Point a_, geometry::Point b_, geometry::Point c_, geometry::Point d_){
    a_(a_);
    b_(b_);
    c_(c_);
    d_(d_);
}
double geometry::Square::Circumference ()
{
    auto ab = sqrt((b.x - a.x)* (b.x - a.x)  + (b.y - a.y) * (b.y - a.y));
    auto ac = sqrt((c.x - a.x) * (c.x - a.x) + ( c.y - a.y) *  (c.y - a.y));
    auto bd = sqrt((d.x - b.x) * (d.x - b.x) + ( d.y - b.y) *  (d.y - b.y));
    auto cd = sqrt((d.x - c.x) * (d.x - c.x) + ( d.y - c.y) *  (d.y - c.y));
    return ab + ac + bd + cd;

}
double geometry::Square::Area()
{
    if(sqrt((d.x - a.x)* (d.x - a.x)  + (d.y - a.y) * (d.y - a.y)) == sqrt((c.x - b.x)* (c.x - b.x)  + (c.y - b.y) * (c.y - b.y)))
    {
        auto bok = sqrt((b.x - a.x)* (b.x - a.x)  + (b.y - a.y) * (b.y - a.y));
        return bok * bok;
    }
}
geometry::Point::Point():x_(0),y_(0){
    cout << "Konstruktor bezparametrowy" << endl;
}

geometry::Point::Point(double x, double y){
    cout << "Konstruktor parametrowy" << endl;
    x_ = x;
    y_ = y;
}

