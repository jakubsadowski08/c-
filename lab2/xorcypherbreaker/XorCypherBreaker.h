#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
#ifndef JIMP_EXERCISES_XORCRYPTERBREAKER_H
#define JIMP_EXERCISES_XORCRYPTERBREAKER_H
std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<std::string> &dictionary);
int IsInDic(std::vector<std::string>dictionary,std::vector<char> a);

#endif //JIMP_EXERCISES_XORCRYPTERBREAKER_H
