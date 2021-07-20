#pragma once

#include <iostream>

using namespace std;

class String{
private:
	char* str;
	int size;
public:
	String();
	String(char* _str, int _size);
	String(char* _str);
	void setStr(char* _str);
	char* getStr();
	void setSize(int _size);
	int getSize();
	char* subStr(int index1, int index2);
	void append(char* temp);
	int findSubStr(char* temp);
	bool strCmp(char* temp);
	~String();
};