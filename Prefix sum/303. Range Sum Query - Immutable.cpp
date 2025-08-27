#include <iostream>
#include <vector>
using namespace std;

class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++) {
            prefix.push_back(nums[i] + prefix[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefix[right];
        return prefix[right]-prefix[left-1];
    }
};


int main() {



    return 0;
}