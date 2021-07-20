//   BY   : Shapour Discover
//   DATE : 2021-06-09
//   TIME : 09:30

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class EmployeeDatabase {
	struct Employee {
		string Employee_ID;
		string Name;
		int Hire_Year;
		int Salary;
	};
	ifstream infile;
	ofstream outfile;
public:
	EmployeeDatabase() {
		ofstream outfile;
		outfile.open("Employee_Database.txt", ios::app);
		outfile.close();
	}
	void AddRecord() {
		ofstream outfile;
		outfile.open("Employee_Database.txt", ios::app);
		Employee emp;
		cout << "\n Enter ID        : ";
		cin >> emp.Employee_ID;
		cin.ignore();
		cout << " Enter Name      : ";
		getline(cin, emp.Name);
		cout << " Enter Salary    : ";
		cin >> emp.Salary;
		cout << " Enter Hire year : ";
		cin >> emp.Hire_Year;
		outfile << emp.Name << '\n' <<
			emp.Employee_ID << " " <<
			emp.Salary << " " <<
			emp.Hire_Year;
		cin.ignore();
		cout << "\n    Employee added successfully!\n" << endl;
		outfile.close();
	}
	void ListRecord() {
		Employee emp;
		ifstream infile;
		infile.open("Employee_Database.txt");
		infile.seekg(0, infile.beg);
		if (infile.eof()) {
			cout << "\n    List is empty!\n";
			return;
		}
		cout << "\n\n";
		for (int i = 0; !infile.eof(); i++) {
			getline(infile, emp.Name);
			infile >> emp.Employee_ID;
			infile >> emp.Salary;
			infile >> emp.Hire_Year;
			cout << " " << i + 1 << "." <<
				setw(30) << setfill(' ') << left << emp.Name <<
				"   ID : " << setw(20) << setfill(' ') << left << emp.Employee_ID <<
				"   Salary : " << setw(10) << setfill(' ') << left << emp.Salary <<
				"   Hire year : " << emp.Hire_Year << endl;
		}
		infile.close();
	}
	void ModifyRecord(string _Employee_ID) {
		Employee emp;
		bool E_found = 0;
		ofstream temp;
		temp.open("temp.txt", ios::trunc);
		ifstream infile;
		infile.open("Employee_Database.txt");
		infile.seekg(0, infile.beg);
		while (!infile.eof()) {
			getline(infile, emp.Name);
			infile >> emp.Employee_ID;
			infile >> emp.Salary;
			infile >> emp.Hire_Year;
			if (emp.Employee_ID == _Employee_ID) {
				cout << "\n Enter new ID        : ";
				cin >> emp.Employee_ID;
				cin.ignore();
				cout << " Enter new Name      : ";
				getline(cin, emp.Name);
				cout << " Enter new Salary    : ";
				cin >> emp.Salary;
				cout << " Enter new Hire year : ";
				cin >> emp.Hire_Year;
				temp << emp.Name << '\n' <<
					emp.Employee_ID << " " <<
					emp.Salary << " " <<
					emp.Hire_Year;
				E_found = 1;
				cout << "\n    Employee modified!\n" << endl;
			}
			else {
				temp << emp.Name << '\n' <<
					emp.Employee_ID << " " <<
					emp.Salary << " " <<
					emp.Hire_Year;
			}
		}
		infile.close();
		temp.close();
		remove("Employee_Database.txt");
		rename("temp.txt", "Employee_Database.txt");
		if (!E_found)
			cout << "\n    Employee not found!\n" << endl;
		cin.ignore();
	}
	void DeleteRecord(string _Employee_ID) {
		ifstream infile;
		Employee emp;
		ofstream temp;
		temp.open("temp.txt", ios::trunc);
		int counter = 0;
		infile.open("Employee_Database.txt");
		infile.seekg(0, infile.beg);
		cin.ignore();
		while (!infile.eof()) {
			getline(infile, emp.Name);
			infile >> emp.Employee_ID;
			infile >> emp.Salary;
			infile >> emp.Hire_Year;
			if (emp.Employee_ID != _Employee_ID) {
				temp << emp.Name << '\n' <<
					emp.Employee_ID << " " <<
					emp.Salary << " " <<
					emp.Hire_Year;
			}
			if (emp.Employee_ID == _Employee_ID && counter == 0) {
				cout << "\n    Employee deleted!\n" << endl;
				counter++;
			}
		}
		infile.close();
		temp.close();
		remove("Employee_Database.txt");
		rename("temp.txt", "Employee_Database.txt");
		if (!counter)
			cout << "\n    Employee not found!\n" << endl;
	}
	void SearchRecord(string _Employee_ID) {
		ifstream infile;
		Employee emp;
		bool E_found = 0;
		infile.open("Employee_Database.txt");
		infile.seekg(0, infile.beg);
		cin.ignore();
		while (!infile.eof()) {
			getline(infile, emp.Name);
			infile >> emp.Employee_ID;
			infile >> emp.Salary;
			infile >> emp.Hire_Year;
			if (emp.Employee_ID == _Employee_ID) {
				cout << " Name : " << emp.Name <<
					"     ID : " << emp.Employee_ID <<
					"     Salary : " << emp.Salary <<
					"     Hire Year : " << emp.Hire_Year << endl;
				E_found = 1;
				break;
			}
		}
		infile.close();
		if (!E_found)
			cout << "\n    Employee not found!\n" << endl;
	}
	void SaveRecord(string file_name) {
		ifstream infile;
		infile.open("Employee_Database.txt");
		infile.seekg(0, infile.beg);
		cin.ignore();
		if (infile.eof()) {
			cout << "\n    List is empty!\n";
			return;
		}
		infile.close();
		Employee emp;
		infile.open("Employee_Database.txt");
		infile.seekg(0, infile.beg);
		ofstream save_file;
		file_name += ".txt";
		save_file.open(file_name);
		while (!infile.eof()) {
			getline(infile, emp.Name);
			infile >> emp.Employee_ID;
			infile >> emp.Salary;
			infile >> emp.Hire_Year;
			save_file << emp.Employee_ID << "                    " <<
				emp.Name << "                    " <<
				emp.Salary << "                    " <<
				emp.Hire_Year << '\n';
		}
		cout << "\n    Information Saved!\n" << endl;
		infile.close();
	}
};
string to_lower_case(string str) {
	string final_str = "";
	for (unsigned int i = 0; i < str.length(); i++) {
		char character = str[i];
		if (character >= 65 && character <= 92)
			final_str += (character + 32);
		else
			final_str += character;
	}
	return final_str;
}
int main() {
	cout << "   Welcome to Database!!!" << endl;
	string command;
	do {
		cout << "\n\n What do you want to do ?" << endl;
		cout << "      1.Add Record" << endl;
		cout << "      2.List Record" << endl;
		cout << "      3.Modify Record" << endl;
		cout << "      4.Delete Record" << endl;
		cout << "      5.Search Record" << endl;
		cout << "      6.Save Record" << endl;
		cout << "      7.Exit\n" << endl;
		cout << "   Commnad : ";
		getline(cin, command);
		if (command == "1" || to_lower_case(command) == "add record") {
			EmployeeDatabase edb;
			edb.AddRecord();
		}
		else if (command == "2" || to_lower_case(command) == "list record") {
			EmployeeDatabase edb;
			edb.ListRecord();
		}
		else if (command == "3" || to_lower_case(command) == "modify record") {
			EmployeeDatabase edb;
			string ID;
			cout << "\n Enter desired employee ID : ";
			cin >> ID;
			edb.ModifyRecord(ID);
		}
		else if (command == "4" || to_lower_case(command) == "delete record") {
			EmployeeDatabase edb;
			string ID;
			cout << "\n Enter desired employee ID : ";
			cin >> ID;
			edb.DeleteRecord(ID);
		}
		else if (command == "5" || to_lower_case(command) == "search record") {
			EmployeeDatabase edb;
			string ID;
			cout << "\n Enter desired employee ID : ";
			cin >> ID;
			edb.SearchRecord(ID);
		}
		else if (command == "6" || to_lower_case(command) == "save record") {
			EmployeeDatabase edb;
			string file_name;
			cout << "\n Enter File name : ";
			cin >> file_name;
			edb.SaveRecord(file_name);
		}
	} while (command != "7" && to_lower_case(command) != "exit");

	return 0;
}