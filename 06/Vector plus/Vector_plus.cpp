#include "Vector_plus.h"

template <typename T>
Vector_plus<T>::Vector_plus() {
	Size = 0;
	arr = new T[Size];
}
template <typename T>
T* Vector_plus<T>::get_array() { return arr; }
template <typename T>
void Vector_plus<T>::set_array(T* Array) { arr = Array; }
template <typename T>
Vector_plus<T>::Vector_plus(const Vector_plus<T>& old) {
	Size = old.Size;
	arr = new T[Size];
	T* ptr = old.arr;
	for (int i = 0; i < Size; i++)
		arr[i] = ptr[i];
}
template <typename T>
int Vector_plus<T>::SIZE() { return Size; }
template <typename T>
void Vector_plus<T>::set_size(int _size) { Size = _size; }
template <typename T>
void Vector_plus<T>::push_back(T data) {
	T* temp_array = new T[Size];
	for (int i = 0; i < Size; i++)
		temp_array[i] = arr[i];
	Size++;
	arr = new T[Size];
	for (int i = 0; i < Size - 1; i++)
		arr[i] = temp_array[i];
	arr[Size - 1] = data;
	delete[] temp_array;
	cout << "Data added to rear successfully :)\n";
}
template <typename T>
void Vector_plus<T>::push_front(T data) {
	T* temp_array = new T[Size];
	for (int i = 0; i < Size; i++)
		temp_array[i] = arr[i];
	Size++;
	arr = new T[Size];
	arr[0] = data;
	for (int i = 1; i < Size; i++)
		arr[i] = temp_array[i - 1];
	delete[] temp_array;
	cout << "Data added to front successfully :)\n";
}
template <typename T>
void Vector_plus<T>::insert(int index, T data) {
	if (index >= Size || index < 0) {
		cout << "Index not found!" << endl;
		return;
	}
	T* temp_array = new T[Size];
	for (int i = 0; i < Size; i++)
		temp_array[i] = arr[i];
	Size++;
	arr = new T[Size];
	for (int i = 0; i < index; i++)
		arr[i] = temp_array[i];
	arr[index] = data;
	for (int i = index + 1; i < Size; i++)
		arr[i] = temp_array[i - 1];
	delete[] temp_array;
	cout << "Data inserted successfully :)\n";
}
template <typename T>
void Vector_plus<T>::pop() {
	if (Size == 0) {
		cout << "List is empty!\n";
		return;
	}
	Size--;// --size   delete last index
	T* temp_array = new T[Size];
	for (int i = 0; i < Size; i++)
		temp_array[i] = arr[i];
	arr = new T[Size];
	for (int i = 0; i < Size; i++)
		arr[i] = temp_array[i];
	delete[] temp_array;
	cout << "List poped successfully :)" << endl;
}
template <typename T>
void Vector_plus<T>::Delete(int index) {
	if (index >= Size || index < 0) {
		cout << "Index not found!" << endl;
		return;
	}
	T* temp_array = new T[Size];
	for (int i = 0; i < Size; i++)
		temp_array[i] = arr[i];
	Size--;
	arr = new T[Size];
	for (int i = 0; i < index; i++)
		arr[i] = temp_array[i];
	for (int i = index; i < Size; i++)
		arr[i] = temp_array[i + 1];
	delete[] temp_array;
	cout << "Data deleted successfully :)\n";
}
template <typename T>
int Vector_plus<T>::search(T data) {
	for (int i = 0; i < Size; i++)
		if (arr[i] == data)
			return i;
	return -1;
}
template <typename T>
void Vector_plus<T>::Swap(int index1, int index2) {
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
void Vector_plus<T>::reverse() {
	if (Size == 0) {
		cout << "List is empty!\n";
		return;
	}
	T* temp_array = new T[Size];
	for (int i = 0; i < Size; i++)
		temp_array[i] = arr[i];
	arr = new T[Size];
	for (int i = Size - 1, j = 0; i >= 0; i--, j++)
		arr[j] = temp_array[i];
	cout << "List reversed successfully :)" << endl;
}
template <typename T>
void Vector_plus<T>::sort() {
	if (Size == 0) {
		cout << "List is empty!\n";
		return;
	}
	for (int i = 0; i < Size; i++)
		for (int j = i + 1; j < Size; j++)
			if (arr[i] > arr[j]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	cout << "List sorted successfully :)" << endl;
}
template <typename T>
void Vector_plus<T>::print_list() {
	if (Size == 0) {
		cout << "List is empty!\n";
		return;
	}
	cout << "\nList:\n\n";
	for (int i = 0; i < Size; i++)
		cout << i << " . " << arr[i] << endl;
}
template <typename T>
Vector_plus<T>& Vector_plus<T>::operator=(const Vector_plus<T>& old_obj) {
	Size = old_obj.Size;
	arr = new T[Size];
	T* ptr = old_obj.arr;
	for (int i = 0; i < Size; i++)
		arr[i] = ptr[i];
	return *this;
}
template <typename T>
Vector_plus<T> Vector_plus<T>::operator+(const Vector_plus<T>& _obj) {
	Vector_plus<T> new_obj = *this;
	T* temp_array = _obj.arr;
	for (int i = 0; i < _obj.Size; i++)
		new_obj.push_back(temp_array[i]);
	return new_obj;
}
template <typename T>
T& Vector_plus<T>::operator[](int index) {
	if (index < 0 || index >= Size) {
		cout << "Index " << index << " is out of bounds." << endl;
		exit(0);
	}
	return arr[index];
}
template <typename T>
Vector_plus<T> Vector_plus<T>::operator+(const T& data) {
	Vector_plus<T> new_obj = *this;
	new_obj.push_back(data);
	return new_obj;
}
template <typename T>
Vector_plus<T> operator+(const T& data, Vector_plus<T>& _obj) {
	Vector_plus<T> new_obj = _obj;
	new_obj.push_front(data);
	return new_obj;
}
template <typename T>
Vector_plus<T>& Vector_plus<T>::operator+=(const Vector_plus<T>& _obj) {
	T* temp_array = _obj.arr;
	for (int i = 0; i < _obj.Size; i++)
		this->push_back(temp_array[i]);
	return *this;
}
template <typename T>
Vector_plus<T>& Vector_plus<T>::operator+=(const T& data) {
	this->push_back(data);
	return *this;
}
template <typename T>
bool Vector_plus<T>::operator==(const Vector_plus<T>& _obj) {
	if (this->Size != _obj.Size)
		return false;
	T* temp_array = _obj.arr;
	for (int i = 0; i < Size; i++)
		if (arr[i] != temp_array[i])
			return false;
	return true;
}
template <typename T>
ostream& operator<<(ostream& out, Vector_plus<T>& _obj) {
	if (_obj.SIZE() == 0) {
		out << "List is empty!\n";
		return out;
	}
	T* temp_array = _obj.get_array();
	out << "\nList:\n\n";
	for (int i = 0; i < _obj.SIZE(); i++)
		out << i << " . " << temp_array[i] << endl;
	return out;
}
template <typename T>
Vector_plus<T>::~Vector_plus() {
	delete[] arr;
}