#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int subarraysDivByK(vector<int>& nums, int k) {
    //stores <rem, count>
    unordered_map<int, int> remCount;
    remCount[0] = 1; //prefixsum divisible by k

    int prefixSum = 0;
    int count = 0; //total counts

    for(int i=0; i<nums.size(); i++) {
        prefixSum += nums[i];

        int rem = ((prefixSum % k) + k) % k; // handle negatives

        if(remCount.count(rem)) { // if this remainder was seen before, those many subarrays end here
            count += remCount[rem];
        }

        remCount[rem]++;
    }
    return count;
}