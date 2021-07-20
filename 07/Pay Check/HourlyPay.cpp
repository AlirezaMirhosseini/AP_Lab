#include "HourlyPay.h"

HourlyPay::HourlyPay(){
	hourly_payment_rate = 0;
	overtime_payment_rate = 0;
	worked_hours = 0;
}

int HourlyPay::get_hourly_payment_rate() { return hourly_payment_rate; }
int HourlyPay::get_overtime_payment_rate() { return overtime_payment_rate; }
int HourlyPay::get_worked_hours() { return worked_hours; }
void HourlyPay::set_hourly_payment_rate(int _hourly_payment_rate) {
	if (_hourly_payment_rate <= 0) {
		cout << "The input Hourly payment rate is invalid... try again." << endl;
		return;
	}
	hourly_payment_rate = _hourly_payment_rate;
	overtime_payment_rate = 3 * hourly_payment_rate / 2;
}
//void HourlyPay::set_overtime_payment_rate(int _overtime_payment_rate) {}
void HourlyPay::set_worked_hours(int _worked_hours) {
	if (_worked_hours > 60) {
		cout << "The input for Worked hours is invalid... try again." << endl;
		return;
	}
	worked_hours = _worked_hours;
}

HourlyPay::~HourlyPay(){

}