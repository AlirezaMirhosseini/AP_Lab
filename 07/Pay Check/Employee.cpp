#include "Employee.h"

Employee::Employee(){
	name = "??????????";
	social_security_number = "000-00-000";
	employee_number = "000-?";
}

string Employee::get_name() { return name; }
string Employee::get_social_security_number() { return social_security_number; }
string Employee::get_employee_number() { return employee_number; }
void Employee::set_name(string _name) { name = _name; }
void Employee::set_social_security_number(string _social_security_number) {
	if ((_social_security_number.length() != 10) || 
		(_social_security_number[3] != '-')||(_social_security_number[6] != '-') ||
		(_social_security_number[0] > 57 || _social_security_number[0] < 48) ||
		(_social_security_number[1] > 57 || _social_security_number[1] < 48) ||
		(_social_security_number[2] > 57 || _social_security_number[2] < 48) ||
		(_social_security_number[4] > 57 || _social_security_number[4] < 48) ||
		(_social_security_number[5] > 57 || _social_security_number[5] < 48) ||
		(_social_security_number[7] > 57 || _social_security_number[7] < 48) ||
		(_social_security_number[8] > 57 || _social_security_number[8] < 48) ||
		(_social_security_number[9] > 57 || _social_security_number[9] < 48)) {
		cout << "The input for Social Security Number is invalid... try again." << endl;
		return;
	}
	social_security_number = _social_security_number;
}
void Employee::set_employee_number(string _employee_number) {
	if ((_employee_number.length() != 5) ||
		(_employee_number[3] != '-') ||
		(_employee_number[0] > 57 || _employee_number[0] < 48) ||
		(_employee_number[1] > 57 || _employee_number[1] < 48) ||
		(_employee_number[2] > 57 || _employee_number[2] < 48) ||
		(_employee_number[4] > 77 || _employee_number[4] < 65)) {
		cout << "The input for Employee Number is invalid... try again." << endl;
		return;
	}
	employee_number = _employee_number;
}

Employee::~Employee(){

}