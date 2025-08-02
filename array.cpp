#include <iostream>
using namespace std;


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
    int end = size;

    while(st <= end) {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
}

int main() {
    int arr[] = {5, 4, 30, 9, 2};
    reverseArr(arr, 5);
    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}