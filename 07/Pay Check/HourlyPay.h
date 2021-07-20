#pragma once

#include "EmployeePay.h"

class HourlyPay :public EmployeePay {
	int hourly_payment_rate;
	int overtime_payment_rate;
	int worked_hours;
public:
	HourlyPay();
	int get_hourly_payment_rate();
	int get_overtime_payment_rate();
	int get_worked_hours();
	void set_hourly_payment_rate(int _hourly_payment_rate);
	//void set_overtime_payment_rate(int _overtime_payment_rate);
	void set_worked_hours(int _worked_hours);
	~HourlyPay();
};