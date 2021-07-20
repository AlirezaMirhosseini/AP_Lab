#include "Library.h"

Library::Library(string _libraryName, string _Address, float _openingHour, float _closingHour, int _foundYear, int _numberOfEmployees, int _numberOfBooks) {
	libraryName = _libraryName;
	Address = _Address;
	openingHour = _openingHour;
	closingHour = _closingHour;
	foundYear = _foundYear;
	numberOfEmployees = _numberOfEmployees;
	numberOfBooks = _numberOfBooks;
	book = new Book[numberOfBooks];
}
Library::Library() {
	string temp = "";
	libraryName = temp;
	Address = temp;
	openingHour = 0;
	closingHour = 0;
	foundYear = 0;
	numberOfEmployees = 0;
	numberOfBooks = 0;
	book = new Book[numberOfBooks];
}
void Library::addBook(string _bookName, int _publishYear, string _authorName, string _authorGender, string _authorEmail) {
	Book newBook(_bookName, _publishYear, _authorName, _authorGender, _authorEmail);
	Book* temp = new Book[numberOfBooks];
	for (int i = 0;i < numberOfBooks;i++) {
		temp[i].setAll(book[i]);
	}
	delete[] book;
	numberOfBooks++;
	book = new Book[numberOfBooks];
	for (int i = 0;i < numberOfBooks - 1;i++) {
		book[i].setAll(temp[i]);
	}
	book[numberOfBooks - 1].setAll(newBook);
	cout << "Book added succesfully.";
}
void Library::bookStatus(string _bookName) {
	for (int i = 0;i < numberOfBooks;i++) {
		if ((book[i].getName() == _bookName) && (!book[i].getStatus())) {
			cout << _bookName << " : There is a book with this name, so you can borrow.\n";
			return;
		}
	}
	cout << _bookName << " : Not found.(there is no book with this name in our list. Maybe it is already borrowed, so you can't borrow.)\n";
}
void Library::borrowBook(string _bookName) {
	for (int i = 0;i < numberOfBooks;i++) {
		if ((book[i].getName() == _bookName) && (!book[i].getStatus())) {
			cout << _bookName << " : There is a book with this name, here you are.\n";
			book[i].setStatus(true);
			return;
		}
	}
	cout << _bookName << " : Not found.(there is no book with this name in our list. Maybe it is already borrowed)\n";
}
void Library::returnBook(string _bookName) {
	for (int i = 0;i < numberOfBooks;i++) {
		if ((book[i].getName() == _bookName) && (book[i].getStatus())) {
			cout << "Thanks for Returning the Book, We hope you've enjoy it.\n";
			book[i].setStatus(false);
			return;
		}
	}
	cout << _bookName << " : Not found.(there is no book with this name in our list. Maybe it hasn't been borrowed yet)\n";
}
void Library::alphabeticalOrder() {
	for (int i = 0;i < numberOfBooks;i++) {
		for (int j = i + 1;j < numberOfBooks;j++) {
			if (book[i].getName().compare(book[j].getName()) > 0) {
				Book temp = book[i];
				book[i] = book[j];
				book[j] = temp;
			}
		}
	}
}
void Library::printList() {
	alphabeticalOrder();
	if (numberOfBooks == 0) {
		cout << "Library is empty!\n";
		return;
	}
	for (int i = 0;i < numberOfBooks;i++) {
		cout << i + 1 << ".Book Name:" << book[i].getName() <<
			" ___ Publish year:" << book[i].getPublishYear() <<
			" ___ Author information:" << book[i].getAuthorName() <<
			" (" << book[i].getAuthorGender() <<
			") at " <<book[i].getAuthorEmail() << endl;
	}
}
void Library::printAuthorBooks(string _AuthorName) {
	alphabeticalOrder();
	int counter = 0;
	for (int i = 0;i < numberOfBooks;i++) {
		if (book[i].getAuthorName().compare(_AuthorName) == 0) {
			cout << counter + 1 << ".Book Name:" << book[i].getName() << endl;
			counter++;
		}
	}
	if (counter == 0)
		cout << "Author:" << _AuthorName << " not found or she/he hasn't written a book yet.\n";
}
void Library::borrowedList() {
	alphabeticalOrder();
	if (numberOfBooks == 0) {
		cout << "Library is empty!\n";
		return;
	}
	int counter = 0;
	for (int i = 0;i < numberOfBooks;i++) {
		if (book[i].getStatus()) {
			cout << counter + 1 << ".Book Name:" << book[i].getName() << endl;
			counter++;
		}
	}
	if (counter == 0)
		cout << "No Books have been borrowed!\n";
}
void Library::notBorrowedList() {
	alphabeticalOrder();
	if (numberOfBooks == 0) {
		cout << "Library is empty!\n";
		return;
	}
	int counter = 0;
	for (int i = 0;i < numberOfBooks;i++) {
		if (!book[i].getStatus()) {
			cout << counter + 1 << ".Book Name:" << book[i].getName() << endl;
			counter++;
		}
	}
	if (counter == 0)
		cout << "All Books have been borrowed!\n";
}
void Library::OpenOrClose(float _hour) {
	if (_hour<openingHour || _hour>closingHour) {
		cout << "Library is Close! (open at " << openingHour << " and close at " << closingHour << ")\n";
		return;
	}
	cout << "Library is Open =). welcome!\n";
}
float Library::getOpenTime() { return openingHour; }
float Library::getCloseTime() { return closingHour; }
int Library::getNumberOfBooks() { return numberOfBooks; }
Library::~Library() { delete[] book; }