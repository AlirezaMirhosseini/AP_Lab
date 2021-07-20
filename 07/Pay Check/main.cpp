//   BY   : Shapour Discover
//   DATE : 2021-05-03
//   TIME : 02:19

#include "HourlyPay.h"

void PrintCheck(HourlyPay hourly_pay) {
	int sal = 0;
	if (hourly_pay.get_worked_hours() > 40)
		sal = hourly_pay.get_worked_hours() * hourly_pay.get_overtime_payment_rate();// *30;
	else
		sal = hourly_pay.get_worked_hours() * hourly_pay.get_hourly_payment_rate();// *30;

	cout << " \nThis is your Pay Check :)\n\n";
	cout << " <---------------------------------------------------------------------------------------------->" << endl;
	cout << " ||                                 $$$$    In the name of god    $$$$" << endl;
	cout << " ||" << endl;
	cout << " ||  Name : " << hourly_pay.get_name() << "                          Social Security Number : " << hourly_pay.get_social_security_number() << endl;
	cout << " ||" << endl;
	cout << " ||  Employee Number : " << hourly_pay.get_employee_number() << endl;
	cout << " ||" << endl;
	cout << " ||  You worked " << hourly_pay.get_worked_hours() << " hours" << endl;
	cout << " ||" << endl;
	cout << " ||  Your Annual payment = " << hourly_pay.get_annual_payment() << endl;
	cout << " ||" << endl;
	cout << " ||  Your Weekly payment = " << hourly_pay.get_weekly_payment() << endl;
	cout << " ||" << endl;
	cout << " ||  Hourly payment rate = " << hourly_pay.get_hourly_payment_rate() << endl;
	cout << " ||  Overtime payment rate = " << hourly_pay.get_overtime_payment_rate() << endl;
	cout << " ||" << endl;
	cout << " ||  This is your weekly salary ---> Check amount = " << sal << "    that means you will earn " << sal * 4 << " in a month" << endl;
	cout << " <---------------------------------------------------------------------------------------------->" << endl;
}

/*
Alireza Mirhosseini
400-80-007
828-A
60000
30
40
*/

int main() {
	HourlyPay hourly_pay;
	string str;
	int num;
	cout << "-----------------------------------------------------------------------------\n";
	cout << "Enter your Name : ";
	getline(cin, str);
	hourly_pay.set_name(str);
	cout << "-----------------------------------------------------------------------------\n";
	cout << "Enter your Social Security Number : ";
	cin >> str;
	hourly_pay.set_social_security_number(str);
	cout << "-----------------------------------------------------------------------------\n";
	cout << "Enter your Employee Number : ";
	cin >> str;
	hourly_pay.set_employee_number(str);
	cout << "-----------------------------------------------------------------------------\n";
	cout << "Enter your Annual payment : ";
	cin >> num;
	hourly_pay.set_annual_payment(num);
	cout << "-----------------------------------------------------------------------------\n";
	cout << "Enter your Hourly payment rate : ";
	cin >> num;
	hourly_pay.set_hourly_payment_rate(num);
	cout << "-----------------------------------------------------------------------------\n";
	cout << "How many hours have you worked in this week? : ";
	cin >> num;
	hourly_pay.set_worked_hours(num);
	cout << "-----------------------------------------------------------------------------\n";
	PrintCheck(hourly_pay);
	return 0;
}