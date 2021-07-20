#include "Professor.h"

int Professor::counter = 0;

Professor::Professor()
{
	publications = 0;
	counter++;
}

void Professor::getdata() {
	cin >> name;
	cin >> age;
	cin >> publications;
	curid = counter;
}
void Professor::putdata() {
	cout << name << " " << age << " " << publications << " " << curid << endl;
}

Professor::~Professor()
{
	counter--;
}