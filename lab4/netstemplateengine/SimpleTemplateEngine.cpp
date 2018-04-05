//
// Created by michal on 05.04.18.
//

#include <string>
#include <unordered_map>
#include <map>
#include <regex>
#include "SimpleTemplateEngine.h"
using namespace nets;

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
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
    for (auto i = model.begin()) {

    }
}

