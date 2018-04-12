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
Matrix::Matrix()
{
    x_ = new std::vector<std::vector<std::complex<double>>>;
    si.first = 0;
    si.second = 0;
}
Matrix::Matrix(size_t a, size_t b)
{
    x_ = new std::vector<std::vector<std::complex<double>>>;
    si.first = a;
    si.second = b;
}
Matrix::Matrix (const Matrix & other)
{
    x_ = new std::vector<std::vector<std::complex<double>>>;
    *x_ = *other.x_;
}




std::string Matrix::Print() const
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
Matrix::Matrix(Matrix&& other) noexcept
{
    *x_ = *other.x_;
    other.x_ = nullptr;
}
Matrix Matrix::Add(Matrix other) const{
    auto * sum = new Matrix;
    sum->x_ = new std::vector<std::vector<std::complex<double>>>;
    sum->si.first =0;
    sum->si.second = 0;
    auto o = *other.x_;
    auto m = *x_;
    auto s = *sum->x_;
    std::vector<std::complex<double>> p(3);
    for(int i =0;i < o.size();i++)
    {
        for(int j =0;j<o[0].size();j++)
        {
            p[j] = m[i][j] + o[i][j];
        }
        s.emplace_back(p);
    }
    return * sum;
}
Matrix Matrix::Sub(Matrix other) const{
    Matrix sum = Matrix{};
    auto o = *other.x_;
    auto m = *x_;
    auto s = *sum.x_;
    for(int i =0;i < o.size();i++)
    {
        for(int j =0;j<o[0].size();j++)
        {
            o[i][j] =  (m[i][j] - o[i][j]);
        }
        s.emplace_back(o[i]);
    }

}
std::pair<size_t, size_t> Matrix::Size() const {
    return si;
}
