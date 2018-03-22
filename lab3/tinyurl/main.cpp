#include"TinyUrl.h"
#include<string>
#include<iostream>
int main()
{
    auto p = tinyurl::Init();
    std::cout<<tinyurl::Encode("walono", &p);
}