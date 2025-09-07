#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1); //store anwer
    stack<int> s; //stores indices

    for(int i=0; i<2*n; i++) { //run loop twice
        int num = nums[i % n];

        while(!s.empty() && nums[s.top()] < num) {
            ans[s.top()] = num;
            s.pop();
        }

        if(i < n) s.push(i);
    }

    return ans;
}