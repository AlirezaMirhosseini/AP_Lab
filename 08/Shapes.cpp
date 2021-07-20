//   BY   : Shapour Discover
//   DATE : 2021-05-07
//   TIME : 18:23

#include <iostream>
#include <iomanip>
#include <cmath>

#pragma warning(disable:4996)
using namespace std;

void Sort(float* Diameter, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (Diameter[i] < Diameter[j]) {
				float temp = Diameter[i];
				Diameter[i] = Diameter[j];
				Diameter[j] = temp;
			}
		}
	}
}

class point {
	float x;
	float y;
public:
	float get_x() { return x; }
	float get_y() { return y; }
	void set_x(float _x) { x = _x; }
	void set_y(float _y) { y = _y; }
};

class shape {
protected:
	string color;
	point* vertice;
public:
	virtual void set_data(int num) {
		int SIZE_NUM;
		if (num == 1) {
			vertice = new point[3];
			SIZE_NUM = 3;
		}
		else if (num == 2 || num == 3 || num == 4) {
			vertice = new point[4];
			SIZE_NUM = 4;
		}
		else if (num == 5) {
			vertice = new point[6];
			SIZE_NUM = 6;
		}
		else if (num == 6) {
			vertice = new point[8];
			SIZE_NUM = 8;
		}
		cin >> color;
		char ch1, ch2, ch3;
		scanf("%c%c%c", &ch1, &ch2, &ch3);
		float X, Y;
		for (int i = 0; i < SIZE_NUM; i++) {
			scanf("%f:%f", &X, &Y);
			vertice[i].set_x(X);
			vertice[i].set_y(Y);
		}
	}
	virtual void get_data() { return; }
	float area(point* v, int SIZE) {
		float Area = 0;
		for (int i = 0; i < SIZE; i++) {
			if (i != SIZE - 1)
				Area += v[i].get_x() *
				v[i + 1].get_y() - v[i].get_y() *
				v[i + 1].get_x();
			else
				Area += v[i].get_x() *
				v[0].get_y() - v[i].get_y() *
				v[0].get_x();
		}
		if (Area < 0)
			Area *= -1;
		return Area / 2;
	}

	float perimeter(point * v, int SIZE) {
		float Perimeter = 0;
		for (int i = 0; i < SIZE; i++) {
			if (i != SIZE - 1)
				Perimeter += sqrt((v[i].get_x() - v[i + 1].get_x()) *
				(v[i].get_x() - v[i + 1].get_x()) +
					(v[i].get_y() - v[i + 1].get_y()) *
					(v[i].get_y() - v[i + 1].get_y()));
			else
				Perimeter += sqrt((v[i].get_x() - v[0].get_x()) *
				(v[i].get_x() - v[0].get_x()) +
					(v[i].get_y() - v[0].get_y()) *
					(v[i].get_y() - v[0].get_y()));
		}
		return Perimeter;
	}
};


class Triangle :public shape {
public:
	void get_data() {
		cout << color << " : " << perimeter(vertice, 3) << " " << area(vertice, 3) << endl;
	}
};

class Rectangle :public shape {
public:
	void get_data() {
		cout << color << " : " << perimeter(vertice, 4) << " " << area(vertice, 4) << " ";
		float diameter[2];
		int d = 0;
		float Distance = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = i + 2; j < 4; j++) {
				if (i == 0 && j == 3)
					break;
				Distance = sqrt((vertice[i].get_x() - vertice[j].get_x()) *
					(vertice[i].get_x() - vertice[j].get_x()) +
					(vertice[i].get_y() - vertice[j].get_y()) *
					(vertice[i].get_y() - vertice[j].get_y()));
				diameter[d] = Distance;
				d++;
			}
		}
		Sort(diameter, 2);
		for (int i = 0; i < 2; i++)
			cout << diameter[i] << " ";
		cout << endl;
	}
};

class Dimond :public shape {
public:
	void get_data() {
		cout << color << " : " << perimeter(vertice, 4) << " " << area(vertice, 4) << " ";
		float diameter[2];
		int d = 0;
		float Distance = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = i + 2; j < 4; j++) {
				if (i == 0 && j == 3)
					break;
				Distance = sqrt((vertice[i].get_x() - vertice[j].get_x()) *
					(vertice[i].get_x() - vertice[j].get_x()) +
					(vertice[i].get_y() - vertice[j].get_y()) *
					(vertice[i].get_y() - vertice[j].get_y()));
				diameter[d] = Distance;
				d++;
			}
		}
		Sort(diameter, 2);
		for (int i = 0; i < 2; i++)
			cout << diameter[i] << " ";
		cout << endl;
	}
};

class Square :public shape {
public:
	void get_data() {
		cout << color << " : " << perimeter(vertice, 4) << " " << area(vertice, 4) << " ";
		float diameter[2];
		int d = 0;
		float Distance = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = i + 2; j < 4; j++) {
				if (i == 0 && j == 3)
					break;
				Distance = sqrt((vertice[i].get_x() - vertice[j].get_x()) *
					(vertice[i].get_x() - vertice[j].get_x()) +
					(vertice[i].get_y() - vertice[j].get_y()) *
					(vertice[i].get_y() - vertice[j].get_y()));
				diameter[d] = Distance;
				d++;
			}
		}
		Sort(diameter, 2);
		for (int i = 0; i < 2; i++)
			cout << diameter[i] << " ";
		cout << endl;
	}
};

class Hexagonal :public shape {
public:
	void get_data() {
		cout << color << " : " << perimeter(vertice, 6) << " " << area(vertice, 6) << " ";
		float diameter[9];
		int d = 0;
		float Distance = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = i + 2; j < 6; j++) {
				if (i == 0 && j == 5)
					break;
				Distance = sqrt((vertice[i].get_x() - vertice[j].get_x()) *
					(vertice[i].get_x() - vertice[j].get_x()) +
					(vertice[i].get_y() - vertice[j].get_y()) *
					(vertice[i].get_y() - vertice[j].get_y()));
				diameter[d] = Distance;
				d++;
			}
		}
		Sort(diameter, 9);
		for (int i = 0; i < 9; i++)
			cout << diameter[i] << " ";
		cout << endl;
	}
};

class Octagonal :public shape {
public:
	void get_data() {
		cout << color << " : " << perimeter(vertice, 8) << " " << area(vertice, 8) << " ";
		float diameter[20];
		int d = 0;
		float Distance = 0;
		for (int i = 0; i < 6; i++) {
			for (int j = i + 2; j < 6; j++) {
				if (i == 0 && j == 7)
					break;
				Distance = sqrt((vertice[i].get_x() - vertice[j].get_x()) *
					(vertice[i].get_x() - vertice[j].get_x()) +
					(vertice[i].get_y() - vertice[j].get_y()) *
					(vertice[i].get_y() - vertice[j].get_y()));
				diameter[d] = Distance;
				d++;
			}
		}
		Sort(diameter, 20);
		for (int i = 0; i < 20; i++)
			cout << diameter[i] << " ";
		cout << endl;
	}
};

int main() {
	cout << setprecision(2) << fixed;
	int n;
	cin >> n;
	int* TYPE = new int[n];
	for (int i = 0; i < n; i++)
		cin >> TYPE[i];
	shape** sh = new shape * [n];
	for (int i = 0; i < n; i++) {
		if (TYPE[i] == 1) 
			sh[i] = new Triangle;
		else if (TYPE[i] == 2) 
			sh[i] = new Rectangle;
		else if (TYPE[i] == 3) 
			sh[i] = new Dimond;
		else if (TYPE[i] == 4) 
			sh[i] = new Square;
		else if (TYPE[i] == 5) 
			sh[i] = new Hexagonal;
		else if (TYPE[i] == 6) 
			sh[i] = new Octagonal;
		sh[i]->set_data(TYPE[i]);
	}
	for (int i = 0; i < n; i++) 
		sh[i]->get_data();
	return 0;
}