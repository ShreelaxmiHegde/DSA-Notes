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
}