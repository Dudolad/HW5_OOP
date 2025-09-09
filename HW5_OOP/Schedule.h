#pragma once
#include "Time.h"
class Schedule
{
private:

	Time startTime;

	int lessonDuration;

	int shortBreak;

	int longBreak;

	int longBreakAfter;

	int totalLessons;


public:

	Schedule(Time start, int lessonDur, int shortBr, int longBr, int longAfter, int lessons);


	void generateSchedule()const;
};

