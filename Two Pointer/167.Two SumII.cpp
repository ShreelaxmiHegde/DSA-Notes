#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSumII(vector<int> nums, int targate) {
    vector<int> res;
    
    int st = 1, end = nums.size(); 
    while(st <= end) {
        int sum = nums[st-1] + nums[end-1];
        
        if(sum == targate) {
            res.push_back(st);
            res.push_back(end);
            return res;
        }

        if(sum > targate) {
            end--;
        } else {
            st++;
        }
    }

    return res;
}

int main() {

    vector<int> nums = {2, 7, 11, 15};
    int targate = 9;
    twoSumII(nums, targate);



    return 0;
}