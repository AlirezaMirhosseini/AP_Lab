//   BY   : Shapour Discover
//   DATE : 2021-06-12
//   TIME : 18:14

#include <iostream>
#include <vector>

using namespace std;

int main() {
	string str;
	cin >> str;
	vector<char> result;
	for (unsigned int i = 0;i < str.length();i++) {
		unsigned int counter = 0;
		for (unsigned int j = 0;j < str.length();j++)
			if ((str[j] <= 90 && (str[j] == str[i] || str[j] == str[i] - 32)) ||
				(str[j] >= 97 && (str[j] == str[i] || str[j] == str[i] + 32)))
				counter++;
		if (str[i] <= 90)
			result.push_back(((counter * (str[i] - 65) + 1) % 26) + 65);
		if (str[i] >= 97)
			result.push_back(((counter * (str[i] - 97) + 1) % 26) + 97);
	}
	for (unsigned int i = 0; i < str.length(); i++)
		cout << result[i];
	return 0;
}