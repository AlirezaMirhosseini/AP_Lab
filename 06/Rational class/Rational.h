#pragma once

#include <iostream>
#include <string>

#pragma warning(disable:4996)

using namespace std;

class Rational{
	int numerator;
	int denominator;
	int gcd;
public:
	Rational();
	Rational(int num, int den);
	int GCD(int x, int n);
	int LCM(int a, int b);
	int get_GCD();
	int get_LCM();
	int get_numbrator();
	int get_denominator();
	void simplify(Rational* i);
	Rational operator+(const Rational& _obj);
	Rational operator-(const Rational& _obj);
	Rational operator*(const Rational& _obj);
	Rational operator/(const Rational& _obj);
	int operator>(const Rational& _obj);
	void operator+=(Rational& _obj);
	int operator==(Rational& _obj);
	void operator[](int index);
	~Rational();
};