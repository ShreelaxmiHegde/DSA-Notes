#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> m; //<prefixSum, freq>
    m[0] = 1; // base case: empty prefix
    int count = 0;
    int sum = 0; 

    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];

        if(m.count(sum-goal)) { 
            count += m[sum-goal]; // add all previous matches
        }

        m[sum]++;
    }

    return count;
}