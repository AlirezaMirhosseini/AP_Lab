#include "Polynomial.h"

Polynomial::Polynomial(){
	for (int i = 0; i < 21; i++)
		coefficient[i] = 0;
}
Polynomial::Polynomial(const Polynomial& obj) {
	for (int i = 0; i < 21; i++)
		coefficient[i] = obj.coefficient[i];
}
Polynomial Polynomial::operator-() {
	Polynomial new_obj = *this;
	for (int i = 0; i < 21; i++)
		new_obj.coefficient[i] *= -1;
	return new_obj;
}
Polynomial& Polynomial::operator=(const Polynomial& obj){
	for (int i = 0; i < 21; i++)
		coefficient[i] = obj.coefficient[i];
	return *this;
}
Polynomial& Polynomial::operator++() {
	int deg = 0;
	for (int i = 20; i >= 0; i--)
		if (coefficient[i] != 0) {
			deg = i;
			break;
		}
	for (int i = 0; i <= deg; i++)
		if (coefficient[i] != 0)
			coefficient[i]++;
	return *this;
}
Polynomial& Polynomial::operator++(int) {
	int deg = 0;
	for (int i = 20; i >= 0; i--)
		if (coefficient[i] != 0) {
			deg = i;
			break;
		}
	for (int i = 0; i <= deg; i++)
		if (coefficient[i] != 0)
			coefficient[i]++;
	return *this;
}
Polynomial Polynomial::operator+(const Polynomial& obj) {
	Polynomial new_obj = *this;
	for (int i = 0; i < 21; i++)
		new_obj.coefficient[i] += obj.coefficient[i];
	return new_obj;
}
Polynomial Polynomial::operator+(const int& data) {
	Polynomial new_obj = *this;
	new_obj.coefficient[0] += data;
	return new_obj;
}
Polynomial operator+(const int& data, const Polynomial& obj) {
	Polynomial new_obj = obj;
	new_obj.coefficient[0] += data;
	return new_obj;
}
Polynomial Polynomial::operator-(const Polynomial& obj) {
	Polynomial new_obj = *this;
	for (int i = 0; i < 21; i++)
		new_obj.coefficient[i] -= obj.coefficient[i];
	return new_obj;
}
Polynomial Polynomial::operator-(const int& data) {
	Polynomial new_obj = *this;
	new_obj.coefficient[0] -= data;
	return new_obj;
}
Polynomial operator-(const int& data, const Polynomial& obj) {
	Polynomial new_obj = obj;
	for (int i = 0; i < 21; i++)
		new_obj.coefficient[i] *= -1;
	new_obj.coefficient[0] += data;
	return new_obj;
}
Polynomial Polynomial::operator*(const Polynomial& obj) {
	int deg1 = 0;
	for (int i = 20; i >= 0; i--)
		if (coefficient[i] != 0) {
			deg1 = i;
			break;
		}
	int deg2 = 0;
	for (int i = 20; i >= 0; i--)
		if (obj.coefficient[i] != 0) {
			deg2 = i;
			break;
		}
	Polynomial new_obj;
	int finalDeg = deg1 + deg2;
	for (int i = finalDeg; i >= 0; i--)
		for (int j = deg1; j >= 0; j--)
			for (int k = deg2; k >= 0; k--)
				if (k + j == i) {
					new_obj.coefficient[i] += (coefficient[j] * obj.coefficient[k]);
					break;
				}
	return new_obj;
}
Polynomial Polynomial::operator*(const int& data) {
	Polynomial new_obj = *this;
	for (int i = 0; i < 21; i++)
		new_obj.coefficient[i] *= data;
	return new_obj;
}
Polynomial operator*(const int& data, const Polynomial& obj) {
	Polynomial new_obj = obj;
	for (int i = 0; i < 21; i++)
		new_obj.coefficient[i] *= data;
	return new_obj;
}
ostream& operator<<(ostream& out, Polynomial obj) {
	for (int i = 20; i >= 0; i--)
		if (obj.coefficient[i] != 0) {
			if (obj.coefficient[i] > 0) {
				out << "+";
				if (obj.coefficient[i] == 1 && i == 0) {
					out << obj.coefficient[i];
					continue;
				}
				if (obj.coefficient[i] != 1)
					out << obj.coefficient[i];
				if (i != 0)
					out << "x";
				if (i > 1)
					out << "^" << i;
			}
			else if (obj.coefficient[i] < 0) {
				if (obj.coefficient[i] == -1 && i == 0) {
					out << obj.coefficient[i];
					continue;
				}
				if (obj.coefficient[i] == -1)
					out << "-";
				else
					out << obj.coefficient[i];
				if (i != 0)
					out << "x";
				if (i > 1)
					out << "^" << i;
			}
		}
	out << endl;
	return out;
}
istream& operator>>(istream& in, Polynomial& obj) {
	for (int i = 0; i < 21; i++)
		obj.coefficient[i] = 0;
	string str;
	cout << "Enter the Polynomial : ";
	in >> str;
	int str_len = (int)str.length();
	for (int i = 0; i < str_len; i++) {
		bool negative = false;
		if (str[i] == '-')
			negative = true;
		i++;
		int number = 0;
		if (str[i] == 'x')
			number = 1;
		while (str[i] <= 57 && str[i] >= 48) {
			if (number > 0)
				number *= 10;
			number += str[i] - 48;
			i++;
		}
		if (negative)
			number *= -1;
		if (str[i] == 'x') {
			i++;
			int power = 0;
			if (str[i] == '^') {
				i++;
				while (str[i] <= 57 && str[i] >= 48) {
					if (power > 0)
						power *= 10;
					power += str[i] - 48;
					i++;
				}
			}
			else
				power = 1;
			obj.coefficient[power] += number;
			i--;
		}
		else if (str[i] != 'x') {
			obj.coefficient[0] += number;
			i--;
		}
	}
	return in;
}
Polynomial::~Polynomial(){}