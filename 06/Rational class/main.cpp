//   BY   : Shapour Discover
//   DATE : 2021-04-20
//   TIME : 14:01

#include "Rational.h"

int main() {
	int first_numerator, first_denominator, second_numerator, second_denominator;

	cout << "First Rational:";
	scanf("%d/%d", &first_numerator, &first_denominator);

	cout << "Second Rational:";
	scanf("%d/%d", &second_numerator, &second_denominator);

	Rational r1(first_numerator, first_denominator);
	Rational r2(second_numerator, second_denominator);

	int counter;
	cout << "Enter number of commands:";
	cin >> counter;
	string* command = new string[counter];
	cout << "Enter commands:" << endl;
	for (int i = 0; i < counter; i++) {
		cin >> command[i];
		if (command[i] == "+") {
			Rational r_new = r1 + r2;
			cout << r_new.get_numbrator() << "/" << r_new.get_denominator() << endl;
		}
		else if (command[i] == "-") {
			Rational r_new = r1 - r2;
			cout << r_new.get_numbrator() << "/" << r_new.get_denominator() << endl;
		}
		else if (command[i] == "*") {
			Rational r_new = r1 * r2;
			cout << r_new.get_numbrator() << "/" << r_new.get_denominator() << endl;
		}
		else if (command[i] == "/") {
			Rational r_new = r1 / r2;
			cout << r_new.get_numbrator() << "/" << r_new.get_denominator() << endl;
		}
		else if (command[i] == "==")
			cout << (r1 == r2) << endl;
		else if (command[i] == ">")
			cout << (r1 > r2) << endl;
		else if (command[i] == "+=")
			r1 += r2;
		else if (command[i][1] == '[' && command[i][3] == ']') {
			if (command[i][0] == '1')
				r1[command[i][2] - 48];
			else if (command[i][0] == '2')
				r2[command[i][2] - 48];
		}
	}

	return 0;
}