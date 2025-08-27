#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
    int count = 0;

    vector<int> prefix(nums.size());
    prefix[0] = nums[0];
    for(int i=1; i<nums.size(); i++) {
        prefix[i] = nums[i] + prefix[i-1];
    }

    unordered_map<int, int> m;
    for(int i=0; i<nums.size(); i++) {
        if(prefix[i] == k) {
            count++;
        }

        if(m.find(prefix[i]-k) != m.end()) {
            count += m[prefix[i]-k];
        }

        m[prefix[i]]++;
    }
}

int main() {

    return 0;
}