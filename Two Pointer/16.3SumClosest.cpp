#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int closestSum = nums[0] + nums[1] + nums[2];

    for(int i=0; i<nums.size()-2; i++) {
        int j = i+1; 
        int k = nums.size()-1;

        while(j < k) {
            int currSum = nums[i] + nums[j] + nums[k];

            if(abs(target - currSum) < abs(target - closestSum)) {
                closestSum = currSum;
            }

            if(currSum > target) { 
                k--;
            } else if(currSum < target) {
                j++;
            } else {
                return currSum;
            }
        }
    }
    cout << closestSum;
    return closestSum;
}

int main() {
    vector<int> nums = {1,1,1,1};
    threeSumClosest(nums, -100);

    return 0;
}