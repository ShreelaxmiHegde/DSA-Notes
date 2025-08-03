#include <iostream>
#include <algorithm>
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

void printSubarray(int arr[], int size) {  // O(n^3)
    cout << "Subarrays :" << endl;
    for(int st=0; st<size; st++) { // Iterate over all possible starting indices of subarrays
        for(int end=st; end<size; end++) { // For each starting index, iterate over possible ending indices
            for(int i=st; i<=end; i++) { // Print elements from current start to current end (inclusive)
                cout << arr[i] << " ";
            }
            cout << endl; // Print newline after each subarray
        }
    }
}

int maxSubarraySum(int arr[], int size) {
    //approach 1:like printing subarray calculate sum and compare to get max O(n^3)
    //approach 2: O(n^2)
    int maxSum = 0;
    for(int st=0; st<size; st++) {  // Loop through every possible start index of a subarray.
        int currSum = 0;
        for(int end=st; end<size; end++) {  // For each start, loop through every possible end index.
            currSum += arr[end]; // Keep adding values to currSum from st to end.
            maxSum = max(currSum, maxSum); // Update maxSum whenever currSum exceeds it.
        }
    }
    

    //approach 3: Kadane's Algo O(n)
    int currSum = 0; 
    // int maxSum = 0;
    for(int i=0; i<size; i++) {
        if(currSum < 0) currSum = 0;
        
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
    }
    
    return maxSum;
}

int main() {
    int arr[] = {-3, 90, -7, 2, 3};

    int n = sizeof(arr)/sizeof(arr[0]); // get size of array //sizeof(arr) doesn't give arr size
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