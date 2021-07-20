#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template <typename T>
class Vector_plus{
private:
	T* arr;
	int Size;
public:
	Vector_plus();
	Vector_plus(const Vector_plus<T>& old);
	int SIZE();
	void set_size(int _size);
	T* get_array();
	void set_array(T* Array);
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
	Vector_plus<T>& operator=(const Vector_plus<T>& old_obj);
	T& operator[](int index);
	Vector_plus<T> operator+(const Vector_plus<T>& _obj);
	Vector_plus<T> operator+(const T& data);
	template <typename T>
	friend Vector_plus<T> operator+(const T& data, Vector_plus<T>& _obj);
	Vector_plus<T>& operator+=(const Vector_plus<T>& _obj);
	Vector_plus<T>& operator+=(const T& data);
	bool operator==(const Vector_plus<T>& _obj);
	template <typename T>
	friend ostream& operator<<(ostream& out, Vector_plus<T>& _obj);
	~Vector_plus();
};