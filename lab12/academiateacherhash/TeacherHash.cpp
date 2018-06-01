//
// Created by sad on 01.06.18.
//

#include "TeacherHash.h"



academia::TeacherId::operator int() {
    return w;
}

bool academia::operator!=(const academia::TeacherId s,const academia::TeacherId sd) {
    return s.w != sd.w;
}

bool academia::operator!=(const academia::Teacher s, const academia::Teacher sd) {
    return s.a_ != sd.a_ || s.x != sd.x || sd.xd != s.xd;
}

bool academia::operator==(const int s, const academia::TeacherId sd) {
    return s == sd.w;
}

bool academia::operator==(const academia::TeacherId s, const academia::TeacherId sd) {
    return s.w == sd.w;
}

bool academia::operator==(const academia::Teacher s, const academia::Teacher sd) {
    return s.a_ == sd.a_;
}


int academia::Teacher::Id() {
    return a_;
}

std::string academia::Teacher::Name() {
    return x;
}

std::string academia::Teacher::Department() {
    return xd;
}

