//   BY   : Shapour Discover
//   DATE : 2021-04-29
//   TIME : 16:25

#include <iostream>
#include <string>

using namespace std;

class A {
	int rollno;
	string name;
	string branch;
public:
	void func(int val) {
		rollno = val;
		val += 200;
		name = to_string(val);
		val += 200;
		branch = to_string(val);
		cout << "Now it is class A and rollno is " <<
			rollno << " , name is " << name <<
			" , branch is " << branch << endl;
	}
};
class B {
	string city;
	string state;
	int pin;
public:
	void func(int val) {
		pin = val;
		val += 300;
		city = to_string(val);
		val += 300;
		state = to_string(val);
		cout << "Now it is class B and pin is " <<
			pin << " , city is " << city <<
			" , state is " << state << endl;
	}
};
class C:public A {
	float height;
	float weight;
public:
	void func(float val) {
		height = val;
		weight = val + 500;
		cout << "Here is class C , height is " << height <<
			" and weight is " << weight << endl;
		A::func((int)val);
	}
};
class D:public C,public B {
	string game_name;
public:
	void func(int val) {
		game_name = to_string(val);
		cout << "You are still in class D and game name is " << game_name << endl;
		C::func((float)val);
		B::func(val);
	}
};
int main() {
	D d1;
	int num;
	cout << "Enter a number : ";
	cin >> num;
	d1.func(num);

	return 0;
}