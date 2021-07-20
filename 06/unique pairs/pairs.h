#pragma once

#include <iostream>
#include <string>
using namespace std;

template <typename T, typename Y>
class pairs{
	T* Key;
	Y* Value;
	int Size;
public:
	pairs();
	pairs(const pairs<T, Y>& obj);
	void insert(T _Key, Y _Value);
	void remove(T _Key);
	int SIZE();
	pairs<T, Y> operator=(const pairs<T, Y>& obj);
	Y operator[](T _Key) const;
	Y& operator[](T _Key);
	pairs<T, Y> operator-(const pairs<T, Y>& _obj);
	template <typename T, typename Y>
	friend ostream& operator<<(ostream& out, const pairs<T, Y>& _obj);
	~pairs();
};