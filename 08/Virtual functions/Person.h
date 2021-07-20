#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
	string name;
	int age;
public:
	Person();
	virtual void getdata() { return; }
	virtual void putdata() { return; }
	~Person();
};