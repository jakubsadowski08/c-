//
// Created by sad on 03.05.18.
//

#include "MovieSubtitles.h"

using namespace moviesubs;

MicroDvdSubtitles::MicroDvdSubtitles() {

}

MicroDvdSubtitles::~MicroDvdSubtitles() {

}
MovieSubtitles::MovieSubtitles() {

}

MovieSubtitles::~MovieSubtitles() {

}

SubRipSubtitles::SubRipSubtitles() {

}

SubRipSubtitles::~SubRipSubtitles() {

}
void
MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::stringstream  *in,
                                                  std::stringstream  *out) {
    if (frame_per_second <= 0){
        throw SubtitlesException(0,"Invalid is less than 0");
    }
    if (in->str().empty())
        throw std::invalid_argument{"Argument isnt given"};
    int h = offset_in_micro_seconds * frame_per_second /1000 ;
    std::regex pattern(R"(\{([0-9]+)\}\{([0-9]+)\})");
    std::regex line_pattern{".*\n?"};

    string content = in->str();
    std::string line,swap;
    int line_num = 0;
    int value;
    int value_2;
    while (!content.empty()){
        line_num++;
        std::smatch result,result1;
        std::regex_search(content,result1,line_pattern);
        line=result1.str();
        if (!std::regex_search(line,result,pattern)){
            throw InvalidSubtitleLineFormat(line_num,line);
        }
        istringstream (result[1]) >> value;
        istringstream (result[2]) >> value_2;
        if (value+h<0)
            throw NegativeFrameAfterShift(line_num,line);
        if (value >value_2)
            throw SubtitleEndBeforeStart(line_num,line.substr(0,line.length()-1));
        content = result1.suffix();

        swap+= "{"+std::to_string(value +h)+"}"+"{"+std::to_string(value_2+h)+"}"+result.suffix().str();
    }
    *out << swap.c_str();
}
std::string SubRipSubtitles::Time(int from) {
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
/*std::regex long_word_regex("(\\w{7,})");
std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
std::cout << new_s << '\n';*/

void SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::stringstream *in,
                                          std::stringstream *out) {
    string content = in->str();
    std::smatch result;
    std::regex pattern(
            "(([0-9]+\n)(([0-9]{2,}):([0-9]{2}):([0-9]{2}),([0-9]{3}) --> ([0-9]{2,}):([0-9]{2}):([0-9]{2}),([0-9]{3}))(\n[^0-9]+))", std::regex::extended);
    if(offset_in_micro_seconds < 0)
    {
        std::regex_search(content ,result,pattern);
        content = result.suffix();
        std::regex_search(content ,result,pattern);
        if(std::stoi(result[2].str()) != 2)
        {
            throw OutOfOrderFrames(0,"we");
        }
        else
        {
            throw NegativeFrameAfterShift(0,"offset is less than 0");
        }

    }

    else if(in->str().empty())
        throw invalid_argument("Invalid argument");
    int h = offset_in_micro_seconds * frame_per_second / 1000;

    int line_num = 0;
    std::string line,swap;

    while (!content.empty()){
        line_num++;

        if(!std::regex_search(content ,result,pattern) || std::stoi(result[2].str()) != line_num)
        {
            throw InvalidSubtitleLineFormat(line_num,"cant find");
        }
        int from = offset_in_micro_seconds + std::stoi(result[4].str()) * 3600000 + std::stoi(result[5].str()) * 60000 + std::stoi(result[6].str()) * 1000 + std::stoi(result[7].str());
        int to = offset_in_micro_seconds + std::stoi(result[8].str()) * 3600000 + std::stoi(result[9].str()) * 60000 + std::stoi(result[10].str()) * 1000 + std::stoi(result[11].str());
        if(from > to)
        {
            throw SubtitleEndBeforeStart(line_num,result[3].str());
        }
        swap += result[2].str() + Time(from) + " --> " + Time(to) + result[12].str();
        content = result.suffix();
    }

    *out << swap.c_str();
}


int SubtitleEndBeforeStart::LineAt() const{
    return line_;
}
