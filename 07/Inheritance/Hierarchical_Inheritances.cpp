//   BY   : Shapour Discover
//   DATE : 2021-04-29
//   TIME : 16:25

#include <iostream>
#include <string>

using namespace std;

class A {
	int rollno;
	string name;
public:
	void func(int val_a) {
		rollno = val_a;
		name = to_string(val_a + 1000);
		cout << "Now you are in class A and your rollno is : " <<
			rollno << " and name is rollno + 1000 , here you can see it " <<
			name << endl;
	}
};
class B :public A {
	int rank_med;
public:
	void func(int val_b) {
		rank_med = val_b;
		cout << "Now you are in class B and your rank_med is : " << rank_med << endl;
		A::func(rank_med + 200);
	}
};
class C :public A {
	int rank_engg;
public:
	void func(int val_c) {
		rank_engg = val_c;
		cout << "Now you are in class C and your rank_engg is : " << rank_engg << endl;
		A::func(rank_engg + 300);
	}
};
class D :public A{
	int rank_biotech;
public:
	void func(int val_d) {
		rank_biotech = val_d;
		cout << "Now you are in class D and your rank_biotech is : " << rank_biotech << endl;
		A::func(rank_biotech + 500);
	}
};

int main() {
	B b1;
	cout << "Enter an integer num for class B : ";
	int num_B;
	cin >> num_B;
	C c1;
	cout << "Enter an integer num for class C : ";
	int num_C;
	cin >> num_C;
	D d1;
	cout << "Enter an integer num for class D : ";
	int num_D;
	cin >> num_D;
	cout << "---------------------\n\n";
	b1.func(num_B);
	cout << "---------------------\n\n";
	c1.func(num_C);
	cout << "---------------------\n\n";
	d1.func(num_D);
	cout << "---------------------\n\n";

	return 0;
}