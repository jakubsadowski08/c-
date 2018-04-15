//
// Created by sad on 15.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include<set>

namespace datastructures
{
    class Word
    {
    public:
        Word();
        Word(const std::string & a);
        Word(const Word & a);
        std::string str_;
    };
    class Counts
    {
    public:
        Counts();
        Counts(int a);
        Counts (const Counts & a);

        int a_;
    };
    class WordCounter
    {
    public:
        WordCounter();
        WordCounter(std::string);
        WordCounter(std::initializer_list<Word> c);
        WordCounter & FromInputStream(std::ifstream);
        unsigned long DistinctWords();
        unsigned long TotalWords();
        std::vector<std::pair<Word,Counts>> p_;
        int operator[](std::string a);
        std::set<Word> Words();

    };
    bool operator==(datastructures::Counts a, int b);
    bool operator<(datastructures::Word,datastructures::Word);
    bool operator==(datastructures::Word a,datastructures::Word b);
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
