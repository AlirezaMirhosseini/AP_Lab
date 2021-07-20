//   BY   : Shapour Discover
//   DATE : 2021-04-26
//   TIME : 23:35

#include "Polynomial.h"

int main() {
	Polynomial p1,p2;
    cin>>p1>>p2;
    Polynomial p3=p1*p2,p4;
    p4=2-p1;
    cout<<p1+p2<<endl;
    cout<<p4<<endl;
    cout<<p3<<endl;
    cout<<p2*3<<endl;
	return 0;
}
/*-x^2-3+2x^3+4
-7x^2-9x^3+9x-1
-8-x^2+3x+189x^4-1-5x^3  */