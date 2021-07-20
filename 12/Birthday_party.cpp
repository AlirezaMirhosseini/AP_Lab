//   BY   : Shapour Discover
//   DATE : 2021-06-16
//   TIME : 16:34

#include <iostream>
#include <vector>

using namespace std;

struct points {
	int x, y;
	bool Delete;
	points() {
		Delete = 0;
		cin >> x >> y;
	}
};
struct equations {
	int a, b, c;
	equations() { cin >> a >> b >> c; }
	bool Position(int x, int y) {
		if (a * x + b * y + c > 0)
			return true;
		return false;
	}
};
int main(void) {
	int temp = 0;
	int n, m, r, candle_count = 0, i, j, k;
	bool two_candle = 0;
	cin >> n >> m >> r;
	vector<points> point(n);
	vector<equations> equation(m);
	for (i = 0; i < n; i++)
		if (!point[i].Delete)
			for (j = i + 1; j < n; j++)
				if (!point[j].Delete) {
					temp = 0;
					for (k = 0; k < m; k++) {
						if (equation[k].Position(point[i].x, point[i].y) == equation[k].Position(point[j].x, point[j].y)) {
							temp++;
							if (temp == m) {
								point[j].Delete = 1;
								if (!two_candle) {
									cout << "YES\n";
									two_candle = 1;
								}
								candle_count++;
							}
						}
						else
							break;
					}
				}
	if (!two_candle)
		cout << "NO\n";
	cout << n - candle_count;
}