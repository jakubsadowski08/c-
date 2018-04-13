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
    si = { x_.size(), x_[0].size()};
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
    if(Size().first == 0 && Size().second == 0)
    {
        return "[]";
    }
    else
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
                im << x.imag();
                im >>i;
                re << x.real();
                re >>r;
                w+=r;
                w+="i";
                w+=i;
                w+= ", ";
            }
            w.erase(w.length() - 2);
            w+= "; ";
        }
        w.erase(w.length() - 2);
        return w + "]";
    }
}
Matrix::Matrix(Matrix&& other) noexcept
{
    x_ = other.x_;
}
Matrix & Matrix::operator= (const Matrix& other)
{
    Matrix tmp(other);         // re-use copy-constructor
    *this = std::move(tmp); // re-use move-assignment
    return *this;
}
Matrix Matrix::Add(Matrix other) const{
    Matrix sum;
    sum.si = { x_.size(), other.x_[0].size()};
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
    sum.si = { x_.size(), other.x_[0].size()};

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
    if(x_[0].size() != other.x_.size())
    {
        sum.Size() = {0, 0};
    }
    else
    {
        sum.si = { x_.size(), other.x_[0].size()};
    }
    std::complex<double> c;
    std::vector<std::complex<double>> w;
    for(int i = 0;i < x_.size();i++)
    {
        for(int j = 0; j < other.x_[0].size();j++)
        {
            c =0;
            for(int k = 0;k < x_[0].size();k++)
            {
                c += x_[i][k] * other.x_[k][j];
            }
            w.emplace_back(c);
        }
        sum.x_.emplace_back(w);
        w.clear();
    }
    return sum;
}
Matrix Matrix::Pow(int a) const
{
    Matrix sum{};
    if(x_[0].size()!= x_.size())
    {
        sum.si = {0, 0};
        return sum;
    }
    else
    {
        sum.si = {x_[0].size(), x_.size()};
    }
    if(a == 0)
    {
        for(int i =0;i < x_[0].size();i++)
        {
            sum.x_.emplace_back(x_[i]);
        }
        for(int i =0;i < x_[0].size();i++)
        {
            for(int j =0;j < x_.size();j++)
            {
                if(i ==j)
                {
                    sum.x_[i][j].real(1);
                }
                else
                {
                    sum.x_[i][j].real(0);
                    sum.x_[i][j].imag(0);
                }
            }
        }
        return sum;
    }
    if(a == 1)
    {
        sum.x_ = x_;
        return sum;
    }
    auto tmp = *this;
    auto tmp_2 = *this;
    sum.x_ = tmp.Mul(tmp_2).x_;
    for(int i = 2 ; i != a;i++)
    {
        sum.x_ = tmp.Mul(sum).x_;
    }
    return sum;
}
std::pair<size_t, size_t> Matrix::Size() const {
    return si;
}
