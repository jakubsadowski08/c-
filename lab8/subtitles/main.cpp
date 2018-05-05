#include <iostream>
using namespace std;

std::string Time(int from) {
    std::string output;
    auto from_milisec = from % 1000;
    from = from / 1000;
    auto from_sec = from % 60;
    from = from / 60;
    auto from_min = from % 60;
    from = from / 60;
    auto from_hou = from % 60;
    from = from / 60;
    if(from_hou > 9)
        output += std::to_string(from_hou) + ":";
    else
    {
        output += "0" + std::to_string(from_hou) + ":";
    }
    if(from_min > 9)
        output += std::to_string(from_min) + ":";
    else
    {
        output += "0" + std::to_string(from_min) + ":";
    }
    if(from_sec > 9)
        output += std::to_string(from_sec) + ",";
    else
    {
        output += "0" + std::to_string(from_sec) + ",";
    }
    if(from_milisec > 99)    {
        output += std::to_string(from_milisec);
    }
    else if (from_milisec >9)
    {
        output += "0" + std::to_string(from_milisec);
    }
    else
    {
        output += "00" + std::to_string(from_milisec);
    }
    return output;

}
#include"MovieSubtitles.h"
int main() {
    stringstream in {"1\n00:00:10,345 --> 00:00:12,678\nTEXT\n\n2\n00:19:14,141 --> 00:17:20,100\nTT\n"};
    stringstream out;
    std::regex pattern(
            "(([0-9]+\n)(([0-9]{2,}):([0-9]{2}):([0-9]{2}),([0-9]{3}) --> ([0-9]{2,}):([0-9]{2}):([0-9]{2}),([0-9]{3}))(\n[^0-9]+))", std::regex::extended);
    std::smatch result;
    auto content = in.str();
    std::regex_search(content,result,pattern);
    int w = 0;
    for(auto v : result)
    {

        std::cout <<w << " - " << v <<endl;
        w++;
    }
    std::cout << result.suffix();

}