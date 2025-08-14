#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size()-2; i++) {
        int j = i+1; 
        int k = nums.size()-1;

        if(i>0 && nums[i] == nums[i-1]) continue;

        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if(sum < 0) { 
                k--;
            } else if(sum > 0) {
                j++;
            } else {
                res.push_back({nums[i], nums[j], nums[k]});
                cout << nums[i] << "," << nums[j] << "," << nums[k] << endl;
                while(j<k && nums[j] == nums[j+1]) ++j;
                while(j<k && nums[k] == nums[k-1]) --k;
                ++j; --k;
            }
        }
    }

    return res;
}

int main() {
    vector<int> nums = {1,1,1,1};
    threeSum(nums);

    return 0;
}
