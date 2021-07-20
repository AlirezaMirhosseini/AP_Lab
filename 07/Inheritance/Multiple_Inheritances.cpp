//   BY   : Shapour Discover
//   DATE : 2021-04-29
//   TIME : 16:25

#include<iostream>

using namespace std;

class A {
	int a;
public:
	void func(int val_a) {
		a = val_a;
		cout << "Now you are in class A, this is value in class A : " << a << endl;
	}
};
class B {
	int b;
public:
	void func(int val_b) {
		b = val_b;
		cout << "Now you are in class B, this is value in class B : " << b << endl;
	}
};
class C {
	int c;
public:
	void func(int val_c) {
		c = val_c;
		cout << "Now you are in class C, this is value in class C : " << c << endl;
	}
};
class D :public A, public B, public C {
	int d;
public:
	void func(int val_d) {
		d = val_d;
		cout << "You are still in class D and your value in class D : " << d << endl;
		A::func(d + 200);
		B::func(d + 400);
		C::func(d + 600);
	}
};

int main() {
	D d1;
	cout << "Enter an integer num : ";
	int num;
	cin >> num;
	d1.func(num);

	return 0;
}