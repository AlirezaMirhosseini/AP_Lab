//   BY   : Shapour Discover
//   DATE : 2021-04-28
//   TIME : 11:25

#include "uniquePairs.cpp"
#include "pairs.cpp"

int main() {
	
	uniquePairs<char, int> first;
	first['x'] = 8; //first= {('x',8)} 
	first['y'] = 16; //first= {('x',8), ('y',16)}
	first['z'] = 32; //first= {('x',8), ('y',16), ('z',32)}
	first.insert('a', 100); //first= {('x',8), ('y',16), ('z',32), ('a',100)} 
	first.insert('x', 200); //first= {('x',200), ('y',16), ('z',32), ('a',100)} 
	first.remove('x'); //first= {('y',16), ('z',32), ('a',100)} 
	first.remove('a'); //first= {('y',16), ('z',32)}
	uniquePairs<char, int> second;
	second = first; // second={('y',16), ('z',32)}
	cout << second;
	

	std::cout << "Size of first: " << first.SIZE() << '\n'; //output: 2 
	std::cout << "Size of second: " << second.SIZE() << '\n'; //output: 2
	second.insert('b', 40);
	second.insert('x', 70);
	second.insert('a', 100); // second={('y',16), ('z',32), ('b',40), ('x',70), ('a',100)} 
	second = second - first; //second=( ('b',40), ('x',70), ('a',100)}
	first.insert('x', 8);
	cout << second;

	const uniquePairs<char, int> third = first;

	second['a'] = third['y'];
	cout << third['z'] << endl;

	pairs<string, string> phoneBook1;
	phoneBook1.insert("ali", "123");
	phoneBook1.insert("ali", "456");
	phoneBook1.insert("mina", "5678");
	pairs<string, string> phoneBook2;
	phoneBook2["ahmad"] = "1234567";
	phoneBook2["mina"] = "1234567";
	phoneBook2["mina"] = "567";
	const pairs<string, string>phoneBook3 = phoneBook2;
	phoneBook1.remove("ali"); // phoneBook1 = { ("mina", "567") }
	cout << phoneBook3;

	return 0;
}