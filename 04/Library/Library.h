#pragma once

#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

class Library{
private:
	string libraryName;
	string Address;
	float openingHour;
	float closingHour;
	int foundYear;
	int numberOfEmployees;
	Book *book;
	int numberOfBooks;
public:
	Library(string _libraryName, string _Address, float _openingHour, float _closingHour, int _foundYear, int _numberOfEmployees, int _numberOfBooks);
	Library();
	void addBook(string _bookName, int _publishYear, string _authorName, string _authorGender, string _authorEmail);
	void bookStatus(string _bookName);
	void borrowBook(string _bookName);
	void returnBook(string _bookName);
	void alphabeticalOrder();
	void printList();
	void printAuthorBooks(string _AuthorName);
	void borrowedList();
	void notBorrowedList();
	void OpenOrClose(float _hour);
	float getOpenTime();
	float getCloseTime();
	int getNumberOfBooks();
	~Library();
};

