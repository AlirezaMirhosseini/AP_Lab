#pragma once

#include "Person.h"

class Student :public Person
{
	int marks[6];
	static int counter;
	int curid;
public:
	Student();
	void getdata();
	void putdata();
	~Student();
};