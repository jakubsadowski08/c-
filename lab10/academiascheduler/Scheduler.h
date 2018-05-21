//
// Created by sad on 20.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include<exception>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <memory>
#include <set>
#include <vector>
#include <utility>
#include <map>
#include <iostream>
namespace academia {

    class SchedulingItem {
    public:
        SchedulingItem(int, int, int, int, int);

        int CourseId() const;

        int TeacherId() const;

        int RoomId() const;

        int TimeSlot() const;

        int Year() const;

    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    };

    class Schedule {
    public:
        Schedule &operator=(const Schedule &other);

        SchedulingItem operator[](int n) const;

        Schedule OfTeacher(int teacher_id) const;

        Schedule OfRoom(int room_id) const;

        Schedule OfYear(int year) const;

        std::vector<int> AvailableTimeSlots(int n_time_slots) const;

        void InsertScheduleItem(const SchedulingItem &item);

        size_t Size() const;

    private:
        std::vector<SchedulingItem> items;

    };
    class Scheduler
    {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    };
    class NoViableSolutionFound : public std::bad_exception
    {

    };
    class GreedyScheduler: public Scheduler
    {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;
    };
}







#endif //JIMP_EXERCISES_SCHEDULER_H
