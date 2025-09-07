#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int niceSubarr(vector<int> nums, int k) {
    int count = 0;

    unordered_map<int, int> m; //<prefixsum,freq>
    m[0] = 1;

    int sum = 0;

    for(int i=0; i<nums.size(); i++) {
        sum += (nums[i]%2);

        cout << sum << " ";
        if(m.count(sum-k)) {
            count += m[sum-k];
        }

        m[sum]++;
    }

    return count;
}

int main() {
    vector<int> n = {1,1,2,1,1};
    cout << niceSubarr(n, 3);

    return 0;
}