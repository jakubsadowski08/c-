
#include<iostream>
#include <complex>

int main()
{
    std::stringstream s;
    double x = 5.55555;
    s.precision(3);
    s << x;
    std::string w;
    s >>w;
    s << x;
    s >> w;
    std::cout <<w;


}

