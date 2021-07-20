#pragma once

#include <iostream>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

class point {
private:
	int x;
	int y;
public:
	point();
	point(int _x, int _y);
	int get_X();
	int get_Y();
	void set_X(int _x);
	void set_Y(int _y);
	double get_length();
	void set_Coordinate(int _x, int _y);
	void print_Coordinate();
};

