#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0);
    stack<int> s; //store indices

    for(int i=0; i<n; i++) {
        while(!s.empty() && temp[s.top()] < temp[i]) { // compare temperature 
            ans[s.top()] = i - s.top(); // store number of days
            s.pop();
        }

        s.push(i);
    }

    return ans;
}