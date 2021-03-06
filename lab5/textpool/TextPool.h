//
// Created by jak on 12.04.18.
//
#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include<iostream>
#include<vector>
//#include<list>
namespace pool
{
    class TextPool
    {
    public :
        TextPool();
        TextPool (TextPool && other) noexcept ;
        ~TextPool();
        //TextPool& operator= (const TextPool& other);
        TextPool(std::initializer_list<std::experimental::string_view > c) ;
        TextPool& operator= (TextPool&& other)noexcept ;
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
    private :
        std::vector<std::experimental::string_view >* strs;
    };

}

#endif //JIMP_EXERCISES_TEXTPOOL_H
