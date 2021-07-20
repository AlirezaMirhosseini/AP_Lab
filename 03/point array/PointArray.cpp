#include "PointArray.h"

using namespace std;

PointArray::PointArray() {resize(0);}
PointArray::PointArray(const point points[], const int size2) {
	size = size2;
	array_pointer = new point[size];
	for (int i = 0;i < size;i++) 
		array_pointer[i] = points[i];
}
void PointArray::resize(const int n) {
	size = n;
	point* temp = array_pointer;
	array_pointer = new point[n];
	for (int i = 0;i < n;i++) 
		array_pointer[i] = temp[i];
	delete[] temp;
}
void PointArray::PushBack(const point& p){
	resize(size + 1);
	array_pointer[size - 1] = p;
}
void PointArray::insert(const int position, const point& p){
	if (position > size || position < 0) {
		cout << "position not found!" << endl;
		return;
	}
	resize(size + 1);
	for (int i = size - 2;i >= position;i--) {
		array_pointer[i + 1] = array_pointer[i];
	}
	array_pointer[position] = p;
}
void PointArray::remove(const int pos){
	if (pos > size || pos < 0) {
		cout << "position not found!" << endl;
		return;
	}
	for (int i = pos;i < size - 1;i++) {
		array_pointer[i] = array_pointer[i + 1];
	}
	resize(size - 1);
}
const int PointArray::getSize() const {return size;}
void PointArray::clear() {resize(0);}
point* PointArray::get(const int position) {
	if (position > size || position < 0) {
		cout << "position not found!" << endl;
		return NULL;
	}
	return &array_pointer[position];
}
const point* PointArray::get(const int position) const {
	if (position > size || position < 0) {
		cout << "position not found!" << endl;
		return NULL;
	}
	return &array_pointer[position];
}
void PointArray::Print() {
	if (size == 0) {
		cout << "array is empty :)" << endl;
	}
	for (int i = 0;i < size;i++) {
		cout << i << ".(" << array_pointer[i].get_X() << "," << array_pointer[i].get_Y() << ")" << endl;
	}
}
PointArray::~PointArray() {delete[] array_pointer;}