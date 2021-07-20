#pragma once

#include <iostream>
#include <string>
using namespace std;

template <typename T, typename Y>
class uniquePairs{
	T* Key;
	Y* Value;
	int Size;
public:
	uniquePairs();
	uniquePairs(const uniquePairs<T, Y>&obj);
	void insert(T _Key, Y _Value);
	void remove(T _Key);
	int SIZE();
	uniquePairs<T, Y> operator=(const uniquePairs<T, Y>& obj);
	Y operator[](T _Key) const;
	Y& operator[](T _Key);
	uniquePairs<T, Y> operator-(const uniquePairs<T, Y>& _obj);
	template <typename T, typename Y>
	friend ostream& operator<<(ostream& out, const uniquePairs<T, Y>& _obj);
	~uniquePairs();
};