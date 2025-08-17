#include <iostream>
#include <vector>
using namespace std;


double maxAverageSubarray(vector<int> &nums, int k) {
    double currSum = 0;
    double maxAvg = -1e9;   // very small number initially
    int left = 0;

    for(int right=0; right<nums.size(); right++) {
        currSum += nums[right];

        // shrink window if it's bigger than k
        if(right-left + 1 > k) {
            currSum -= nums[left];
            left++;
        }
        
        // when window size == k, update maxAvg
        if(right-left + 1 == k) {
            maxAvg = max(maxAvg, (currSum/k));
        }
    }
    cout << maxAvg << endl;
    return maxAvg;
}

int main() {
    
    vector<int> nums = {1,12,-5,-6, 50,3};
    int k = 4;
    maxAverageSubarray(nums, k);

    return 0;
}