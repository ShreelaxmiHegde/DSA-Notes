#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> sortedSquares1(vector<int>& nums) { //O(n log n)
    vector<int> res;

    for(int i=0; i<nums.size(); i++) { // O(n)
        res.push_back(nums[i]*nums[i]);
    }

    sort(res.begin(), res.end()); //O(n log n)
    return res;
}

vector<int> sortedSquares2(vector<int>& nums) { //O(n)
    vector<int> res(nums.size());
    
    int st=0, end=nums.size()-1;
    int pos = nums.size()-1;

    while(st <= end) {
        if(abs(nums[st]) > abs(nums[end])) {
            res[pos] = nums[st] * nums[st];
            st++;
        } else {
            res[pos] = nums[end] * nums[end];
            end--;
        }
        pos--;
    }

    for(int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }

    return res;
}


int main() {
    vector<int> nums = {-4,-1,0,3,10};
    sortedSquares2(nums);

    

    return 0;
}