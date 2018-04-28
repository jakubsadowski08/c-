//
// Created by sadojaku on 25.04.18.
//

#include <vector>
#include "Pesel.h"
using namespace academia;
Pesel::Pesel(std::string a)
{
    pesel_ = a;
    if(pesel_.length() != 11)
    {
        throw InvalidPeselLength(*this);
    }
    for(auto w : pesel_)
    {
        if(!isdigit(w))
        {
            throw InvalidPeselCharacter(*this);
        }
    }
    std::vector<int> w = {9,7,3,1,9,7,3,1,9,7};
    int sum =0;
    int h;
    for(int i = 0;i < pesel_.length(); i++)
    {
        h = (int)pesel_[i] - 48;
        sum += h * w[i];
    }
    char x = sum % 10 + 48;

    if(x != pesel_[10])
    {
        auto hhh = pesel_[10];
        throw InvalidPeselChecksum(*this);
    }
}
InvalidPeselChecksum::InvalidPeselChecksum(const Pesel &m) : invalid_argument{"Wrong checkkum"}, x_{m}
{

}
InvalidPeselLength::InvalidPeselLength(const Pesel &m) : invalid_argument{"Wrong length"}, x_{m}
{

}
InvalidPeselCharacter::InvalidPeselCharacter(const Pesel &m) : invalid_argument{"Wrong pesel character"}, x_{m}
{

}
AcademiaDataValidationError::AcademiaDataValidationError(const Pesel &m) : invalid_argument{"Data validation error"}, x_{m}
{

}