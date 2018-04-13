
#include<iostream>
#include <complex>
#include"Matrix.h"
using namespace algebra;
int main()
{
    Matrix sum{};
    std::complex<double> c;
    std::vector<std::complex<double>> w;
    Matrix m1{{1. + 3.0i, 2. + 2.0i}, {3. + 1.0i, 4. + 6.0i}, {5. + 5.i, 6. + 4.0i}};
    Matrix other{{7. + 1.0i, 12. + 1.3i, 1.5 + 3.7i, 1.0i}, {15. + 2.0i, 2. + 4.6i, 2.1 + 3.8i, 1.4 + 0.2i}};
    auto x_ = m1.x_;
    std::cout <<x_.size() << x_[0].size();
    for(int i = 0;i < x_.size();i++)
    {
        for(int j = 0; j < x_[0].size();j++)
        {
            c =0;
            for(int k = 0;k < other.x_[0].size();k++)
            {
                c += x_[i][j] * other.x_[j][k];
            }
            w.emplace_back(c);
        }
        sum.x_.emplace_back(w);
        w.clear();
    }
    std::cout<<sum.Print();


}

