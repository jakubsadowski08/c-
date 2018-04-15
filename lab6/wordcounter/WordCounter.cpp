

#include "WordCounter.h"
#include<fstream>

using namespace datastructures;
bool datastructures::operator==(datastructures::Counts a, int b)
{
    return a.a_ ==b;
}
bool datastructures::operator<(datastructures::Word a,datastructures::Word b)
{
    return a.str_ < b.str_;
}
bool datastructures::operator==(datastructures::Word a,datastructures::Word b)
{
    return a.str_ == b.str_;
}
bool IsNotIn(std::vector<std::pair<Word,Counts>> & a, Word s)
{
    for(auto & x : a)
    {
        if(x.first.str_ == s.str_)
        {
            x.second.a_++;
            return false;
        }
    }
    return true;
}
bool IsNotIn(std::vector<std::pair<Word,Counts>> & a, std::string s)
{
    for(auto & x : a)
    {
        if(x.first.str_ == s)
        {
            x.second.a_++;
            return false;
        }
    }
    return true;
}
int WordCounter::operator[](std::string a)
{
    for(auto x : p_)
    {
        if(x.first.str_ == a)
        {
            return x.second.a_;
        }
    }
    return 0;
}
WordCounter::WordCounter(std::string a)
{
    std::pair<Word,Counts> s;
    Counts w;
    s.second = w;
    if(p_.empty()) {
        s.second.a_ = 1;
        s.first = a;
        p_.emplace_back(s);
    }
    if(IsNotIn(p_,a))
    {
        s.second.a_ = 1;
        s.first = a;
        p_.emplace_back(s);
    }
}
WordCounter & WordCounter::FromInputStream(std::ifstream a)
{
    std::string s;
    while(!a.eof())
    {
        a >> s;
        WordCounter(s);
    }
}
Word::Word()
{
    str_ = "";
}
Word::Word(const Word & a)
{
    str_ = a.str_;
}
Word::Word(const std::string & a)
{
    str_ = a;
}
Counts::Counts()
{
    a_ = 0;
}
Counts::Counts(int a)
{
    a_= a;
}
Counts::Counts(const Counts & a)
{
    a_ = a.a_;
}
WordCounter::WordCounter()
{
    std::pair<Word,Counts> s;
    s.first.str_ = "";
    s.second.a_ = 0;
    p_.emplace_back(s);
}

WordCounter::WordCounter(std::initializer_list<Word> c)
{
    std::pair<Word,Counts> s;
    Counts w;
    s.second = w;
    if(p_.empty())
    {
        s.first =*c.begin();
        s.second.a_ = 1;
        p_.emplace_back(s);
    }
    for(auto it = c.begin();++it < c.end();) {
        if (IsNotIn(p_, *it)) {
            s.first = *it;
            s.second.a_ = 1;
            p_.emplace_back(s);
        }
    }
}
unsigned long WordCounter::DistinctWords()
{
    unsigned long sum = 0;
    for(const auto & v : p_)
    {
        if(v.first.str_ =="")
        {
            continue;
        }
        else
        {
            sum++;
        }
    }
    return sum;
}
unsigned long WordCounter::TotalWords()
{
    unsigned long sum = 0;
    for(const auto & v : p_)
    {
        sum += v.second.a_;
    }
    return sum;
}
std::set<Word> WordCounter::Words()
{
    std::set<Word> x;
    for(auto v : p_)
    {
        x.emplace(v.first);
    }
    return x;
}