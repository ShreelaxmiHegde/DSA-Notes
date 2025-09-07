#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


bool checkSum(vector<int>& nums, int k) {
    unordered_map<int, int>remIdx;

    remIdx[0] = -1;

    int runningSum = 0;

    for(int i=0; i<nums.size(); i++) {
        runningSum += nums[i];

        // n/0 not allowed
        int rem = (k == 0)? runningSum : runningSum % k;

        if(remIdx.find(rem) != remIdx.end()) {
            int prevIdx = remIdx[rem];
            if(i - prevIdx >= 2) {
                return true;
            }
        } else {
            remIdx[rem] = i;
        }
    }
    return false;
}


int main() {
    cout << 6%6;

    return 0;
}