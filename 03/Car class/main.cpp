//   BY   : Shapour Discover
//   DATE : 2021-03-20
//   TIME : 15:40

#include <iostream>
#include "car.h"

using namespace std;

car c_obj[100];

int main() {
	int counter = -1;
	int option;
	int ts, tw, y, m, d;
	string cc;
	do {
		counter++;
		cout << "What do you want to do? (enter number of option)\n";
		cout << "1.Enter a Car\n";
		cout << "0.Exit\n";
		cin >> option;
		if (option == 1) {
			cout << "Enter color of car:";
			cin >> cc;
			c_obj[counter].set_c_color(cc);
			cout << "Enter count of wheels:";
			cin >> tw;
			c_obj[counter].set_wheels(tw);
			cout << "Enter count of seats:";
			cin >> ts;
			c_obj[counter].set_seats(ts);
			cout << "Enter Year & Month & Day of production:";
			cin >> y >> m >> d;
			c_obj[counter].set_DATE(y, m, d);
			cout << "Now wheels:))\n";
			for (int i = 0;i < c_obj[counter].get_wheels();i++) {
				c_obj[counter].iwheel_set_status(i);
			}
			cout << "Now seats:))\n";
			for (int i = 0;i < c_obj[counter].get_seats();i++) {
				c_obj[counter].iseat_set_status(i);
			}
			cout << c_obj[counter].get_c_color() << " ";
			c_obj[counter].DATE();
			cout << c_obj[counter].get_wheels() << endl;
			for (int i = 0;i < c_obj[counter].get_wheels();i++) {
				c_obj[counter].iwheel_get_status(i);
				cout << endl;
			}
			cout << c_obj[counter].get_seats() << endl;
			for (int i = 0;i < c_obj[counter].get_seats();i++) {
				c_obj[counter].iseat_get_status(i);
			}
			cout << "\n\nThe next one:\n\n";
		}
	} while (option != 0);
	//car c1;
	//int ts, tw, y, m, d;
	//string cc;
	//cout << "Enter color of car:";
	//cin >> cc;
	//c1.set_c_color(cc);
	//cout << "Enter count of wheels:";
	//cin >> tw;
	//c1.set_wheels(tw);
	//cout << "Enter count of seats:";
	//cin >> ts;
	//c1.set_seats(ts);
	//cout << "Enter Year & Month & Day of production:";
	//cin >> y >> m >> d;
	//c1.set_DATE(y, m, d);
	//cout << "Now wheels:))\n";
	//for (int i = 0;i < c1.get_wheels();i++) {
	//	c1.iwheel_set_status(i);
	//}
	//cout << "Now seats:))\n";
	//for (int i = 0;i < c1.get_seats();i++) {
	//	c1.iseat_set_status(i);
	//}
	//cout << c1.get_c_color() << " ";
	//c1.DATE();
	//cout << c1.get_wheels() << endl;
	//for (int i = 0;i < c1.get_wheels();i++) {
	//	c1.iwheel_get_status(i);
	//	cout << endl;
	//}
	//cout << c1.get_seats() << endl;
	//for (int i = 0;i < c1.get_seats();i++) {
	//	c1.iseat_get_status(i);
	//}

	return 0;
}