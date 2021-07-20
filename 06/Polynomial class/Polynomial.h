#pragma once

#include <iostream>
#include <string>

using namespace std;

class Polynomial{
	int coefficient[21];
public:
	Polynomial();
	Polynomial(const Polynomial& obj);
	Polynomial operator-();
	Polynomial& operator=(const Polynomial& obj);
	Polynomial& operator++();
	Polynomial& operator++(int);
	Polynomial operator+(const Polynomial& obj);
	Polynomial operator+(const int& data);
	friend Polynomial operator+(const int& data, const Polynomial& obj);
	Polynomial operator-(const Polynomial& obj);
	Polynomial operator-(const int& data);
	friend Polynomial operator-(const int& data, const Polynomial& obj);
	Polynomial operator*(const Polynomial& obj);
	Polynomial operator*(const int& data);
	friend Polynomial operator*(const int& data, const Polynomial& obj);
	friend ostream& operator<<(ostream& out, Polynomial obj);
	friend istream& operator>>(istream& in, Polynomial& obj);
	~Polynomial();
};