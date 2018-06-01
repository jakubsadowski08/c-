//
// Created by sad on 01.06.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H
#include<iostream>
namespace academia
{

    class TeacherId
    {
    public:
        TeacherId(int s) : w(s){};
        operator int();
        int w;

    };


    class Teacher {
    public:
        Teacher(int a, std::string str_,std::string str__) {
            a_ = a;
            x = str_;
            xd = str__;
        }
        int Id();
        std::string Name();
        std::string Department();
        int a_;
        std::string x;
        std::string xd;
    };
    class TeacherHash {
    public:
        std::size_t operator()(const Teacher &xds) const
        {
            std::size_t h1 = std::hash<int>{}(xds.a_);
            std::size_t h2 = std::hash<std::string>{}(xds.xd);
            std::size_t h3 = std::hash<std::string>{}(xds.x);
            return h1 ^ (h2 << 1) ^ h3; // or use boost::hash_combine (see Discussion)
        }
    };
    bool operator != (const academia::TeacherId s,const academia::TeacherId sd);
    bool operator != (const academia::Teacher s, const academia::Teacher sd);
    bool operator == (const int s, const academia::TeacherId);
    bool operator == (const academia::TeacherId s, const academia::TeacherId sd);
    bool operator == (const academia::Teacher s, const academia::Teacher sd);
}



#endif //JIMP_EXERCISES_TEACHERHASH_H
