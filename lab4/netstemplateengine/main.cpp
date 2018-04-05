#include<iostream>
#include <unordered_map>
#include <map>
#include <regex>
#include "SimpleTemplateEngine.h"
using namespace nets;

int main()
{
    std::string xd = "haha {asd}}";
    std::cout << xd.substr(xd.find("{{") + 2, xd.find("}}") - xd.find("{{") - 2);
}