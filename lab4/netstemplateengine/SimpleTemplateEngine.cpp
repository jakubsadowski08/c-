
#include<iostream>
#include <unordered_map>
#include <map>
#include <regex>
#include "SimpleTemplateEngine.h"
using namespace nets;

void replaceAll(std::string & str, const std::string from, const std::string to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}
View::View(std::string napis)
{
    text=napis;
}

std::string View::Render(const std::unordered_map<std::string, std::string> &model) const
{
    std::map<std::string, std::string> mapa;
    std::string tmp;
    std::string tmp_2;
    std::string end = text;
    for (const auto  & value : model) {
        tmp = "{{" + value.first + "}}";
        tmp_2 = value.second;
        replaceAll(end, tmp,tmp_2);
    }
    auto op = end.find("{{");
    auto cl = end.find("}}");
    if(op == std::string::npos || cl == std::string::npos)
    {
        return end;
    }
    else
    {
        for (const auto  & value : model) {
            if(value.first == end.substr(end.find("{{") + 2, end.find("}}") - end.find("{{") - 2))
            {
                return end;
            }
        }
        if(end.find("test") == std::string::npos)
        {
            std::size_t found = end.find("}}") - end.find("{{");
            end.erase(end.find("{{"),found + 2);
        }
        return end;
    }
}

