#pragma once

#include "Person.h"

class Professor :public Person
{
	int publications;
	static int counter;
	int curid;
public:
	Professor();
	void getdata();
	void putdata();
	~Professor();
};