#pragma once

#include <iostream>
#include <string>

using namespace std;

class Employee{
	string name;
	string social_security_number;
	string employee_number;
public:
	Employee();
	string get_name();
	string get_social_security_number();
	string get_employee_number();
	void set_name(string _name);
	void set_social_security_number(string _social_security_number);
	void set_employee_number(string _employee_number);
	~Employee();
};