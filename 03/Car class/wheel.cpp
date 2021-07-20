#include "wheel.h"


void wheel::DATE() { prdct_date.correct_print(); }
void wheel::set_DATE(int _year, int _month, int _day) {
	prdct_date.set_year(_year);
	prdct_date.set_month(_month);
	prdct_date.set_day(_day);
}