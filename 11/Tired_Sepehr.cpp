//   BY   : Shapour Discover
//   DATE : 2021-06-12
//   TIME : 04:49

#include <iostream>
#include <exception>
#include <string>

using namespace std;

bool IsLeapYear(int _year) {
	if (_year % 400 == 0 || (_year % 4 == 0) && (_year % 100 != 0))
		return true;
	return false;
}
class DateTimeException : public exception {
	int var;
	string desc;
public:
	DateTimeException(int _var, string _desc) {
		var = _var;
		desc = _desc;
	}
	int get_var() { return var; }
	string What() { return desc; }
};
class TimeException : public exception {
	int var;
	string desc;
public:
	TimeException(int _var, string _desc) {
		var = _var;
		desc = _desc;
	}
	int get_var() { return var; }
	string What() { return desc; }
};
class Time { 
	int minute;
	int hour;
public:
	Time() {
		minute = 0;
		hour = 0;
	}
	Time(int _minute, int _hour) {
		try {
			if (_minute < 0 || _minute>59)
				throw TimeException(_minute, "Invalid input for minute!");
		}
		catch(TimeException te){
			cout << te.get_var() << " : " << te.What() << endl;
			if (te.get_var() < 0)
				_minute = 0;
			else if (te.get_var() > 59)
				_minute = 59;
		}
		try {
			if (_hour < 0 || _hour>23)
				throw DateTimeException(_hour, "Invalid input for hour!");
		}
		catch (DateTimeException dte) {
			cout << dte.get_var() << " : " << dte.What() << endl;
			if (dte.get_var() < 0)
				_hour = 0;
			else if (dte.get_var() > 23)
				_hour = 23;
		}
		minute = _minute;
		hour = _hour;
	}
	int get_min() { return minute; }
	int get_hour() { return hour; }
};
class DateException : public exception {
	int var;
	string desc;
public:
	DateException(int _var, string _desc) {
		var = _var;
		desc = _desc;
	}
	int get_var() { return var; }
	string What() { return desc; }
};
class Date {
	int day;
	int month;
	int year;
public:
	Date() {
		day = 1;
		month = 1;
		year = 1;
	}
	Date(int _day, int _month, int _year) {
		int monthDayCount[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (IsLeapYear(_year))
			monthDayCount[1]++;
		try {
			if (_month > 12 || _month < 1) {
				string oor = to_string(_month);
				oor += " : Invalid input for month!";
				if (_month < 1)
					_month = 1;
				else 
					_month = 12;
				throw out_of_range(oor);
			}
		}
		catch (out_of_range oor) {
			cout << oor.what() << endl;
		}
		try {
			if (_day<1 || _day>monthDayCount[_month - 1])
				throw _day;
		}
		catch (int d) {
			cout << _day << " : Invalid input for day!" << endl;
			if (_day < 1)
				_day = 1;
			else if (_day > monthDayCount[_month - 1])
				_day = monthDayCount[_month - 1];
		}
		try {
			if (_year < 0)
				throw DateException(_year, "Invalid input for year!");
		}
		catch (DateException de) {
			cout << _year << " : Invalid input for year!" << endl;
			_year = 1 ;
		}
		day = _day;
		month = _month; 
		year = _year;
	}
	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }
};
class DateTime {
	Time t;
	Date d;
public:
	DateTime() {
		t = Time(0, 0);
		d = Date(1, 1, 1);
	}
	DateTime(int _min,int _hour,int _day,int _mon,int _year) {
		t = Time(_min, _hour);
		d = Date(_day, _mon, _year);
	}
	Time get_time() { return t; }
	Date get_date() { return d; }
};
int main() {
	int min, hour, day, mon, year;
	cout << " Enter minute : ";
	cin >> min;
	cout << " Enter hour   : ";
	cin >> hour;
	cout << " Enter day    : ";
	cin >> day;
	cout << " Enter month  : ";
	cin >> mon;
	cout << " Enter year   : ";
	cin >> year;
	try {
		DateTime dt(min, hour, day, mon, year);
		cout << " Time ==> " << dt.get_time().get_hour() << ":" <<
			dt.get_time().get_min() <<
			"          Date ==> " <<
			dt.get_date().get_year() <<
			"-" << dt.get_date().get_month() <<
			"-" << dt.get_date().get_day() << endl;
	}
	catch (DateTimeException dte) {
		cout << dte.get_var() << " : " << dte.What() << endl;
	}
	return 0;
}