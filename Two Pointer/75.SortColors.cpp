#include <iostream>
#include <vector>
using namespace std;



void sortColors(vector<int>& nums) {
    int left = 0;
    int mid = 0;
    int right = nums.size()-1;

    while(mid <= right) {
        if(nums[mid] == 0) {
            swap(nums[mid], nums[left]);
            mid++; left++;
        } else if(nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[right]);
            right--;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 1, 1, 0};
    sortColors(nums);

    return 0;
}