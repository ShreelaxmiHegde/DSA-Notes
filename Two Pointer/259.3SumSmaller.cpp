#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumSmaller(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int count = 0;

    for(int i=0; i<nums.size()-2; i++) {
        int j = i+1;
        int k = nums.size()-1;

        if(i>0 && nums[i] == nums[i-1]) continue;

        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if(sum < target) {
                count += (k-j);
                j++;
            } else {
                k--;
            }
        }
    }
    cout << count;
    return count;
}



int main() {
    vector<int> nums = {-2,0,1,3};
    threeSumSmaller(nums, 2);

    return 0;
}