<<<<<<< HEAD
#include <iostream>
using namespace std;

void passByVal(int a) {
    // parameter(a) is copy of passed argument(x)
    a = 30;
    cout << "a = " << a << endl;
}

void passByRefPtr(int *ptr) { //address passed
    // the argument and parameter point to same location so any change in variable function will reflect to original var
    *ptr = 30;
    cout << "*ptr = " << *ptr << endl;
}

void passByRefVar(int &a) {
    //pass by reference using variables
    a = 60;
    cout << "a = " << a << endl;
}

const int a = 10;
int main() {

    // pointers -> store address

    int a = 10;

    // & operator -> address of a variable
    int* ptr = &a; // ptr storing address of a

    // meanings of *
    // 1. declaration -> to store address 
    // 2. usage -> to dereference the pointer

    cout << &a << " = " << ptr << endl;
    cout << a << " = " << *ptr << endl;

    *ptr = 50; //modifying value by accessing location
    cout << "a = " << a << endl;

    //NULL pointer (doesn't point to any location)
    int* ptr1; //points towards random garbeg value -> use null initialization
    int* ptr2 = NULL; //address -> 0x0 
    //cout << *ptr2; //segmentation fault error(not possible to dereference)

    int x = 10;
    passByVal(x); 
    cout << "x = " << x << endl; // no change in x

    passByRefPtr(&x); //passing address
    cout << "x = " << x << endl; //change will reflect


    //Reference variable
    //a=50
    int &b = a; // a&b refer to the same location in memory //&b should always be initialize
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    passByRefVar(a);
    cout << "b = " << b << endl;

    return 0;
=======
#include <iostream>
using namespace std;


int main() {

    // pointers -> store address

    int a = 10;

    // & operator -> address of a variable
    int* ptr = &a; // ptr storing address of a

    // meanings of *
    // 1. declaration -> to store address 
    // 2. usage -> to dereference the pointer

    cout << &a << " = " << ptr << endl;
    cout << a << " = " << *ptr << endl;
    

    return 0;
>>>>>>> 017225a7effa5d9d1a63ca99a2d0b812d93c5dd4
}