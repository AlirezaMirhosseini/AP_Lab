#include "Vector.h"

template <typename T>
Vector<T>::Vector() {
	Size = 0;
	arr = new T[Size];
}
template <typename T>
T* Vector<T>::get_array() { return arr; }
template <typename T>
Vector<T>::Vector(Vector& old) {
	Size = old.SIZE();
	arr = new T[Size];
	T* ptr = old.get_array();
	for (int i = 0;i < Size;i++)
		arr[i] = ptr[i];
}
template <typename T>
int Vector<T>::SIZE() { return Size; }
template <typename T>
void Vector<T>::push_back(T data) {
	T* temp_array = new T[Size];
	for (int i = 0;i < Size;i++)
		temp_array[i] = arr[i];
	Size++;
	arr = new T[Size];
	for (int i = 0;i < Size - 1;i++)
		arr[i] = temp_array[i];
	arr[Size - 1] = data;
	delete[] temp_array;
	cout << "Data added to rear successfully :)\n";
}
template <typename T>
void Vector<T>::push_front(T data) {
	T* temp_array = new T[Size];
	for (int i = 0;i < Size;i++)
		temp_array[i] = arr[i];
	Size++;
	arr = new T[Size];
	arr[0] = data;
	for (int i = 1;i < Size;i++)
		arr[i] = temp_array[i - 1];
	delete[] temp_array;
	cout << "Data added to front successfully :)\n";
}
template <typename T>
void Vector<T>::insert(int index, T data) {
	if (index >= Size || index < 0) {
		cout << "Index not found!" << endl;
		return;
	}
	T* temp_array = new T[Size];
	for (int i = 0;i < Size;i++)
		temp_array[i] = arr[i];
	Size++;
	arr = new T[Size];
	for (int i = 0;i < index;i++)
		arr[i] = temp_array[i];
	arr[index] = data;
	for (int i = index + 1;i < Size;i++)
		arr[i] = temp_array[i - 1];
	delete[] temp_array;
	cout << "Data inserted successfully :)\n";
}
template <typename T>
void Vector<T>::pop() {
	if (Size == 0) {
		cout << "List is empty!\n";
		return;
	}
	Size--;// --size   delete last index
	T* temp_array = new T[Size];
	for (int i = 0;i < Size;i++)
		temp_array[i] = arr[i];
	arr = new T[Size];
	for (int i = 0;i < Size;i++)
		arr[i] = temp_array[i];
	delete[] temp_array;
	cout << "List poped successfully :)" << endl;
}
template <typename T>
void Vector<T>::Delete(int index) {
	if (index >= Size || index < 0) {
		cout << "Index not found!" << endl;
		return;
	}
	T* temp_array = new T[Size];
	for (int i = 0;i < Size;i++)
		temp_array[i] = arr[i];
	Size--;
	arr = new T[Size];
	for (int i = 0;i < index;i++)
		arr[i] = temp_array[i];
	for (int i = index;i < Size;i++)
		arr[i] = temp_array[i + 1];
	delete[] temp_array;
	cout << "Data deleted successfully :)\n";
}
template <typename T>
int Vector<T>::search(T data) {
	for (int i = 0;i < Size;i++)
		if (arr[i] == data)
			return i;
	return -1;
}
template <typename T>
void Vector<T>::Swap(int index1, int index2) {
	if (index1 >= Size || index1 < 0 || index2 >= Size || index2 < 0) {
		cout << "Index not found!" << endl;
		return;
	}
	T temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
	cout << "These two indexes swap successfully :)\n";
}
template <typename T>
void Vector<T>::reverse() {
	if (Size == 0) {
		cout << "List is empty!\n";
		return;
	}
	T* temp_array = new T[Size];
	for (int i = 0;i < Size;i++)
		temp_array[i] = arr[i];
	arr = new T[Size];
	for (int i = Size - 1, j = 0;i >= 0;i--, j++)
		arr[j] = temp_array[i];
	cout << "List reversed successfully :)" << endl;
}
template <typename T>
void Vector<T>::sort() {
	if (Size == 0) {
		cout << "List is empty!\n";
		return;
	}
	for (int i = 0;i < Size;i++)
		for (int j = i + 1;j < Size;j++)
			if (arr[i] > arr[j]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	cout << "List sorted successfully :)" << endl;
}
template <typename T>
void Vector<T>::print_list() {
	if (Size == 0) {
		cout << "List is empty!\n";
		return;
	}
	cout << "\nList:\n\n";
	for (int i = 0;i < Size;i++)
		cout << i << " . " << arr[i] << endl;
}
template <typename T>
Vector<T>::~Vector() { delete[] arr; }