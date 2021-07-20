#include "seat.h"

void seat::set_s_color(string _s_color) { s_color = _s_color; }
void seat::set_material(string _material) { material = _material; }
string seat::get_s_color() { return s_color; }
string seat::get_material() { return material; }
void seat::DATE() { prdct_date.correct_print(); }
void seat::set_DATE(int _year, int _month, int _day) {
	prdct_date.set_year(_year);
	prdct_date.set_month(_month);
	prdct_date.set_day(_day);
}