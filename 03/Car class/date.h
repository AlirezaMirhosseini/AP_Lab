#pragma once

#include <iostream>
#include <string>

using namespace std;

class date{
private:
	int year;
	int month;
	int day;
public:
	void correct_print();
	void string_print();
	void set_year(int _year);
	void set_month(int _month);
	void set_day(int _day);
};