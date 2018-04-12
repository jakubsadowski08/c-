//
// Created by jak on 12.04.18.
//

#include<iterator>
#include "TextPool.h"
using namespace pool;
TextPool::TextPool()
{
    strs = new std::vector<std::experimental::string_view >;
}
TextPool::TextPool(std::initializer_list<std::experimental::string_view > c)
{
    strs = new std::vector<std::experimental::string_view >;
    for(auto v : c)
    {
        strs->emplace_back(v);
    }
}
TextPool::~TextPool()
{
    delete strs;
}
TextPool::TextPool(TextPool &&other) noexcept
{
    strs = other.strs;
    for(auto  i =strs->begin() ;i != strs->end();i++)
    {
        for(auto j = strs->begin();j < strs->end();j++)
        {
            if(i < j && (*i == *j))
            {
                strs->erase(j);
                j--;
            }
        }
    }
    other.strs = nullptr;
}
/*TextPool & TextPool::operator=(const TextPool &other)
{
    TextPool tmp(other);
    bool b;
    for(auto x : *tmp.strs)
    {
        b = true;
        for(auto v : *this->strs)
        {
            if(v == x)
            {
                b = false;
            }
        }
        if(b)
        {
            this->strs->emplace_back(std::move(x));
        }
    }
    return * this;
}*/
TextPool & TextPool::operator=(TextPool&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }
    delete this->strs;
    this->strs = other.strs;
    other.strs = nullptr;
    return *this;
}
std::experimental::string_view TextPool::Intern(const std::string &str)
{
    if(strs==nullptr)
    {
        strs = new std::vector<std::experimental::string_view >;
        strs->emplace_back(str);
        return str;
    }
    for(auto v : *strs)
    {
        if(str == v)
        {
            return v;
        }
    }
    strs->emplace_back(str);
    return str;
}
size_t TextPool::StoredStringCount() const
{
    if(strs == nullptr)
    {
        return 0;
    }
    return strs->size();
}