#pragma once

#include <iostream>
#include <string>

using namespace std;

class Book{
private:
	string bookName;
	int publishYear;
	bool inUse;
	string authorName;
	string authorGender;
	string authorEmail;
public:
	Book(string _bookName, int _publishYear, string _authorName, string _authorGender, string _authorEmail);
	Book();
	void setAll(Book _book);
	string getName();
	bool getStatus();
	void setStatus(bool _status);
	int getPublishYear();
	string getAuthorName();
	string getAuthorGender();
	string getAuthorEmail();
};