//   BY   : Shapour Discover
//   DATE : 2021-03-10
//   TIME : 17:38

#include <iostream>
#include "point.h"

using namespace std;

int main(){
	point obj1(9,12);
	cout << obj1.get_X() << endl << obj1.get_Y() << endl << obj1.get_length() << endl;
	obj1.set_X(16);
	obj1.set_Y(30);
	cout << obj1.get_X() << endl << obj1.get_Y() << endl << obj1.get_length() << endl;
	obj1.set_Coordinate(12,16);
	cout << obj1.get_X() << endl << obj1.get_Y() << endl << obj1.get_length() << endl;
	obj1.print_Coordinate();

	return 0;
}