//
// Created by sad on 12.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include<iostream>
#include <complex>
#include <vector>

namespace algebra
{
    class Matrix {
    public:
        Matrix();
        Matrix(std::initializer_list<std::vector<std::complex<double>>> c);
        Matrix(size_t a,size_t b);
        Matrix (const Matrix & other);
        Matrix (Matrix && other) noexcept;
        Matrix & operator= (const Matrix& other);
        std::string Print() const;
        std::pair<size_t, size_t> Size()const;
        Matrix Add(Matrix other) const;
        Matrix Sub(Matrix other) const;
        Matrix Mul(Matrix other) const;
        Matrix Pow(int a) const;
        std::vector<std::vector<std::complex<double>>>x_;
    private:

        std::pair<size_t, size_t> si;
    };
}



#endif //JIMP_EXERCISES_MATRIX_H
