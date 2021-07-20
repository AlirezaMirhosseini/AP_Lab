#pragma once

#include <iostream>
#include <string>
#include "date.h"
#include "wheel.h"
#include "seat.h"

using namespace std;

class car{
private:
	date Production;
	wheel Wheel[100];
	seat Seat[100];
	int wheel_count;
	int seat_count;
	string c_color;
public:
	void DATE();
	int get_wheels();
	int get_seats();
	string get_c_color();
	void set_wheels(int _wheel_count);
	void set_seats(int _seat_count);
	void set_c_color(string _c_color);
	void set_DATE(int _year, int _month, int _day);
	void iwheel_set_status(int index);
	void iseat_set_status(int index);
	void iwheel_get_status(int index);
	void iseat_get_status(int index);
};