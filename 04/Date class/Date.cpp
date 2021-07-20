#include "Date.h"

Date::Date(int _year, int _month, int _day) {
	year = _year;
	month = _month;
	day = _day;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Date::SetDate(int _year, int _month, int _day) {
	int monthDayCount[12]= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (IsLeapYear(_year))
		monthDayCount[1]++;
	if (_year > 9999 || _year < 1973) {
		cout << "Error: Invalid year (1753-9999)!\n";
		return;
	}
	else if (_month < 1 || _month>12) {
		cout << "Error: Invalid month (1-12)!\n";
		return;
	}
	else if (_day<1 || _day>monthDayCount[_month - 1]) {
		cout << "Error: Invalid day! your input is: " << _day << " but last day of month is : " << monthDayCount[_month - 1] << endl;
		return;
	}
	else {
		year = _year;
		month = _month;
		day = _day;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Date::SetYear(int _year) {
	if (_year > 9999 || _year < 1973) {
		cout << "Error: Invalid year (1973-9999)!\n";
		return;
	}
	else 
		year = _year;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Date::GetYear() { return year; }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Date::SetMonth(int _month) {
	if (_month < 1 || _month>12) {
		cout << "Error: Invalid month (1-12)!\n";
		return;
	}
	else 
		month = _month;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Date::GetMonth() { return month; }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Date::SetDay(int _day) {
	int monthDayCount[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (IsLeapYear(year))
		monthDayCount[1]++;
	if (_day<1 || _day>monthDayCount[month - 1]) {
		cout << "Error: Invalid day! your input is: " << _day << " but last day of month is : " << monthDayCount[month - 1] << endl;
		return;
	}
	else 
		day = _day;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Date::Print() {
	string weekdays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	string month_str[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	cout << weekdays[GetDayOfWeek(year, month, day)] << ", " << day << " " << month_str[month - 1] << " " << year << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Date& Date::NextDay() {
	int monthDayCount[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (IsLeapYear(year))
		monthDayCount[1]++;
	day++;
	if (day == monthDayCount[month - 1] + 1) {
		month++;
		day = 1;
	}
	if (month == 13) {
		year++;
		month = 1;
	}
	if (year > 9999) {
		day = 31;
		month = 12;
		year = 9999;
		cout << "Error: Next day is out of range!\n";
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Date& Date::PreviousDay() {
	int monthDayCount[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (IsLeapYear(year))
		monthDayCount[1]++;
	day--;
	if (day == 0) 
		month--;
	if (month == 0) {
		year--;
		month = 12;
	}
	if (day == 0) {
		day = monthDayCount[month - 1];
	}
	if (year < 1973) {
		year = 1973;
		month = 1;
		day = 1;
		cout << "Error: Previous day is out of range!\n";
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Date& Date::NextMonth() {
	int monthDayCount[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (IsLeapYear(year))
		monthDayCount[1]++;
	month++;
	if (month == 13) {
		year++;
		month = 1;
	}
	if (monthDayCount[month - 1] < day)
		day = monthDayCount[month - 1];
	if (year > 9999) {
		month = 12;
		year = 9999;
		cout << "Error: Next month is out of range!\n";
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Date& Date::PreviousMonth() {
	int monthDayCount[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (IsLeapYear(year))
		monthDayCount[1]++;
	month--;
	if (month == 0) {
		year--;
		month = 12;
	}
	if (monthDayCount[month - 1] < day)
		day = monthDayCount[month - 1];
	if (year < 1973) {
		year = 1973;
		month = 1;
		cout << "Error: Previous month is out of range!\n";
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Date& Date::NextYear() {
	if (IsLeapYear(year) && month == 2 && day == 29) {
		day--;
	}
	year++;
	//if (!IsValidDate(year, month, day)) {
	//	day--;
	//}
	if (year > 9999) {
		year = 9999;
		cout << "Error: Next year is out of range!\n";
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Date& Date::PreviousYear() {
	if (IsLeapYear(year) && month == 2 && day == 29) {
		day--;
	}
	year--;
	//if (!IsValidDate(year, month, day)) {
	//	day--;
	//}
	if (year < 1973) {
		year = 1973;
		cout << "Error: Previous year is out of range!\n";
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Date::IsLeapYear(int _year){
	if (_year % 400 == 0 || (_year % 4 == 0) && (_year % 100 != 0))
		return true;
	return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Date::IsValidDate(int _year, int _month, int _day) {
	int monthDayCount[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (IsLeapYear(_year))
		monthDayCount[1]++;
	if (_year > 9999 || _year < 1973)
		return false;
	
	else if (_month < 1 || _month>12)
		return false;
	
	else if (_day<1 || _day>monthDayCount[_month - 1])
		return false;
	
	else
		return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Date::GetDayOfWeek(int _year, int _month, int _day) {
	int monthDayCount[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (IsLeapYear(_year))
		monthDayCount[1]++;
	int days = 0;
	for (int i = 1973;i < _year;i++) {
		if (IsLeapYear(i)) 
			days += 366;
		else 
			days += 365;
	}
	for (int i = 1;i <= 12;i++) {
		if (_month == i) {
			for (int j = 0;j < i - 1;j++)
				days += monthDayCount[j];
			break;
		}
	}
	days += _day;
	return days % 7;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Date::PrintDayOfWeek(int _year, int _month, int _day){
	string weekdays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	string month_str[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	cout << weekdays[GetDayOfWeek(_year, _month, _day)] << ", " << _day << " " << month_str[_month - 1] << " " << _year << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////