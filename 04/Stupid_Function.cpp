//   BY   : Shapour Discover
//   DATE : 2021-03-24
//   TIME : 13:11

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int Function(int number1, int number2) { return number1 + number2; }
int* Function(int number, int* ptr, int& size) {
	int* temp = new int[size];
	for (int i = 0;i < size;i++) { temp[i] = ptr[i]; }
	size++;
	ptr = new int[size];
	ptr[0] = number;
	int t = 0;
	for (int i = 1;i < size;i++,t++) { ptr[i] = temp[t]; }
	delete[] temp;
	return ptr;
}
int* Function(int* ptr, int number, int& size) {
	int* temp = new int[size];
	for (int i = 0;i < size;i++) { temp[i] = ptr[i]; }
	size++;
	ptr = new int[size];
	ptr[size-1] = number;
	for (int i = 0;i < size - 1;i++) { ptr[i] = temp[i]; }
	delete[] temp;
	return ptr;
}
float Function(float number1, float number2) { return number1 + number2; }
float* Function(float number, float* ptr, int& size) {
	float* temp = new float[size];
	for (int i = 0;i < size;i++) { temp[i] = ptr[i]; }
	size++;
	ptr = new float[size];
	ptr[0] = number;
	int t = 0;
	for (int i = 1;i < size;i++, t++) { ptr[i] = temp[t]; }
	delete[] temp;
	return ptr;
}
float* Function(float* ptr, float number, int& size) {
	float* temp = new float[size];
	for (int i = 0;i < size;i++) { temp[i] = ptr[i]; }
	size++;
	ptr = new float[size];
	ptr[size - 1] = number;
	for (int i = 0;i < size - 1;i++) { ptr[i] = temp[i]; }
	delete[] temp;
	return ptr;
}
bool Function(bool case1, bool case2) { return (case1 && case2) ? true : false; }
string Function(string str1, string str2) { 
	str1.append(" ");
	return str1.append(str2);
}
string Function(string str, int number) {
	str.append(" ");
	return str.append(to_string(number)); 
}
//string Function(int number, string str) { 
//	str.append(" ");
//	return str.append(to_string(number)); 
//}
string Function(string str, float number) {
	str.append(" ");
	return str.append(to_string(number)); 
}
//string Function(float number, string str) {
//	str.append(" ");
//	return str.append(to_string(number)); 
//}
string Function(string str, int* ptr, int size) {
	for (int i = 0;i < size;i++) {//-814459481
		str.append(" ");
		str.append(to_string(ptr[i]));
	}
	return str;
}
//string Function(int* ptr, string str, int size) {
//	for (int i = 0;i < size;i++) {//-814459481
//		str.append(" ");
//		str.append(to_string(ptr[i]));
//	}
//	return str;
//}
string Function(string str, float* ptr, int size) {
	for (int i = 0;i < size;i++) {//-403229136
		str.append(" ");
		str.append(to_string(ptr[i]));
	}
	return str;
}
//string Function(float* ptr, string str, int size) {
//	for (int i = 0;i < size;i++) {//-403229136
//		str.append(" ");
//		str.append(to_string(ptr[i]));
//	}
//	return str;
//}

int main() {
	cout << setprecision(3) << fixed << boolalpha;
	cout << "<<Program>>\n\n--------------------\n\n";

	int num1, num2, size;// Int

	cout << "Sum. Enter two integers:";
	cin >> num1 >> num2;
	cout << "The Function returns:" << Function(num1, num2) << "\n\n--------------------\n\n";
	cout << "Push an integer to array. Enter the integer:";
	cin >> num1;
	cout << "Enter size of the array:";
	cin >> size;
	cout << "now Enter array:";
	int* Int_Array = new int[size];
	for (int i = 0;i < size;i++) { cin >> Int_Array[i]; }
	cout << "The Function returns:";
	int* pointer1 = Function(num1, Int_Array, size);
	for (int i = 0;i < size;i++) { cout << pointer1[i] << "  "; }
	cout<< "\n\n--------------------\n\n";
	cout << "Append an integer to array. Enter the integer:";
	cin >> num1;
	cout << "Enter size of the array:";
	cin >> size;
	cout << "now Enter array:";
	int* Int_Array2 = new int[size];
	for (int i = 0;i < size;i++) { cin >> Int_Array2[i]; }
	cout << "The Function returns:";
	int* pointer2 = Function(Int_Array2, num1, size);
	for (int i = 0;i < size;i++) { cout << pointer2[i] << "  "; }
	cout << "\n\n--------------------\n\n";

	float Num1, Num2;// Float

	cout << "Sum. Enter two floats:";
	cin >> Num1 >> Num2;
	cout << "The Function returns:" << Function(Num1, Num2) << "\n\n--------------------\n\n";
	cout << "Push an float to array. Enter the float:";
	cin >> Num1;
	cout << "Enter size of the array:";
	cin >> size;
	cout << "now Enter array:";
	float* Float_Array = new float[size];
	for (int i = 0;i < size;i++) { cin >> Float_Array[i]; }
	cout << "The Function returns:";
	float* Float_pointer1 = Function(Num1, Float_Array, size);
	for (int i = 0;i < size;i++) { cout << Float_pointer1[i] << "  "; }
	cout << "\n\n--------------------\n\n";
	cout << "Append an float to array. Enter the float:";
	cin >> Num1;
	cout << "Enter size of the array:";
	cin >> size;
	cout << "now Enter array:";
	float* Float_Array2 = new float[size];
	for (int i = 0;i < size;i++) { cin >> Float_Array2[i]; }
	cout << "The Function returns:";
	float* Float_pointer2 = Function(Float_Array2, Num1, size);
	for (int i = 0;i < size;i++) { cout << Float_pointer2[i] << "  "; }
	cout << "\n\n--------------------\n\n";

	bool case1, case2;// Bool

	cout << "Enter two boolean attributes:";
	cin >> case1 >> case2;
	cout << "The Function returns:" << Function(case1, case2) << "\n\n--------------------\n\n";

	string str1, str2;// String
	cout << "Append string2 to string1. Enter string1:";
	cin >> str1;
	cout << "Enter string2:";
	cin >> str2;
	cout << "The Function returns:" << Function(str1, str2) << "\n\n--------------------\n\n";

	int num3;// add int to string
	string str3;
	cout << "Append an integer to string. Enter the string:";
	cin >> str3;
	cout << "Enter the integer:";
	cin >> num3;
	cout << "The Function returns:" << Function(str3, num3) << "\n\n--------------------\n\n";

	float num4;// add float to string
	string str4;
	cout << "Append an float to string. Enter the string:";
	cin >> str4;
	cout << "Enter the float:";
	cin >> num4;
	cout << "The Function returns:" << Function(str4, num4) << "\n\n--------------------\n\n";

	cout << "Append an integer array to string. Enter the string:";// add int_array to string
	string str5;
	cin >> str5;
	cout << "Enter size of integer array:";
	cin >> size;
	int* Int_Array3 = new int[size];
	cout << "Enter array:";
	for (int i = 0;i < size;i++)
		cin >> Int_Array3[i];
	cout << "The Function returns:" << Function(str5, Int_Array3, size) << "\n\n--------------------\n\n";

	cout << "Append an float array to string. Enter the string:";// add float_array to string
	string str6;
	cin >> str6;
	cout << "Enter size of float array:";
	cin >> size;
	float* Float_Array3 = new float[size];
	cout << "Enter array:";
	for (int i = 0;i < size;i++)
		cin >> Float_Array3[i];
	cout << "The Function returns:" << Function(str6, Float_Array3, size) << "\n\n--------------------\n\n";

	return 0;
}