#include "car.h"


void car::DATE() {Production.string_print();}
int car::get_seats() { return seat_count; }
int car::get_wheels() { return wheel_count; }
string car::get_c_color() { return c_color; }
void car::set_c_color(string _c_color) { c_color = _c_color; }
void car::set_seats(int _seat_count) { seat_count = _seat_count; }
void car::set_wheels(int _wheel_count) { wheel_count = _wheel_count; }
void car::set_DATE(int _year, int _month, int _day) {
	Production.set_year(_year);
	Production.set_month(_month);
	Production.set_day(_day);
}
void car::iseat_set_status(int index) {
	int _year, _month, _day;
	string _color, _material;
	cout << "Enter its color:";
	cin >> _color;
	Seat[index].set_s_color(_color);
	cout << "Enter its material:";
	cin >> _material;
	Seat[index].set_material(_material);
	cout << "Enter Year & Month & Day of production:";
	cin >> _year >> _month >> _day;
	Seat[index].set_DATE(_year, _month, _day);
}
void car::iwheel_set_status(int index) {
	int _year, _month, _day;
	cout << "Enter Year & Month & Day of production:";
	cin >> _year >> _month >> _day;
	Wheel[index].set_DATE(_year, _month, _day);
}
void car::iwheel_get_status(int index) { Wheel[index].DATE(); }
void car::iseat_get_status(int index) {
	cout << Seat[index].get_material() << " ";
	Seat[index].DATE();
	cout << " " << Seat[index].get_s_color() << endl;
}