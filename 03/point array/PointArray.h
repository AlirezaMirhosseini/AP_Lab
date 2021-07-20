#pragma once

#include <iostream>
#include "point.h"

using namespace std;

class PointArray {
private:
	int size;
	point* array_pointer;
	void resize(const int n);
public:
	PointArray();
	PointArray(const point points[], const int size2);
	void PushBack(const point& p);
	void insert(const int position, const point& p);
	void remove(const int pos);
	const int getSize() const;
	void clear();
	point* get(const int position);
	const point* get(const int position) const;
	void Print();
	~PointArray();
};
