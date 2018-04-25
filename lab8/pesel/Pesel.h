

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H
#include<iostream>
#include<string>
#include <stdexcept>
using namespace std;
namespace academia
{
    class Pesel {
    public:
        Pesel(std::string a);
        void validatePESEL(const char*);
        std::string pesel_;
    };
    class InvalidPeselChecksum : public invalid_argument
    {
    public:
        InvalidPeselChecksum(const Pesel &m);
        Pesel GetPesel() const {
            return x_;
        }
    private:
        Pesel x_;
    };
    class InvalidPeselLength : public invalid_argument
    {
    public:
        InvalidPeselLength(const Pesel &m);
        Pesel GetPesel() const {
            return x_;
        }
    private:
        Pesel x_;
    };
    class InvalidPeselCharacter : public invalid_argument
    {
    public:
        InvalidPeselCharacter(const Pesel &m);
        Pesel GetPesel() const {
            return x_;
        }
    private:
        Pesel x_;
    };
    class AcademiaDataValidationError : public invalid_argument
    {
    public:
        AcademiaDataValidationError(const Pesel &m);
        Pesel GetPesel() const {
            return x_;
        }
    private:
        Pesel x_;
    };
}



#endif //JIMP_EXERCISES_PESEL_H
