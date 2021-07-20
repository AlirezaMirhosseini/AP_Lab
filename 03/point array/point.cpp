#include "point.h"

using namespace std;

point::point() {
	x = 0;
	y = 0;
}
point::point(int _x, int _y) {
	x = _x;
	y = _y;
}
int point::get_X() { return x; }
int point::get_Y() { return y; }
void point::set_X(int _x) { x = _x; }
void point::set_Y(int _y) { y = _y; }
double point::get_length() { return sqrt((x * x) + (y * y)); }
void point::set_Coordinate(int _x, int _y) {
	x = _x;
	y = _y;
}
void point::print_Coordinate() { cout << "(" << x << "," << y << ")" << endl; }