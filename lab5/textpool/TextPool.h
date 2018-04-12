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
namespace pool
{
    class TextPool
    {
    public :
        TextPool();
        TextPool(const TextPool           &)
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
    private :
        std::string_view str;
    };

}


#endif //JIMP_EXERCISES_TEXTPOOL_H
