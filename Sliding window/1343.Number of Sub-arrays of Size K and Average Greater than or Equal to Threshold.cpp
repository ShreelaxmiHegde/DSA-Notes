#include <iostream>
#include <vector>
using namespace std;



int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int left = 0;
    int count = 0;
    int sum = 0;

    for(int right = 0; right<arr.size(); right++) {
        sum += arr[right];

        if(right - left + 1 > k) {
            sum -= arr[left];
            left++;
        }

        if(right - left + 1 == k) {
            if((sum/k) >= threshold) {
                count++;
            }
        }
        
    }
    return count;
}



int main() {
    vector<int> arr = {2,2,2,2,5,5,5,8}; 
    int k = 3, threshold = 4;
    
    return 0;
}