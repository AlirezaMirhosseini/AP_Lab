//   BY   : Shapour Discover
//   DATE : 2021-04-12
//   TIME : 20:06

#include <iostream>

#pragma warning(disable:4996)

using namespace std;

template <class T>
class Storage {
private:
	T m_value;
public:
    Storage(T value){ m_value = value;}
    void print() { cout << m_value << '\n'; }
    ~Storage() {}
};
template <class T>
class Storage<T*> {
private:
    T* m_value;
public:
    Storage(T* value) { m_value = new T(*value);; }
    void print() { cout << *m_value << '\n'; }
    ~Storage() { delete m_value; }
};
template <>
Storage<char*>::Storage(char* value) {
    int SIZE = 0;
    while (value[SIZE] != '\0') {
        SIZE++;
    }
    SIZE++;
    m_value = new char[SIZE];
    for (int i = 0; i < SIZE;i++)
        m_value[i] = value[i];
}
template<>
void Storage<char*>::print() { cout << m_value << '\n'; }
template<>
Storage<char*>::~Storage() { delete[] m_value; }

int main() {
    Storage<int> myint(5);
    myint.print();

    double x = 7.5;
    Storage<double*> myintptr(&x);

    x = 9;
    myintptr.print();

    char* name = new char[40];
    strcpy(name, "Alex");

    Storage< char*> myname(name);

    delete[] name;

    myname.print();
    //----------------------------------
    /*char* string = new char[40];

    cout << "Enter your name: ";
    cin >> string;

    Storage<char*> storage(string);

    delete[] string;

    storage.print();*/
    //----------------------------------
    /*Storage<int> myint(5);
    myint.print();

    int x = 7;
    Storage<int*> myintptr(&x);

    x = 9;
    myintptr.print();*/
    //----------------------------------


	return 0;
}