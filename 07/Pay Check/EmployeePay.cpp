#include "EmployeePay.h"

EmployeePay::EmployeePay(){
	annual_payment = 0;
	weekly_payment = 0;
}

int EmployeePay::get_annual_payment() { return annual_payment; }
int EmployeePay::get_weekly_payment() { return weekly_payment; }
void EmployeePay::set_annual_payment(int _annual_payment) {
	if (_annual_payment < 0) {
		cout << "The input for Annual payment is invalid... try again." << endl;
		return;
	}
	annual_payment = _annual_payment;
	weekly_payment = annual_payment / 52;
}

EmployeePay::~EmployeePay(){

}