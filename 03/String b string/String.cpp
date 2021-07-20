#include "String.h"

String::String() {
	str = new char[0];
	size = 0;
}
String::String(char* _str, int _size) {
	str = new char[size];
	//for
	for (int i = 0;i < size;i++) {
		str[i] = _str[i];
	}
	//str = _str;
	size = _size;
}
String::String(char* _str) {
	int s = 0;
	for (int i = 0;_str[i] != '\0';i++) {
		s++;
	}
	size = s;
	str = new char[size];
	//size
	for (int i = 0;i < size;i++) {
		str[i] = _str[i];
	}
	str[size] = '\0';
	//str = _str;
	//int _size = 0;
	//for (int i = 0;_str[i] != '\0';i++) {
	//	_size++;
	//}
	//size = _size;
}
void String::setStr(char* _str) {
	str = _str;
	int _size = 0;
	for (int i = 0;_str[i] != '\0';i++) {
		_size++;
	}
	setSize(_size);
}
char* String::getStr() { return str; }
void String::setSize(int _size) { size = _size; }
int String::getSize() { return size; }
char* String::subStr(int index1, int index2){
	int sub_len = index2 - index1 + 1;
	char* sub = new char[sub_len+1];
	int t = 0;
	for (int i = index1;i <= index2;i++) {
		sub[t] = str[i];
		t++;
	}
	sub[t] = '\0';
	return sub;
}
void String::append(char* temp) {
	int temp_size = 0;
	for (int i = 0;temp[i] != '\0';i++) {
		temp_size++;
	}
	char* arr_temp = new char[size];
	for (int i = 0;i < size;i++) {
		arr_temp[i] = str[i];
	}
	str = new char[size + temp_size];
	for (int i = 0;i < size;i++) {
		str[i] = arr_temp[i];
	}
	for (int i = 0;temp[i] != '\0';i++) {
		str[size] = temp[i];
		size++;
	}
	str[size] = '\0';
	delete[] arr_temp;
	//str = new char[100];
}
int String::findSubStr(char* temp) {
	int i = 0, j = 0,st=0;
	str[size] = '\0';
	for (int i = 0;temp[i] != '\0';i++) {
		st++;
	}
	for (;str[j] != '\0' && temp[i] != '\0';j++) {
		if (str[j] == temp[i])
			i++;
		else
			i = 0;
	}
	if (temp[i] == '\0')
		return j-st;

	return -1;
}
bool String::strCmp(char* temp) {
	int temp_len = 0;
	for (int i = 0;i < size;i++) 
		if (str[i] == temp[i])
			temp_len++;
	
	if (temp_len == size)
		return true;

	return false;
}
String::~String() {}