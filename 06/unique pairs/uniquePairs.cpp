#include "uniquePairs.h"

template <typename T, typename Y>
uniquePairs<T, Y>::uniquePairs(){
	Size = 0;
	Key = new T[Size];
	Value = new Y[Size];
}
template <typename T, typename Y>
uniquePairs<T, Y> uniquePairs<T, Y>::operator=(const uniquePairs<T, Y>& obj) {
	Size = obj.Size;
	Key = new T[Size];
	for (int i = 0; i < Size; i++)
		Key[i] = obj.Key[i];
	Value = new Y[Size];
	for (int i = 0; i < Size; i++)
		Value[i] = obj.Value[i];
	return *this;
}
template <typename T, typename Y>
uniquePairs<T, Y>::uniquePairs(const uniquePairs<T, Y>& obj) {
	Size = obj.Size;
	Key = new T[Size];
	for (int i = 0; i < Size; i++)
		Key[i] = obj.Key[i];
	Value = new Y[Size];
	for (int i = 0; i < Size; i++)
		Value[i] = obj.Value[i];
}
template <typename T, typename Y>
void uniquePairs<T, Y>::insert(T _Key, Y _Value) {
	for (int i = 0; i < Size; i++) {
		if (Key[i] == _Key) {
			Value[i] = _Value;
			cout << "We already have " << _Key << " , But its value replaced." << endl;
			return;
		}
	}
	T* temp_Key = new T[Size];
	Y* temp_Value = new Y[Size];
	for (int i = 0; i < Size; i++) {
		temp_Key[i] = Key[i];
		temp_Value[i] = Value[i];
	}
	Size++;
	Key = new T[Size];
	Value = new Y[Size];
	for (int i = 0; i < Size - 1; i++) {
		Key[i] = temp_Key[i];
		Value[i] = temp_Value[i];
	}
	Key[Size - 1] = _Key;
	Value[Size - 1] = _Value;
	delete[] temp_Key;
	delete[] temp_Value;
}
template <typename T, typename Y>
void uniquePairs<T, Y>::remove(T _Key) {
	for(int i=0;i<Size;i++)
		if (Key[i] == _Key) {
			Size--;
			T* temp_Key = new T[Size];
			Y* temp_Value = new Y[Size];
			for (int j = 0; j < i; j++) {
				temp_Key[j] = Key[j];
				temp_Value[j] = Value[j];
			}
			for (int j = i; j < Size; j++) {
				temp_Key[j] = Key[j + 1];
				temp_Value[j] = Value[j + 1];
			}
			Key = new  T[Size];
			Value = new Y[Size];
			for (int j = 0; j < Size; j++) {
				Key[j] = temp_Key[j];
				Value[j] = temp_Value[j];
			}
			delete[] temp_Key;
			delete[] temp_Value;
			return;
		}
	cout << "404 Error!... Key not found :(" << endl;
}
template <typename T, typename Y>
int uniquePairs<T, Y>::SIZE() { return Size; }
template <typename T, typename Y>
Y uniquePairs<T, Y>::operator[](T _Key) const {
	int i = 0;
	for (i = 0; i < Size; i++) {
		if (Key[i] == _Key) {
			return Value[i];
		}
	}
}
template <typename T, typename Y>
Y& uniquePairs<T, Y>::operator[](T _Key) {
	int i = 0;
	for (i = 0; i < Size; i++) {
		if (Key[i] == _Key) {
			return Value[i];
		}
	}
	//if (sizeof(Y) == 32) {
	//	string a = "ali";
	//	this->insert(_Key, a);
	//}
	//else {
	//	this->insert(_Key, 0);
	//}
	this->insert(_Key, 0);
	return Value[Size - 1];
}
template <typename T, typename Y>
uniquePairs<T, Y> uniquePairs<T, Y>::operator-(const uniquePairs<T, Y>& _obj) {
	uniquePairs<T, Y> new_obj = *this;
	for (int i = 0; i < new_obj.Size; i++) {
		for (int j = 0; j < _obj.Size; j++) {
			if (new_obj.Key[i] == _obj.Key[j] && new_obj.Value[i] == _obj.Value[j]) {
				new_obj.remove(new_obj.Key[i]);
			}
		}
	}
	return new_obj;
}
template <typename T, typename Y>
ostream& operator<<(ostream& out, const uniquePairs<T, Y>& _obj) {
	out << "We have " << _obj.Size << " pairs:" << endl;
	out << "{";
	for (int i = 0; i < _obj.Size; i++) {
		out << "(" << _obj.Key[i] << "," << _obj.Value[i] << ")";
		if (i != _obj.Size - 1)
			out << " , ";
	}
	out << "}" << endl;
	return out;
}
template <typename T, typename Y>
uniquePairs<T, Y>::~uniquePairs() {
	delete[] Key;
	delete[] Value;
}