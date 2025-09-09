#include "Schedule.h"
#include <iostream>
using namespace std;

Schedule::Schedule(Time start, int lessonDur, int shortBr, int longBr, int longAfter, int lessons)
    : startTime(start), lessonDuration(lessonDur), shortBreak(shortBr),
    longBreak(longBr), longBreakAfter(longAfter), totalLessons(lessons) {}

void Schedule::generateSchedule() const
{
    Time current = startTime;

    for (int i = 1; i <= totalLessons; i++) {
        cout << "Lesson " << i << ": ";
        current.showTime();

        current += lessonDuration;

        if (i == longBreakAfter) {
            current += longBreak;
        }
        else if (i < totalLessons) {
            current += shortBreak;
        }
    }
}
