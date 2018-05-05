//
// Created by sad on 03.05.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <istream>
#include <iostream>
#include <stdexcept>
#include <regex>
#include <sstream>
using namespace std;

namespace moviesubs
{
    class MovieSubtitles
    {
    public:
        MovieSubtitles();
        virtual ~MovieSubtitles();
        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::stringstream  *in, std::stringstream  *out) = 0;
    };
    class MicroDvdSubtitles :public MovieSubtitles
    {
    public:
        MicroDvdSubtitles();
        virtual ~MicroDvdSubtitles();
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::stringstream *in, std::stringstream *out) override;

    };
    class SubRipSubtitles : public MovieSubtitles
    {
    public:
        SubRipSubtitles();
        virtual ~SubRipSubtitles();
        std::string Time(int from);
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::stringstream *in, std::stringstream *out) override;
    };


    class SubtitlesException : public std::invalid_argument{
    public:
        SubtitlesException(const int & line, const std::string & exception_message) : invalid_argument(exception_message) {};
    };

    class NegativeFrameAfterShift : public SubtitlesException{
    public:
        NegativeFrameAfterShift(int line, const std::string & exception_message) : SubtitlesException(line,"Framerate cant be negative"){};
    };

    class SubtitleEndBeforeStart : public SubtitlesException{
    public:
        SubtitleEndBeforeStart(int line_num, std::string line) : SubtitlesException(line_num,"At line "+std::to_string(line_num)+": "+line), line_{line_num} {};
        int LineAt() const;
        int line_;

    };

    class InvalidSubtitleLineFormat : public SubtitlesException{
    public:
        InvalidSubtitleLineFormat(int line_num, const std::string &message) : SubtitlesException(line_num,message), line_{line_num} {};
        int line_;
    };

    class MissingTimeSpecification : public SubtitlesException{
    public:
        MissingTimeSpecification(int line, const std::string &message) : SubtitlesException(line, "Time missing") {};
    };

    class OutOfOrderFrames : public SubtitlesException{
    public:
        OutOfOrderFrames(int line, const std::string &message) : SubtitlesException(line, "Bad order") {};
    };
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
