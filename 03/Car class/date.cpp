#include "date.h"


void date::correct_print() {
	cout << year << "/" << month << "/" << day;
}
void date::string_print() {
	string strmonth[12] = { "farvardin","ordibehesht","khordad","tir","mordad","shahrivar","mehr","aban","azar","dey","bahman","esfand" };
	cout << year << " " << strmonth[month - 1] << " " << day << endl;
}
void date::set_year(int _year) { year = _year; }
void date::set_month(int _month) { month = _month; }
void date::set_day(int _day) { day = _day; }