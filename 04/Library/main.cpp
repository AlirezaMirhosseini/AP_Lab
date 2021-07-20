//   BY   : Shapour Discover
//   DATE : 2021-04-04
//   TIME : 22:08

#include "Library.h"

int main() {
	int op;
	Library library("Mard abad city", "Yazd, Mahmoud abad", 7.50, 22.50, 2001, 15, 0);
	do
	{
		cout << " What do you want to do? (enter number of your option)" << endl;
		cout << " 1.Add a book to library" << endl;
		cout << " 2.List of available books" << endl;
		cout << " 3.List of borrowed books" << endl;
		cout << " 4.Get status of a book" << endl;
		cout << " 5.Borrow a book" << endl;
		cout << " 6.Return a book" << endl;
		cout << " 7.Get opening and closing time" << endl;
		cout << " 8.Enter a time and find out if the library is open at that time or not" << endl;
		cout << " 9.Number of all books that belong to this library" << endl;
		cout << " 10.List of all books that belong to this library" << endl;
		cout << " 0.Exit" << endl;
		cout << "Input:";
		cin >> op;
		getchar();
		if (op == 1) {
			cout << "Enter name of the book:";
			string _bookName;
			getline(cin, _bookName);
			cout << "Enter year of publish:";
			int _publishYear;
			cin >> _publishYear;
			getchar();
			cout << "Enter name of author:";
			string _authorName;
			getline(cin, _authorName);
			cout << "The author is male or female? (just enter male/female):";
			string _authorGender;
			cin >> _authorGender;
			getchar();
			cout << "Enter email of author:";
			string _authorEmail;
			cin >> _authorEmail;
			getchar();
			library.addBook(_bookName, _publishYear, _authorName, _authorGender, _authorEmail);
		}
		if (op == 2)
			library.notBorrowedList();
		if (op == 3)
			library.borrowedList();
		if (op == 4) {
			cout << "Enter name of book:";
			string _bookName;
			getline(cin, _bookName);
			library.bookStatus(_bookName);
		}
		if (op == 5) {
			cout << "Enter name of book:";
			string _bookName;
			getline(cin, _bookName);
			library.borrowBook(_bookName);
		}
		if (op == 6) {
			cout << "Enter name of book:";
			string _bookName;
			getline(cin, _bookName);
			library.returnBook(_bookName);
		}
		if (op == 7)
			cout << "Library opens at " << library.getOpenTime() << " and closes at " << library.getCloseTime() << endl;
		if (op == 8) {
			cout << "Enter Time:";
			float _hour;
			cin >> _hour;
			getchar();
			library.OpenOrClose(_hour);
		}
		if (op == 9)
			cout << "There is " << library.getNumberOfBooks() << " books that belongs to this library!";
		if (op == 10)
			library.printList();
		if (op != 0)
			cout << "\n\n\n";
	} while (op != 0);
	cout << "\nThanks for visiting our library. hope to see you again :)\n";
	return 0;
}