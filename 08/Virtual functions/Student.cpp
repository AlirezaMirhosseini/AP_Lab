#include "Student.h"

int Student::counter = 0;

Student::Student()
{
	for (int i = 0; i < 6; i++)
		marks[i] = 0;
	counter++;
}

void Student::getdata() {
	curid = counter;
	cin >> name;
	cin >> age;
	for (int i = 0; i < 6; i++)
		cin >> marks[i];
}
void Student::putdata() {
	int sum = 0;
	for (int i = 0; i < 6; i++)
		sum += marks[i];
	cout << name << " " << age << " " << sum << " " << curid << endl;
}

Student::~Student()
{
	counter--;
}