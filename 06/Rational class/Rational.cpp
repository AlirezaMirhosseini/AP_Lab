#include "Rational.h"

Rational::Rational(){
	numerator = 0;
	denominator = 0;
	gcd = 0;
}
Rational::Rational(int num, int den) {
	numerator = num;
	denominator = den;
	gcd = GCD(num, den);
}
int Rational::GCD(int x, int n) { return x % n ? GCD(n, x % n) : n; }
int Rational::LCM(int a, int b) { return (a / GCD(a, b)) * b; }
int Rational::get_GCD() { return gcd; }
int Rational::get_LCM() { return LCM(numerator, denominator); }
int Rational::get_numbrator() { return numerator; }
int Rational::get_denominator() { return denominator; }
void Rational::simplify(Rational* _obj) {
	_obj->gcd = GCD(_obj->numerator, _obj->denominator);
	_obj->numerator /= _obj->gcd;
	_obj->denominator /= _obj->gcd;
}
Rational Rational::operator+(const Rational& _obj) {
	int new_den = LCM(denominator, _obj.denominator);
	int new_num = (numerator * new_den) / denominator + (_obj.numerator * new_den) / _obj.denominator;
	Rational new_obj(new_num, new_den);
	simplify(&new_obj);
	return new_obj;
}
Rational Rational::operator-(const Rational& _obj) {
	int new_den = LCM(denominator, _obj.denominator);
	int new_num = (numerator * new_den) / denominator - (_obj.numerator * new_den) / _obj.denominator;
	Rational new_obj(new_num, new_den);
	simplify(&new_obj);
	return new_obj;
}
Rational Rational::operator*(const Rational& _obj) {
	int new_den = denominator * _obj.denominator;
	int new_num = numerator * _obj.numerator;
	Rational new_obj(new_num, new_den);
	simplify(&new_obj);
	return new_obj;
}
Rational Rational::operator/(const Rational& _obj) {
	int new_den = denominator * _obj.numerator;
	int new_num = numerator * _obj.denominator;
	Rational new_obj(new_num, new_den);
	simplify(&new_obj);
	return new_obj;
}
int Rational::operator>(const Rational& _obj) {
	if ((this->numerator * _obj.denominator) > (this->denominator * _obj.numerator))
		return 1;
	return 0;
}
void Rational::operator+=(Rational& _obj) {
	int new_den = LCM(denominator, _obj.denominator);
	int new_num = (numerator * new_den) / denominator + (_obj.numerator * new_den) / _obj.denominator;
	numerator = new_num;
	denominator = new_den;
	gcd = GCD(numerator, denominator);
	simplify(this);
	simplify(&_obj);
	cout << numerator << "/" << denominator << endl <<
		_obj.numerator << "/" << _obj.denominator << endl;
}
int Rational::operator==(Rational& _obj) {
	simplify(this);
	simplify(&_obj);
	if (this->numerator == _obj.numerator && this->denominator == _obj.denominator)
		return 1;
	return 0;
}
void Rational::operator[](int index) {
	if (index == 0)
		cout << numerator << endl;
	else if (index == 1)
		cout << denominator << endl;
}
Rational::~Rational(){}