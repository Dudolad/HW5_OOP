#pragma once

class Time
{
	int hour;
	int minutes;
	int seconds;
	bool format;// true = utc (24-hours), false = am/pm (12-hours),


public:

	Time(); // Current local time
	Time(int hour, int minutes, int seconds, bool format = true);
	Time(const Time& obj); //Визначити: чи потрібен Конструктор Копіювання?
	Time& operator = (const Time& obj); // Визначити: чи потрібен Оператор Присвоювання?
	~Time(); // Визначити: чи потрібен Деструктор?


	void setHour(int hour);
	int getHour()const;
	void setMinutes(int minutes);
	int getMinutes()const;
	void setSeconds(int seconds);
	int getSeconds()const;
	void setFormat(bool format);
	bool getFormat()const;

	bool valid()const; //time check
	void tickTime(); //every tick add one second
	void untickTime(); //every tick remove one second
	void showTime()const; //show time by the format


	//--------- Comparison operators ---------

	bool operator == (const Time& obj)const&;
	bool operator != (const Time& obj)const&;
	bool operator > (const Time& obj)const&;
	bool operator < (const Time& obj)const&;
	bool operator >= (const Time& obj)const&;
	bool operator <= (const Time& obj)const&;


	//--------- Assignment operators ---------

	Time& operator += (float s); // add seconds
	Time& operator -= (float s);
	Time& operator += (int m); // add minutes
	Time& operator -= (int m);
	Time& operator += (long h); // add hours
	Time& operator -= (long h);


	//--------- Arithmetic operators ---------

	Time operator + (float s)const&; // add seconds
	Time operator - (float s)const&;
	Time operator + (int m)const&; // add minutes
	Time operator - (int m)const&;
	Time operator + (long h)const&; // add hours
	Time operator - (long h)const&;
};

