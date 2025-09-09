#include "Time.h"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

Time::Time()
{
	time_t sec = time(NULL);
	tm now{};
	localtime_s(&now, &sec);

	hour = now.tm_hour;
	minutes = now.tm_min;
	seconds = now.tm_sec;
	format = true;
}

Time::Time(int hour, int minutes, int seconds, bool format)
{
	this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
	this->format = format;
}

Time::Time(const Time& obj)
{
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	this->format = obj.format;
}

Time& Time::operator=(const Time& obj)
{
	if (this != &obj) {
		this->hour = obj.hour;
		this->minutes = obj.minutes;
		this->seconds = obj.seconds;
		this->format = obj.format;
	}
	return *this;
}

Time::~Time()
{
	//нічого не треба звільняти
}

void Time::setHour(int hour)
{
	if (hour >= 0 && hour < 24) this->hour = hour;
}

int Time::getHour() const
{
	return hour;
}

void Time::setMinutes(int minutes)
{
	if (minutes >= 0 && minutes < 60) this->minutes = minutes;
}

int Time::getMinutes() const
{
	return minutes;
}

void Time::setSeconds(int seconds)
{
	if (seconds >= 0 && seconds < 60) this->seconds = seconds;
}

int Time::getSeconds() const
{
	return seconds;
}

void Time::setFormat(bool format)
{
	this->format = format;
}

bool Time::getFormat() const
{
	return format;
}

bool Time::valid() const
{
	return (hour >= 0 && hour < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60);
}

void Time::tickTime()
{
	seconds++;
	if (seconds >= 60) { seconds = 0; minutes++; }
	if (minutes >= 60) { minutes = 0; hour++; }
	if (hour >= 24) { hour = 0; }
}

void Time::untickTime()
{
	seconds--;
	if (seconds < 0) { seconds = 59; minutes--; }
	if (minutes < 0) { minutes = 59; hour--; }
	if (hour < 0) { hour = 23; }
}

void Time::showTime() const
{
	int h = hour;
	string suffix = "";

	if (!format) { // 12-годинний формат
		suffix = (h >= 12) ? " PM" : " AM";
		h = h % 12;
		if (h == 0) h = 12;
	}

	cout << setfill('0') << setw(2) << h << ":"
		<< setw(2) << minutes << ":"
		<< setw(2) << seconds;

	if (!format) cout << suffix;
	cout << endl;
}

bool Time::operator==(const Time& obj) const&
{
	return hour == obj.hour && minutes == obj.minutes && seconds == obj.seconds;
}

bool Time::operator!=(const Time& obj) const&
{
	return !(*this == obj);
}

bool Time::operator>(const Time& obj) const&
{
	if (hour != obj.hour) return hour > obj.hour;
	if (minutes != obj.minutes) return minutes > obj.minutes;
	return seconds > obj.seconds;
}

bool Time::operator<(const Time& obj) const&
{
	return !(*this > obj) && (*this != obj);
}

bool Time::operator>=(const Time& obj) const&
{
	return (*this > obj) || (*this == obj);
}

bool Time::operator<=(const Time& obj) const&
{
	return (*this < obj) || (*this == obj);
}

Time& Time::operator+=(float s)
{
	for (int i = 0; i < (int)s; i++) tickTime();
	return *this;
}

Time& Time::operator-=(float s)
{
	for (int i = 0; i < (int)s; i++) untickTime();
	return *this;
}

Time& Time::operator+=(int m)
{
	for (int i = 0; i < m; i++) { minutes++; if (minutes >= 60) { minutes = 0; hour++; if (hour >= 24) hour = 0; } }
	return *this;
}

Time& Time::operator-=(int m)
{
	for (int i = 0; i < m; i++) { minutes--; if (minutes < 0) { minutes = 59; hour--; if (hour < 0) hour = 23; } }
	return *this;
}

Time& Time::operator+=(long h)
{
	hour = (hour + h) % 24;
	return *this;
}

Time& Time::operator-=(long h)
{
	hour = (hour - h) % 24;
	if (hour < 0) hour += 24;
	return *this;                                                   
}

Time Time::operator+(float s) const&
{
	Time tmp = *this;
	tmp += s;
	return tmp;
}

Time Time::operator-(float s) const&
{
	Time tmp = *this;
	tmp -= s;
	return tmp;
}

Time Time::operator+(int m) const&
{
	Time tmp = *this;
	tmp += m;
	return tmp;
}

Time Time::operator-(int m) const&
{
	Time tmp = *this;
	tmp -= m;
	return tmp;
}

Time Time::operator+(long h) const&
{
	Time tmp = *this;
	tmp += h;
	return tmp;
}

Time Time::operator-(long h) const&
{
	Time tmp = *this;
	tmp -= h;
	return tmp;
}
