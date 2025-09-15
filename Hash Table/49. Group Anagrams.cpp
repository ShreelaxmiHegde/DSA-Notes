#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> m; 
    
    for(int i=0; i<strs.size(); i++) {
        string s = strs[i];
        sort(s.begin(), s.end());
        m[s].push_back(strs[i]);
    }
    
    for(auto i: m) {
        ans.push_back(i.second);
    }
    
    return ans;
}

int main() {


    return 0;
}