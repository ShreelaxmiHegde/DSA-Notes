#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size()-3; i++) {
        while(i > 0 && nums[i] == nums[i-1]) continue;

        for(int j=i+1; j<nums.size()-2; j++) {
            while((j > i + 1) && nums[j] == nums[j-1]) continue;

            int k = j + 1;
            int l = nums.size()-1;

            while(k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if(sum < target) {
                    k++;
                } else if(sum > target) {
                    l--;
                } else {
                    res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    cout << nums[i] << "," << nums[j] << "," << nums[k] << "," << nums[l] << endl;
                    //remove duplicates of left and right
                    while(k < l && nums[k] == nums[k+1]) k++;
                    while(k < l && nums[l] == nums[l-1]) l--;

                    k++; l--;
                }
            }
            cout << "hajsdfh";
        }
    }
    return res;
}


int main() {
    vector<int> nums = {3,-1,0,4,5};
    fourSum(nums, 0);

    return 0;
}