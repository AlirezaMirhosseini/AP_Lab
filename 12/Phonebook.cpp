//   BY   : Shapour Discover
//   DATE : 2021-06-16
//   TIME : 13:34

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	map<string, map<string, string>> Phonebook;
	map<string, map<string, string>>::iterator itr;
	vector<string> favorite;
	int cmd;
	do{
		cout << "\n What do you want to do ? (number of option)" << endl;
		cout << "     1.Add a contact" << endl;
		cout << "     2.Edit a contact" << endl;
		cout << "     3.Remove a contact" << endl;
		cout << "     4.Add a phone number to a contact" << endl;
		cout << "     5.Edit a phone number of a contact" << endl;
		cout << "     6.Remove a phone number from a contact" << endl;
		cout << "     7.Add a contact to favorites list" << endl;
		cout << "     8.Remove a contact from favorites list" << endl;
		cout << "     9.Change order of contacts in favorites list" << endl;
		cout << "     10.Display all contacts (in alphabetical order)" << endl;
		cout << "     11.Show all phone numbers of a contact" << endl;
		cout << "     12.Favorites list" << endl;
		cout << "     13.Search in contacts" << endl;
		cout << "     0.Exit\n" << endl;
		cout << " Command : ";
		cin >> cmd;
		if (cmd == 1) {
			cin.ignore();
			cout << "\n Enter name : ";
			string name;
			getline(cin, name);
			Phonebook.insert(make_pair(name, map<string, string>()));
			cout << " Contact added successfully." << endl;
		}
		else if (cmd == 2) {
			cin.ignore();
			cout << "\n Enter contact name : ";
			string name;
			getline(cin, name);
			itr = Phonebook.find(name);
			if (itr != Phonebook.end()) {
				cout << " Enter new name for contact : ";
				string new_name;
				getline(cin, new_name);
				for (unsigned int i = 0; i < favorite.size(); i++)
					if (favorite[i] == name) {
						favorite[i] = new_name;
						break;
					}
				map<string, string> val = move(itr->second);
				Phonebook.erase(itr);
				Phonebook.insert(make_pair(new_name, val));
				cout << " Contact modified." << endl;
			}
			else
				cout << " Not found!" << endl;
		}
		else if (cmd == 3) {
			cin.ignore();
			cout << "\n Enter contact name : ";
			string name;
			getline(cin, name);
			itr = Phonebook.find(name);
			if (itr != Phonebook.end()) {
				for (unsigned int i = 0; i < favorite.size(); i++)
					if (favorite[i] == name) {
						favorite.erase(favorite.begin() + i);
						break;
					}
				Phonebook.erase(itr);
				cout << " Contact deleted." << endl;
			}
			else
				cout << " Not found!" << endl;
		}
		else if (cmd == 4) {
			cin.ignore();
			cout << "\n Enter contact name : ";
			string name;
			getline(cin, name);
			itr = Phonebook.find(name);
			if (itr != Phonebook.end()) {
				string type, number;
				cout << " Enter type : ";
				cin >> type;
				cout << " Enter phone number : ";
				cin >> number;
				Phonebook[name].insert(make_pair(type, number));
				cout << " Number added to contact number list." << endl;
				cin.ignore();
			}
			else
				cout << " Not found!" << endl;
		}
		else if (cmd == 5) {
			cin.ignore();
			cout << "\n Enter contact name : ";
			string name;
			getline(cin, name);
			itr = Phonebook.find(name);
			if (itr != Phonebook.end()) {
				cout << " Enter type : ";
				string type;
				cin >> type;
				map<string, string>::iterator type_itr;
				type_itr = Phonebook[name].find(type);
				if (type_itr != Phonebook[name].end()) {
					cout << " Enter new phone number : ";
					string new_num;
					cin >> new_num;
					type_itr->second = new_num;
					cout << " Number modified." << endl;
				}
				else
					cout << " Type not found!" << endl;
				cin.ignore();
			}
			else
				cout << " Not found." << endl;
		}
		else if (cmd == 6) {
			cin.ignore();
			cout << "\n Enter contact name : ";
			string name;
			getline(cin, name);
			itr = Phonebook.find(name);
			if (itr != Phonebook.end()) {
				cout << " Enter type : ";
				string type;
				cin >> type;
				map<string, string>::iterator type_itr;
				type_itr = Phonebook[name].find(type);
				if (type_itr != Phonebook[name].end()) {
					Phonebook[name].erase(type_itr);
					cout << " Phone number deleted." << endl;
				}
				else
					cout << " Type not found!" << endl;
				cin.ignore();
			}
			else
				cout << " Not found." << endl;
		}
		else if (cmd == 7) {
			cin.ignore();
			cout << "\n Enter contact name : ";
			string name;
			getline(cin, name);
			itr = Phonebook.find(name);
			if (itr != Phonebook.end()) {
				favorite.push_back(itr->first);
				cout << " Contact added to favorites." << endl;
			}
			else
				cout << " Not found." << endl;
		}
		else if (cmd == 8) {
			cin.ignore();
			cout << "\n Enter contact name : ";
			string name;
			getline(cin, name);
			itr = Phonebook.find(name);
			if (itr != Phonebook.end())
				for (unsigned int i = 0; i < favorite.size(); i++)
					if (favorite[i] == itr->first) {
						favorite.erase(favorite.begin() + i);
						cout << " Contact deleted from favorites." << endl;
						break;
					}
			else
				cout << " Not found." << endl;
		}
		else if (cmd == 9) {
			cin.ignore();
			if (favorite.size()) {
				cout << "\n     Swap two contacts...\n" << endl;
				cout << " Enter first contact name  : ";
				string name1;
				getline(cin, name1);
				cout << " Enter second contact name : ";
				string name2;
				getline(cin, name2);
				bool found_1 = 0, found_2 = 0;
				int index_1, index_2;
				for (unsigned int i = 0; i < favorite.size(); i++) {
					if (favorite[i] == name1) {
						found_1 = 1;
						index_1 = i;
					}
					if (favorite[i] == name2) {
						found_2 = 1;
						index_2 = i;
					}
				}
				if (found_1 && found_2) {
					string temp = favorite[index_1];
					favorite[index_1] = favorite[index_2];
					favorite[index_2] = temp;
					cout << " Contacts swaped successfully." << endl;
				}
				else
					cout << " Not found!" << endl;
			}
			else
				cout << "\n Favorites list is empty!" << endl;

		}
		else if (cmd == 10) {
			cin.ignore();
			vector<string> contacts_name;
			for (itr = Phonebook.begin(); itr != Phonebook.end(); ++itr)
				contacts_name.push_back(itr->first);
			if (contacts_name.size()) {
				unsigned int i = 0;
				for (; i < contacts_name.size(); i++)
					for (unsigned int j = i + 1; j < contacts_name.size(); j++)
						if (contacts_name[i] > contacts_name[j]) {
							string temp = contacts_name[i];
							contacts_name[i] = contacts_name[j];
							contacts_name[j] = temp;
						}
				for (i = 0; i < contacts_name.size(); i++) {
					itr = Phonebook.find(contacts_name[i]);
					cout << "\n " << itr->first << " ==>" << endl;
					map<string, string>::iterator numbers_itr;
					for (numbers_itr = Phonebook[itr->first].begin(); numbers_itr != Phonebook[itr->first].end(); ++numbers_itr)
						cout << "     " << numbers_itr->first << " : " << numbers_itr->second << endl;
				}
			}
			else
				cout << "\n List is empty!" << endl;
		}
		else if (cmd == 11) {
			cin.ignore();
			cout << "\n Enter contact name : ";
			string name;
			getline(cin, name);
			itr = Phonebook.find(name);
			if (itr != Phonebook.end()) {
				if (Phonebook[itr->first].size()) {
					cout << "\n " << itr->first << " ==>" << endl;
					map<string, string>::iterator numbers_itr;
					for (numbers_itr = Phonebook[itr->first].begin(); numbers_itr != Phonebook[itr->first].end(); ++numbers_itr)
						cout << "     " << numbers_itr->first << " : " << numbers_itr->second << endl;
				}
				else
					cout << "\n You have not enter a phone number for this contact." << endl;
			}
			else
				cout << " Not found!" << endl;
		}
		else if (cmd == 12) {
			cin.ignore();
			for (unsigned int i = 0; i < favorite.size(); i++) {
				itr = Phonebook.find(favorite[i]);
				cout << "\n " << itr->first << " ==>" << endl;
				map<string, string>::iterator numbers_itr;
				for (numbers_itr = Phonebook[itr->first].begin(); numbers_itr != Phonebook[itr->first].end(); ++numbers_itr)
					cout << "     " << numbers_itr->first << " : " << numbers_itr->second << endl;
			}
			if (!favorite.size())
				cout << "\n Favorites list is empty!" << endl;
		}
		else if (cmd == 13) {
			cin.ignore();
			if (Phonebook.size()) {
				cout << "\n Enter Substring : ";
				string sub;
				cin >> sub;
				int counter = 0, same_count = 0;
				for (itr = Phonebook.begin(); itr != Phonebook.end(); ++itr) {
					same_count = 0;
					for (unsigned int i = 0; i < sub.length(); i++)
						if (sub[i] == itr->first[i])
							same_count++;
					if (same_count == sub.length()) {
						counter++;
						cout << "\n " << itr->first << " ==>" << endl;
						map<string, string>::iterator numbers_itr;
						for (numbers_itr = Phonebook[itr->first].begin(); numbers_itr != Phonebook[itr->first].end(); ++numbers_itr)
							cout << "     " << numbers_itr->first << " : " << numbers_itr->second << endl;
					}
				}
				if (!counter)
					cout << " No contact found with this substring!" << endl;
			}
			else
				cout << "\n List is empty!" << endl;
		}
	} while (cmd != 0);
	return 0;
}