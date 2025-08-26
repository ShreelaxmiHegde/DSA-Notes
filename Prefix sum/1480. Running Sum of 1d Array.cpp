#include <iostream>
#include <vector>
using namespace std;




vector<int> runningSum(vector<int>& nums) {
    vector<int> sum(nums.size());
    sum[0] = nums[0];

    for(int i=1; i<nums.size(); i++) {
        sum[i] = nums[i] + sum[i-1];
    }

    return sum;
}

int main() {

    return 0;
}