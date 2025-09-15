#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void twoSum(vector<int> nums, int tar) {
    unordered_map<int, int> m; // nums[i], idx

    for(int i=0; i<nums.size(); i++) {
        int comp = tar - nums[i];
        if(m.find(m[comp]) != m.end()) {
            cout << "ans:"<< m[comp] << "," << i << endl;
        }

        m[nums[i]] = comp;
    } 
}


int main() {

    vector<int> nums = {10,2,4,1,5,9}; 
    int tar = 6;
    twoSum(nums, tar);

    return 0;
}