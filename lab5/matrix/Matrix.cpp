//
// Created by sad on 12.04.18.
//

#include "Matrix.h"
using namespace algebra;

Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> c)
{
    x_ = new std::vector<std::vector<std::complex<double>>>;
    for(const auto & v : c)
    {
        x_->emplace_back(v);
    }
}
Matrix::Matrix(size_t a, size_t b)
{
    x_ = new std::vector<std::vector<std::complex<double>>>(a);
    for(int i =0;i < b;i++)
    {
        x_[i] = new std::vector<std::complex<double>>(b);
    }
    si.first = a;
    si.second = b;
}
Matrix:: Matrix (const Matrix & other)
{
    x_ = new std::vector<std::vector<std::complex<double>>>;
    *x_ = *other.x_;
}




std::string Matrix::Print()
{
    std::stringstream stream;
    std::string w = "[";
    for(const auto &  v : *x_)
    {

        for(auto x : v)
        {
            w += std::to_string((int)x.real());
            w+="i";
            w += std::to_string((int)x.imag());
            w+= ", ";
            //Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
            //"[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]"
        }
        w.erase(w.length() - 2);
        w+= "; ";
    }
    w.erase(w.length() - 2);
    return w + "]";
}
Matrix Matrix::Add(const Matrix & other) const
{
    Matrix sum = Matrix{other.Size().first,other.Size().second};
    int a=0, b =0;
    for(auto i = x_->begin();i !=x_->end();i++)
    {
        for (auto j = i->begin();j != i->end();j++) {

            (*sum.x_)[0][0] = *j;
        }
    }
}
std::pair<size_t, size_t> Matrix::Size()const {
    return si;
}
