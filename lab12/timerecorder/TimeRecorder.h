//
// Created by sad on 31.05.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H
#include<chrono>
#include <utility>

namespace profiling
{
    template<class T>
    auto TimeRecorder (T x)
    {
        auto from = std::chrono::high_resolution_clock::now();
        auto obj = x();
        auto to = std::chrono::high_resolution_clock::now();
        double time = std::chrono::duration<double,std::milli>(to-from).count();
        return std::make_pair(obj,time);
    };
}





#endif //JIMP_EXERCISES_TIMERECORDER_H
