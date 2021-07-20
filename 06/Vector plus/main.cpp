//   BY   : Shapour Discover
//   DATE : 2021-04-19
//   TIME : 20:06

#include "Vector_plus.cpp"

typedef string TYPE;

int main() {
	cout << setprecision(3) << fixed;
	Vector_plus<TYPE> obj1;

	// You can uncomment following code (From line 14 to line 87) to use user interface 
	/*int op;
	do
	{
		cout << "\n\n\n";
		cout << " What do you want to do? (enter number of option)" << endl;
		cout << " 1.Push a data to front" << endl;
		cout << " 2.Append a data to rear" << endl;
		cout << " 3.Insert a data to a special index (indexes start at 0)" << endl;
		cout << " 4.Delete last index (indexes start at 0)" << endl;
		cout << " 5.Delete a special index (indexes start at 0)" << endl;
		cout << " 6.Search index by giving data (indexes start at 0)" << endl;
		cout << " 7.Swap two data by giving indexes (indexes start at 0)" << endl;
		cout << " 8.Reverse the list" << endl;
		cout << " 9.Ascending sort" << endl;
		cout << " 10.Print the list" << endl;
		cout << " 11.You can also changing the code" <<
			" According to your desire" <<
			" (template and copy constructor)." <<
			" Please don't enter 11 and just come in to change :)" <<
			"(I used typedef to changing easily)" << endl;
		cout << " 0.Exit" << endl;
		cout << "Input:";
		cin >> op;
		if (op == 1) {
			cout << "Enter data:";
			TYPE _data;
			cin >> _data;
			obj1.push_front(_data);
		}
		else if (op == 2) {
			cout << "Enter data:";
			TYPE _data;
			cin >> _data;
			obj1.push_back(_data);
		}
		else if (op == 3) {
			cout << "Enter data:";
			TYPE _data;
			cin >> _data;
			cout << "Enter index (indexes start at 0):";
			int _index;
			cin >> _index;
			obj1.insert(_index, _data);
		}
		else if (op == 4)
			obj1.pop();
		else if (op == 5) {
			cout << "Enter index (indexes start at 0):";
			int _index;
			cin >> _index;
			obj1.Delete(_index);
		}
		else if (op == 6) {
			cout << "Enter data:";
			TYPE _data;
			cin >> _data;
			cout << "Its index:" << obj1.search(_data) << endl;
		}
		else if (op == 7) {
			cout << "Enter first index (indexes start at 0):";
			int _index1;
			cin >> _index1;
			cout << "Enter second index (indexes start at 0):";
			int _index2;
			cin >> _index2;
			obj1.Swap(_index1, _index2);
		}
		else if (op == 8)
			obj1.reverse();
		else if (op == 9)
			obj1.sort();
		else if (op == 10)
			obj1.print_list();
	} while (op != 0);*/







	obj1.push_front("alireza");
	obj1.push_front("mamad");
	obj1.push_front("javad");
	obj1.push_front("shapour");
	obj1.push_front("discover");
	obj1.push_back("arash");
	obj1.push_back("mahdi");
	obj1.push_back("mohsen");
	obj1.push_back("meraj");
	obj1.insert(2, "yasin");
	obj1.insert(9, "json");
	obj1.insert(9, "jackson");
	obj1.insert(9, "ronaldo");
	obj1.pop();
	obj1.Delete(3);
	obj1.Swap(3, 8);
	obj1.reverse();
	obj1.sort();
	obj1.print_list();
	cout << obj1.search("mohsen") << endl;

	Vector_plus<TYPE> obj2;
	obj2 = obj1;
	obj2.print_list();
	cout << obj2.search("alireza") << endl;
	cout << "\n\n\n" << obj2[2] << "\n\n\n";
	cout << obj2 << endl;
	obj2.reverse();
	Vector_plus<TYPE> obj3;
	TYPE ty = "alimamad";
	obj3 = obj2 + ty;
	cout << obj2.SIZE();
	obj3.print_list();

	obj3 = obj1 + obj2;
	obj3.print_list();

	Vector_plus<TYPE> obj4 = obj1 + obj2;

	if (obj3 == obj4)
		printf("mashala");

	obj3 += obj2;
	obj3.print_list();

	TYPE ty1 = "marshal";
	obj3 += ty1;
	obj3.print_list();


	TYPE ty2 = "david";
	obj3 = ty2 + obj1;
	obj3.print_list();

	cout << (obj3 = obj2);

	return 0;
}