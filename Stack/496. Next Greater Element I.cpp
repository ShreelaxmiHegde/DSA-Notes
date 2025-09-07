#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


void nextGreater(vector<int> nums1, vector<int> nums2) {
    unordered_map<int, int> m; //<el, greater>
    stack<int> s;

    for(int num : nums2) {
        while(!s.empty() && s.top() < num) {
            m[s.top()] = num;
            cout << s.top() << " ";
            s.pop();
        }
        s.push(num);
    }
    cout << endl;

    vector<int> ans;
    for(int num: nums1) {
        ans.push_back(m.count(num)? m[num]: -1);
    }

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
}


int main() {
    vector<int> n1 = {4,1,2};
    vector<int> n2 = {1,3,4,2};
    nextGreater(n1,n2);

    return 0;
}