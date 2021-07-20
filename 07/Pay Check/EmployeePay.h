#pragma once

#include "Employee.h"

class EmployeePay:public Employee{
	int annual_payment;
	int weekly_payment;
public:
	EmployeePay();
	int get_annual_payment();
	int get_weekly_payment();
	void set_annual_payment(int _annual_payment);
	~EmployeePay();
};