#ifndef PROJECTNAME_PATH_POINT_H_
#define PROJECTNAME_PATH_POINT_H_
namespace geometry
{
    class Point {
    public:
        Point();
        ~Point();
        Point(double x, double y);
        double GetX() const;
        double GetY() const;

    private:
        double x_, y_;
    };
    class Square {
    public:
        Square(Point a, Point b,Point c, Point D);
        double Circumference ();
        double Area();
    private:
        geometry::Point a,b,c,d;
    };
}


#endif  // PROJECTNAME_PATH_POINT_H_

