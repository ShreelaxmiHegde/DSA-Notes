#include <iostream>
#include <vector>
using namespace std;



int longestSubarray(vector<int>& nums) {
    int left = 0;
    int maxLen = 0;
    int zeros = 0;

    for(int right=0; right<nums.size(); right++) {
        if(nums[right] == 0) {
            zeros++;
        } 

        while(zeros > 1) { // invalid window
            if(nums[left] == 0) {
                zeros--;
            }
            left++;
        }

        // window length minus one (the deleted element)
        maxLen = max(maxLen, right-left);
    }
    return maxLen;
}


int main() {

    return 0;
}