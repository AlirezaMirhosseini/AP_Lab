//   BY   : Shapour Discover
//   DATE : 2021-03-10
//   TIME : 17:38

#include "point.h"
#include "PointArray.h"

using namespace std;

int main() {
	point arr[10];
	for (int i = 0;i < 10;i++) {
		arr[i].set_X(i + 1);
		arr[i].set_Y(5 * i + 1);
	}
	PointArray a(arr, 10);
	cout << "size:" << a.getSize() << endl;
	a.Print();
	cout << a.get(4)->get_length() << endl;
	cout << "---------------" << endl;
	point t(80, 20);
	a.PushBack(t);
	cout << "size:" << a.getSize() << endl;
	point temp(81, 21);
	a.insert(7, temp);
	a.Print();
	cout << "---------------" << endl;
	cout << "size:" << a.getSize() << endl;
	a.remove(4);
	a.Print();
	cout << "---------------" << endl;
	cout << "size:" << a.getSize() << endl;
	a.clear();
	a.Print();
	cout << "---------------" << endl;
	cout << "size:" << a.getSize() << endl;
	//cout << a.get(4)->get_length() << endl;
	PointArray b;
	point q(12, 16), w(3, 4), e(16, 30);
	b.PushBack(q);
	b.Print();
	cout << "---------------" << endl;
	cout << "size:" << b.getSize() << endl;
	b.PushBack(w);
	b.PushBack(e);
	b.Print();
	cout << "---------------" << endl;
	cout << "size:" << b.getSize() << endl;
	cout << b.get(2)->get_length();

	return 0;
}