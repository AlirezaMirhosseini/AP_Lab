#pragma once

#include <iostream>
#include <string>

using namespace std;

class Date{
private:
	int year;
	int month;
	int day;
public:
	Date(int _year, int _month, int _day);
	void SetDate(int _year, int _month, int _day);
	void SetYear(int _year);
	int GetYear();
	void SetMonth(int _month);
	int GetMonth();
	void SetDay(int _day);
	void Print();
	Date& NextDay();
	Date& PreviousDay();
	Date& NextMonth();
	Date& PreviousMonth();
	Date& NextYear();
	Date& PreviousYear();
	static bool IsLeapYear(int _year);
	static bool IsValidDate(int _year, int _month, int _day);
	static int GetDayOfWeek(int, int, int);
	static void PrintDayOfWeek(int, int, int);
};

