//   BY   : Shapour Discover
//   DATE : 2021-03-01
//   TIME : 14:38

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GCD : Greatest Common Divisor ____  LCM : Least Common Multiple

#pragma warning (disable:4996)

typedef struct Rational {
    int numbrator;
    int denominator;
	int gcd;
}Rational;

void getRational(Rational* i);
void print(Rational i);
void simplify(Rational* i);
Rational add(Rational q1, Rational q2);
Rational subtract(Rational q1, Rational q2);
Rational multiply(Rational q1, Rational q2);
Rational divide(Rational q1, Rational q2);
void reverse(Rational* i);
int GCD(int x, int n);
int LCM(int a, int b);

int main(){
	Rational Q1, Q2, Q3;

	getRational(&Q1);
	print(Q1);

	getRational(&Q2);
	print(Q2);

	Q3 = add(Q1, Q2);
	print(Q3);

	Q3 = subtract(Q1, Q2);
	print(Q3);

	Q3 = multiply(Q1, Q2);
	print(Q3);

	Q3 = divide(Q1, Q2);
	print(Q3);

	reverse(&Q3);
	print(Q3);

	simplify(&Q3);
	print(Q3);

	return 0;
}
void getRational(Rational* i) {
	printf("Enter the Numbrator : ");
	scanf("%d", &i->numbrator);
	printf("Enter the Denominator : ");
	scanf("%d", &i->denominator);
	i->gcd = GCD(i->numbrator, i->denominator);
}
void print(Rational i) {
	printf("%d/%d\n", i.numbrator, i.denominator);
}
void simplify(Rational* i) {
	i->numbrator /= i->gcd;
	i->denominator /= i->gcd;
}
Rational add(Rational q1, Rational q2) {
	Rational result;
	result.denominator = LCM(q1.denominator, q2.denominator);
	result.numbrator = (q1.numbrator * (LCM(q1.denominator, q2.denominator) / q1.denominator)) + (q2.numbrator * (LCM(q1.denominator, q2.denominator) / q2.denominator));
	result.gcd = GCD(result.numbrator, result.denominator);
	return result;
}
Rational subtract(Rational q1, Rational q2) {
	Rational result;
	result.denominator = LCM(q1.denominator, q2.denominator);
	result.numbrator = (q1.numbrator * (LCM(q1.denominator, q2.denominator) / q1.denominator)) - (q2.numbrator * (LCM(q1.denominator, q2.denominator) / q2.denominator));
	result.gcd = GCD(result.numbrator, result.denominator);
	return result;
}
Rational multiply(Rational q1, Rational q2) {
	Rational result;
	result.numbrator = q1.numbrator * q2.numbrator;
	result.denominator = q1.denominator * q2.denominator;
	result.gcd = GCD(result.numbrator, result.denominator);
	return result;
}
void reverse(Rational* i) {
	int temp = i->numbrator;
	i->numbrator = i->denominator;
	i->denominator = temp;
}
Rational divide(Rational q1, Rational q2) {
	Rational result;
	result.numbrator = q1.numbrator * q2.denominator;
	result.denominator = q1.denominator * q2.numbrator;
	result.gcd = GCD(result.numbrator, result.denominator);
	return result;
}
int GCD(int x, int n) {
	return x % n ? GCD(n, x % n) : n;
}
int LCM(int a, int b) {
	return (a / GCD(a, b)) * b;
}