#ifndef PROJECTNAME_PATH_POINT_H_
#define PROJECTNAME_PATH_POINT_H_
namespace geometry
{
    class Point {
    public:
        //Konstruktor bezparametrowy
        Point();
        //Konstruktor parametrowy
        Point(double x, double y);
        //Destruktor wykonywany przed zwolnieniem pamięci
        ~Point();

        //Metody nie modyfikujące stanu obiektu (const na końcu metody)
        //nie mogą zmodyfikować tego obiektu.
        void ToString(std::ostream *out) const;
        double Distance(const geometry::Point &other) const;
    private:
        //w przeciwienstwie do pythona C++ wymaga jawnej deklaracji składowych pól klasy:
        double x_, y_;
    };
    class Square {
    public:
        Square(Point a, Point b,Point c, Point D);
        //Destruktor wykonywany przed zwolnieniem pamięci

        //Metody nie modyfikujące stanu obiektu (const na końcu metody)
        //nie mogą zmodyfikować tego obiektu.
        double Circumference () const;
        double Area() const;
    private:
        geometry::Point a_,b_,c_,d_;
    };
}


#endif  // PROJECTNAME_PATH_POINT_H_

