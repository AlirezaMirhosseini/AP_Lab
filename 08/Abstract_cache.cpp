//   BY   : Shapour Discover
//   DATE : 2021-05-09
//   TIME : 15:00

#include <iostream>

using namespace std;

class Cache {
protected:
	//data structure
	int cp;  //capacity
	Cache() { cp = 0; }
	Cache(int _cp) { cp = _cp; }
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function
};

class Cache_array :public Cache {
	int* key;
	int* val;
public:
	Cache_array() :Cache() { 
		cp = 0;
		key = nullptr;
		val = nullptr;
	}
	Cache_array(int _cp) :Cache(_cp) {
		cp = _cp;
		key = new int[cp];
		val = new int[cp];
	}
	void set(int _key, int _val) {
		for (int i = 0; i < cp; i++)
			if (key[i] == _key) {
				for (int j = i; j >= 1; j--) {
					key[j] = key[j - 1];
					val[j] = val[j - 1];
				}
				key[0] = _key;
				val[0] = _val;
				return;
			}
		for (int i = cp - 1; i >= 1; i--) {
			key[i] = key[i - 1];
			val[i] = val[i - 1];
		}
		key[0] = _key;
		val[0] = _val;
	}
	int get(int _key) {
		for (int i = 0; i < cp; i++)
			if (key[i] == _key)
				return val[i];
		return -1;
	}
};

int main() {
	int commands_count, capacity;
	cin >> commands_count >> capacity;
	Cache_array cache(capacity);
	string command;
	for (int i = 0; i < commands_count; i++) {
		cin >> command;
		int key, val;
		if (command == "set") {
			cin >> key >> val;
			cache.set(key, val);
		}
		else if (command == "get") {
			cin >> key;
			cout << cache.get(key) << endl;
		}
	}
	return 0;
}