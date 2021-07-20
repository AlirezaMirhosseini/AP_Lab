#include "Book.h"

Book::Book(string _bookName, int _publishYear, string _authorName, string _authorGender, string _authorEmail) {
	bookName = _bookName;
	publishYear = _publishYear;
	inUse = false;
	authorName = _authorName;
	authorGender = _authorGender;
	authorEmail = _authorEmail;
}
Book::Book() {
	string temp = "";
	bookName = temp;
	publishYear = 0;
	inUse = false;
	authorName = temp;
	authorGender = temp;
	authorEmail = temp;
}
void Book::setAll(Book _book) {
	bookName = _book.bookName;
	publishYear = _book.publishYear;
	inUse = _book.inUse;
	authorName = _book.authorName;
	authorGender = _book.authorGender;
	authorEmail = _book.authorEmail;
}
string Book::getName() { return bookName; }
bool Book::getStatus() { return inUse; }
void Book::setStatus(bool _status) { inUse = _status; }
int Book::getPublishYear() { return publishYear; }
string Book::getAuthorName() { return authorName; }
string Book::getAuthorGender() { return authorGender; }
string Book::getAuthorEmail() { return authorEmail; }