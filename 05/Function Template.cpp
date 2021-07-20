//   BY   : Shapour Discover
//   DATE : 2021-04-08
//   TIME : 15:01

#include <iostream>
#include <iomanip>
#include <string>

#pragma warning(disable:4996)

using namespace std;

template <typename T>
T GetMax(T a, T b) { return (a >= b) ? a : b; }
//________________________________________________________________________________________________________
template <typename T, int SIZE>
T GetMax(T* arr) {
	T max = arr[0];
	for (int i = 1;i < SIZE;i++) 
		if (max < arr[i])
			max = arr[i];
	return max;
}
//________________________________________________________________________________________________________
template <typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
//________________________________________________________________________________________________________
template <typename T, int SIZE>
int Find(T* arr, T data) {
	for (int i = 0;i < SIZE;i++) {
		if (arr[i] == data) {
			return i;
		}
	}
	return -1;
}
//________________________________________________________________________________________________________
template <typename T, int SIZE>
void Sort(T* arr) {
	for (int i = 0;i < SIZE;i++)
		for (int j = i + 1;j < SIZE;j++) 
			if (arr[i] < arr[j]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}
void Sort(char* arr, int SIZE) {
	for (int i = 0;i < SIZE;i++)
		for (int j = i + 1;j < SIZE;j++)
			if (arr[i] < arr[j]) {
				char temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}
void Sort(string* arr, int SIZE) {
	for (int i = 0;i < SIZE;i++)
		for (int j = i + 1;j < SIZE;j++)
			if (arr[i] < arr[j]) {
				string temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}
//________________________________________________________________________________________________________
template <typename T, int SIZE>
T* valarray(T data) {
	T* val_arr = new T[SIZE];
	for (int i = 0;i < SIZE;i++)
		val_arr[i] = data;
	return val_arr;
}
//________________________________________________________________________________________________________
template <typename T>
T Add(T data1, T data2) { return data1 + data2; }
char* Add(char c1, char c2) {
	char* res = new char[3];
	res[0] = c1;
	res[1] = c2;
	res[2] = '\0';
	return res;
}
char* Add(char* s1, char* s2) { return strcat(s1, s2); }
string Add(string str1, string str2) { return str1.append(str2); }
//________________________________________________________________________________________________________
template <typename T>
void print(T data) { cout << "Data is : " << data << endl; }

int main() {
	cout << scientific;
	//cout << setprecision(3) << fixed;

	cout << "GetMax for int : ";// GetMax int
	int a = 11, b = 12;
	cout << GetMax<int>(a, b) << endl;
	cout << "GetMax for float : ";// GetMax float
	float a1 = 1122.5, b1 = 1213.003;
	cout << GetMax<float>(a1, b1) << endl;
	cout << "GetMax for double : ";// GetMax double
	double a2 = 0.1122334, b2 = 0.1213141;
	cout << GetMax<double>(a2, b2) << endl;
	cout << "GetMax for char : ";// GetMax char
	char a3 = 'c', b3 = 'u';
	cout << GetMax<char>(a3, b3) << endl;
	cout << "GetMax for string : ";// GetMax string
	string a4 = "shapour", b4 = "alireza";
	cout << GetMax<string>(a4, b4) << endl;

	cout << "----------------------------------------------------------\n";

	cout << "GetMax for int array : ";// GetMax int array
	int arr[10] = { 429,-335,0,12,678,238,8020,3,-3,-111 };
	cout << GetMax<int, 10>(arr) << endl;
	cout << "GetMax for float array : ";// GetMax float array
	float arr1[10] = { 429.5,-335.21,0,12.008,678.01,0.238,8020.5555,3.3,-3.3,-111.111 };
	cout << GetMax<float, 10>(arr1) << endl;
	cout << "GetMax for double array : ";// GetMax double array
	double arr2[10] = { 429.000005,-335.000021,0,12.000008,678.001001,0.238238,3.321321,-3.123123,-111.111111,80208020.555555 };
	cout << GetMax<double, 10>(arr2) << endl;
	cout << "GetMax for char array : ";// GetMax char array
	char arr3[10] = { 's','h','a','p','o','s','r','d','i','u' };
	cout << GetMax<char, 10>(arr3) << endl;
	cout << "GetMax for string array : ";// GetMax string array
	string arr4[10] = { "alireza","shapour","javad","mohsen","shayan","disco","mahdi","me'raj","matin","iliya" };
	cout << GetMax<string, 10>(arr4) << endl;

	cout << "----------------------------------------------------------\n";

	int c = 4, d = 237;// Swap int
	Swap<int>(c, d);
	cout << "swap for int : ";
	cout << c << "  and  " << d << endl;
	float c1 = 0.00054545, d1 = 237.238;// Swap float
	Swap<float>(c1, d1);
	cout << "swap for float : ";
	cout << c1 << "  and  " << d1 << endl;
	double c2 = 0.0045454, d2 = 237237237.237;// Swap double
	Swap<double>(c2, d2);
	cout << "swap for double : ";
	cout << c2 << "  and  " << d2 << endl;
	char c3 = 'u', d3 = 'g';// Swap char
	Swap<char>(c3, d3);
	cout << "swap for char : ";
	cout << c3 << "  and  " << d3 << endl;
	string c4 = "alireza", d4 = "shapour";// Swap string
	Swap<string>(c4, d4);
	cout << "swap for string : ";
	cout << c4 << "  and  " << d4 << endl;

	cout << "----------------------------------------------------------\n";

	cout << "Find for int array(indexes start at 0) : ";// Find int array
	int Find_arr[10] = { 429,-335,0,12,678,238,8020,3,-3,-111 };
	cout << Find<int, 10>(Find_arr, -335) << endl;
	cout << "Find for float array(indexes start at 0) : ";// Find float array
	float Find_arr1[10] = { 429.5,-335.21,0,12.008,678.01,0.238,8020.5555,3.3,-3.3,-111.111 };
	cout << Find<float, 10>(Find_arr1, 0) << endl;
	cout << "Find for double array(indexes start at 0) : ";// Find double array
	double Find_arr2[10] = { 429.000005,-335.000021,0,12.000008,678.001001,0.238238,3.321321,-3.123123,-111.111111,80208020.555555 };
	cout << Find<double, 10>(Find_arr2, 3.321321) << endl;
	cout << "Find for char array(indexes start at 0) : ";// Find char array
	char Find_arr3[10] = { 's','h','a','p','o','s','r','d','i','u' };
	cout << Find<char, 10>(Find_arr3, 's') << endl;
	cout << "Find for string array(indexes start at 0) : ";// Find string array
	string Find_arr4[10] = { "alireza","shapour","javad","mohsen","shayan","disco","mahdi","me'raj","matin","iliya" };
	cout << Find<string, 10>(Find_arr4, "matin") << endl;

	cout << "----------------------------------------------------------\n";

	cout << "Sort for int array(indexes start at 0) : ";// Sort int array
	int Sort_arr[10] = { 429,-335,0,12,678,238,8020,3,-3,-111 };
	Sort<int, 10>(Sort_arr);
	for (int i = 0;i < 10;i++) {
		cout << Sort_arr[i] << " _ ";
	}
	cout << endl;

	cout << "Sort for float array(indexes start at 0) : ";// Sort float array
	float Sort_arr1[10] = { 429.5,-335.21,0,12.008,678.01,0.238,8020.5555,3.3,-3.3,-111.111 };
	Sort<float, 10>(Sort_arr1);
	for (int i = 0;i < 10;i++) {
		cout << Sort_arr1[i] << " _ ";
	}
	cout << endl;

	cout << "Sort for double array(indexes start at 0) : ";// Sort double array
	double Sort_arr2[10] = { 429.000005,-335.000021,0,12.000008,678.001001,0.238238,3.321321,-3.123123,-111.111111,80208020.555555 };
	Sort<double, 10>(Sort_arr2);
	for (int i = 0;i < 10;i++) {
		cout << Sort_arr2[i] << " _ ";
	}
	cout << endl;

	cout << "Sort for char array(indexes start at 0) : ";// Sort char array
	char Sort_arr3[10] = { 's','h','a','p','o','s','r','d','i','u' };
	Sort(Sort_arr3, 10);
	for (int i = 0;i < 10;i++) {
		cout << Sort_arr3[i] << " _ ";
	}
	cout << endl;

	cout << "Sort for string array(indexes start at 0) : ";// Sort string array
	string Sort_arr4[10] = { "alireza","shapour","javad","mohsen","shayan","disco","mahdi","me'raj","matin","iliya" };
	Sort(Sort_arr4, 10);
	for (int i = 0;i < 10;i++) {
		cout << Sort_arr4[i] << " _ ";
	}
	cout << endl;

	cout << "----------------------------------------------------------\n";

	cout << "Value array for int (indexes start at 0) : ";// Val array int
	int* val_arr = valarray<int, 10>(17);
	for (int i = 0;i < 10;i++) {
		cout << val_arr[i] << " _ ";
	}
	cout << endl;

	cout << "Value array for float (indexes start at 0) : ";// Val array float
	float* val_arr1 = valarray<float, 10>(0.0006);
	for (int i = 0;i < 10;i++) {
		cout << val_arr1[i] << " _ ";
	}
	cout << endl;

	cout << "Value array for double (indexes start at 0) : ";// Val array double
	double* val_arr2 = valarray<double, 10>(123456789.123456);
	for (int i = 0;i < 10;i++) {
		cout << val_arr2[i] << " _ ";
	}
	cout << endl;

	cout << "Value array for char (indexes start at 0) : ";// Val array char
	char* val_arr3 = valarray<char, 10>('m');
	for (int i = 0;i < 10;i++) {
		cout << val_arr3[i] << " _ ";
	}
	cout << endl;

	cout << "Value array for string (indexes start at 0) : ";// Val array string
	string* val_arr4 = valarray<string, 10>("alireza");
	for (int i = 0;i < 10;i++) {
		cout << val_arr4[i] << " _ ";
	}
	cout << endl;

	cout << "----------------------------------------------------------\n";

	int add_c = 4, add_d = 237;// Add int
	cout << "Add for int : ";
	cout << Add<int>(add_c, add_d) << endl;
	float add_c1 = 0.00054545, add_d1 = 237.238;// Add float
	cout << "Add for float : ";
	cout << Add<float>(add_c1, add_d1) << endl;
	double add_c2 = 0.0045454, add_d2 = 237237237.237;// Add double
	cout << "Add for double : ";
	cout << Add<double>(add_c2, add_d2) << endl;
	char add_c3 = 'a', add_d3 = 'b';// Add char
	cout << "Add for char : ";
	cout << Add(add_c3, add_d3) << endl;
	string add_c4 = "alireza", add_d4 = "shapour";// Add string
	cout << "Add for string : ";
	cout << Add(add_c4, add_d4) << endl;
	char add_c5[11] = "mamad", add_d5[6] = "javad";// Add char*
	cout << "Add for char* : ";
	cout << Add(add_c5, add_d5) << endl;

	cout << "----------------------------------------------------------\n";

	int print_c = -4593;// print int
	cout << "print for int : ";
	print<int>(print_c);
	float print_c1 = 0.00054545;// print float
	cout << "print for float : ";
	print<float>(print_c1);
	double print_c2 = 0.0045454;// print double
	cout << "print for double : ";
	print<double>(print_c2);
	char print_c3 = 'a';// print char
	cout << "print for char : ";
	print(print_c3);
	string print_c4 = "shapour";// print string
	cout << "print for string : ";
	print(print_c4);

	return 0;
}