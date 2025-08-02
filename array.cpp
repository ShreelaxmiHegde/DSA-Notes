#include <iostream>
using namespace std;


//**Arrays are passed by Reference**

int largestNumber(int arr[], int size) {
    // O(n)
    int largeNum = arr[0];
    for(int i=1; i<size; i++) {
        if(arr[i] > largeNum) {
            largeNum = arr[i];
        }
    }

    return largeNum;
}


void reverseArr(int arr[], int size) {
    //two pointer approach O(log n)
    int st = 0;
    int end = size-1;

    while(st <= end) {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
}

int main() {
    int arr[] = {5, 4, 30, 9, 2};

    int n = sizeof(arr)/sizeof(int); // get size of array //sizeof(arr) doesn't give arr size
    cout << "n = " << n << endl;

    // In C++, when you pass an array to a function, the array name (arr) is treated as a pointer to the first element.
    //void func(int arr[]); is effectively the same as void func(int *arr);
    //Both are interpreted the same way by the compiler when used as function parameters. Inside the function, arr behaves like a pointer (int*), not like a full array
    
    cout << arr << endl; //prints the first el location 
    cout << *(arr) << endl; //dereferences and gives the value at arr[0]
    cout << *(arr+1) << endl; // *(arr+1) = arr[1]
    
    reverseArr(arr, 5); //passing array name = passing ptr pointing to 0th idx of arr
    for(int i=0; i<5; i++) {
        cout << arr[i] << " "; 
    }
 
    



    // **Take Away**
    //when you pass an array to a function in C++, you're actually passing only the memory address of its first element — not the whole array.
    //This means the function has no idea how big the array is, unless you explicitly pass the size as a separate parameter.

    //constant pointer
            //int arr[] = {2, 4, 6};
            // int y = 10;
            // arr = &y;  // ❌ Error: incompatible types in assignment
    //arr is like a read-only pointer. The compiler allocates a fixed block of memory for it.
    //You can’t change where it points — unlike a normal pointer (int* ptr), which you can reassign.
    
    return 0;
}