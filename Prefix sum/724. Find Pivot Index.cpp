#include <iostream>
#include <vector>
using namespace std;



int pivotIndex(vector<int>& nums) {
    vector<int> prefix;
    prefix.push_back(nums[0]);

    for(int i=1; i<nums.size(); i++) {
        prefix.push_back(nums[i] + prefix[i-1]);
    }

    for(int i=0; i<prefix.size(); i++) {
        int leftSum = (i==0)? 0 : prefix[i-1];
        int rightSum = prefix[prefix.size()-1]-prefix[i];
        if(leftSum == rightSum) {
            return i;
        }
    }

    return -1;
}
 
int main() {

    return 0;
}