//   BY   : Shapour Discover
//   DATE : 2021-03-20
//   TIME : 23:38

#include "String.h"

//String s[200];

int main() {
	cout << boolalpha;
	int op, counter = -1, _size;
	String s1;
	do{
		counter++;
		cout << "\n\nWhat do you want to do? (Enter number of your option)\n";
		cout << "1.Create a new string with its size\n";
		cout << "2.Create a new string without its size\n";
		cout << "3.Set new string\n";
		cout << "4.Get the string\n";
		cout << "5.Set new size\n";
		cout << "6.Get the size\n";
		cout << "7.Get a Substring\n";
		cout << "8.Append a string to yours\n";
		cout << "9.Find index of a substring\n";
		cout << "10.Compare two strings\n";
		cout << "0.Exit\n";
		cout << "\nInput:";
		cin >> op;
		if (op == 1) {
			//int _size;
			char* pr = new char[200];
			cout << "Enter string:";
			cin >> pr;
			cout << "Enter its size:";
			cin >> _size;
			s1.setStr(pr);
			s1.setSize(_size);
			//String s1(pr, _size);
		}
		else if (op == 2) {
			char* pr0 = new char[200];
			cout << "Enter string:";
			cin >> pr0;
			s1.setStr(pr0);
			//String s1(pr);
		}
		else if (op == 3) {
			char* pr1 = new char[200];
			cout << "Enter string:";
			cin >> pr1;
			s1.setStr(pr1);
		}
		else if (op == 4) {
			cout << s1.getStr() << endl;
		}
		else if (op == 5) {
			cin >> _size;
			s1.setSize(_size);
		}
		else if (op == 6) {
			cout << s1.getSize() << endl;
		}
		else if (op == 7) {
			int i1, i2;
			cout << "Enter two indexes:";
			cin >> i1 >> i2;
			cout << s1.subStr(i1, i2) << endl;
		}
		else if (op == 8) {
			char* pr2 = new char[100];
			cout << "Enter your string:";
			cin >> pr2;
			s1.append(pr2);
			cout << "The new string:" << s1.getStr() << endl;
		}
		else if (op == 9) {
			char* pr3 = new char[100];
			cout << "Enter a substring:";
			cin >> pr3;
			cout << s1.findSubStr(pr3) << endl;
		}
		else if (op == 10) {
			char* pr4 = new char[100];
			cout << "Enter a string:";
			cin >> pr4;
			cout << s1.strCmp(pr4) << endl;
		}
	} while (op != 0);

	//char* ptr = new char[100];
	//cin >> ptr;
	//String s1(ptr);
	////s1.setStr(ptr);
	//cout << s1.getStr() << endl;
	//cout << s1.getSize() << endl;
	////cout << "Enter indexes:";
	////int i1, i2;
	////cin >> i1 >> i2;
	////cout << s1.subStr(i1, i2) << endl;
	//char* ptr1 = new char[100];
	//cin >> ptr1;
	////s1.append(ptr1);
	////cout << s1.getStr() << endl;
	////cout << s1.findSubStr(ptr1) << endl;
	//cout << s1.strCmp(ptr1) << endl;

	return 0;
}