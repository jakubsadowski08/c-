//
// Created by sad on 12.04.18.
//
#include <iomanip>
#include "Matrix.h"
using namespace algebra;

Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> c)
{
    for(const auto & v : c)
    {
        x_.emplace_back(v);
    }
}
Matrix::Matrix()
{
    si.first = 0;
    si.second = 0;
}
Matrix::Matrix(size_t a, size_t b)
{
    si.first = a;
    si.second = b;
}
Matrix::Matrix (const Matrix & other)
{
    x_ = other.x_;
}


std::string Matrix::Print() const
{

    std::string w = "[";
    std::string r;
    std::string i;
    for(const auto &  v : x_)
    {

        for(auto x : v)
        {
            std::stringstream re;
            std::stringstream im;
            auto h = (int)x.imag();
            int s = 1;
            if(h == 0)
            {
                s = 2;
            }
            while(h)
            {
                h = h / 10;
                s++;
            }
            im.precision(s);
            im << x.imag();
            im >>i;
            //
            h = (int)x.real();
            s = 1;
            if(h == 0)
            {
                s = 2;
            }
            while(h)
            {
                h = h / 10;
                s++;
            }
            re.precision(s);
            re << x.real();
            re >>r;
            w+=r;
            w+="i";
            w+=i;
            w+= ", ";
            //"[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]"
        }
        w.erase(w.length() - 2);
        w+= "; ";
    }
    w.erase(w.length() - 2);
    return w + "]";
}
Matrix::Matrix(Matrix&& other) noexcept
{
    x_ = other.x_;
}
Matrix Matrix::Add(Matrix other) const{
    Matrix sum;
    auto o = other.x_;
    auto m = x_;
    for(int i =0;i < o.size();i++)
    {
        for(int j =0;j<o[0].size();j++)
        {
            o[i][j] +=  m[i][j];
        }
        sum.x_.emplace_back(o[i]);
    }
    return sum;
}
Matrix Matrix::Sub(Matrix other) const{
    Matrix sum;
    std::vector<std::complex<double>> w;
    for(int i =0;i < x_.size();i++)
    {
        for(int j =0;j < x_[0].size();j++)
        {
            other.x_[i][j] =  x_[j][i] - other.x_[i][j] ;
        }
        sum.x_.emplace_back(other.x_[i]);
    }
    return sum;
}
Matrix Matrix::Mul(Matrix other) const
{
    Matrix sum{};
    std::complex<double> c;
    std::vector<std::complex<double>> w(x_.size());
    for(int i = 0;i < x_.size();i++)
    {
        for(int j = 0; j < x_.size();j++)
        {
            c =0;
            for(int k = 0;k < x_[0].size();k++)
            {
                c += x_[i][k] * other.x_[k][j];
            }
            w[j] = c;
        }
        sum.x_.emplace_back(w);
    }
    return sum;
}
std::pair<size_t, size_t> Matrix::Size() const {
    return si;
}
