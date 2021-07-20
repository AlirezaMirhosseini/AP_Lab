#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template <typename T>
class Vector {
private:
	T* arr;
	int Size;
public:
	Vector();
	Vector(Vector& old);
	int SIZE();
	T* get_array();
	void push_back(T data);
	void push_front(T data);
	void insert(int index, T data);
	void pop();
	void Delete(int index);
	int search(T data);
	void Swap(int index1, int index2);
	void reverse();
	void sort();
	void print_list();
	~Vector();
};

