//
// Created by sad on 20.05.18.
//

#include "Scheduler.h"

academia::SchedulingItem::SchedulingItem(int course_id_, int teacher_id_, int room_id_, int time_slot_, int year_) {
    course_id = course_id_;
    teacher_id = teacher_id_;
    room_id = room_id_;
    time_slot = time_slot_;
    year = year_;

}

int academia::SchedulingItem::CourseId() const {
    return course_id;
}

int academia::SchedulingItem::TeacherId() const {
    return teacher_id;
}

int academia::SchedulingItem::RoomId() const {
    return room_id;
}

int academia::SchedulingItem::TimeSlot() const {
    return time_slot;
}

int academia::SchedulingItem::Year() const {
    return year;
}


academia::Schedule &academia::Schedule::operator=(const academia::Schedule &other) {
    items = other.items;
}

void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
    items.emplace_back(item);
}

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    academia::Schedule obj;
    std::copy_if (items.begin(), items.end(), back_inserter(obj.items), [teacher_id](SchedulingItem f){return teacher_id == f.TeacherId();} );
    return obj;
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    academia::Schedule obj;
    std::copy_if (items.begin(), items.end(), back_inserter(obj.items), [room_id](SchedulingItem f){return room_id == f.RoomId();} );
    return obj;
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    academia::Schedule obj;
    std::copy_if (items.begin(), items.end(), back_inserter(obj.items), [year](SchedulingItem f){return year == f.Year();} );
    return obj;
}

academia::SchedulingItem academia::Schedule::operator[](int n) const {
    return items[n];
}

size_t academia::Schedule::Size() const {
    return items.size();
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    std::vector<int> free_slots;
    bool b = true;
    for(int i = 1;i <= n_time_slots;i++)
    {
        for(auto x : items)
        {
            if(x.TimeSlot() == i)
            {
                b = false;
            }
        }
        if(b)
        {
            free_slots.emplace_back(i);

        }
        b = true;
    }
    return free_slots;
}

academia::Schedule academia::GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) {
    academia::Schedule obj;
    int course,teacher,room,year,taken_time_slots = 1;
    auto ind = 0;
    for(const auto & x : teacher_courses_assignment)
    {
        teacher = x.first;
        for(const auto & w : x.second)
        {
            course = w;
            for(auto d: courses_of_year)
            {
                for(auto f: d.second)
                {
                    if(course==f) year=d.first;
                }
            }

            if(taken_time_slots >n_time_slots)
            {
                taken_time_slots = 1;
                ind++;
                if(ind +1 > rooms.size())
                {
                    throw NoViableSolutionFound();
                }
            }
            room = rooms[ind];
            SchedulingItem item{course,teacher,room,taken_time_slots,year};
            obj.InsertScheduleItem(item);
            taken_time_slots++;

        }
    }
    return obj;
}
