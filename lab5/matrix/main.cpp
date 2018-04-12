
#include<iostream>
#include <complex>

int main()
{
    std::stringstream s;
    std::complex<double> z1 = 1i * 1i;
    s << z1;
    std::string w ;
    s >> w;
    std::cout <<w;

}

