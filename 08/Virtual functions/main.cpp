//   BY   : Shapour Discover
//   DATE : 2021-05-05
//   TIME : 19:06

#include "Professor.h"
#include "Student.h"

int main(){
    int n, val;
    cin >> n; //The number of objects that is going to be created.
    //Person *per[n];
	//Person** per = new Person * [n];
	Person** per = nullptr;
	per = new Person * [n];
    for(int i = 0;i < n;i++){
        cin >> val;
        if(val == 1)
            per[i] = new Professor; // If val is 1 current object is of type Professor
        else 
			per[i] = new Student; // Else the current object is of type Student
        per[i]->getdata(); // Get the data from the user.
    }
    for(int i = 0;i < n;i++)
        per[i]->putdata(); // Print the required output for each object.
    return 0;
}