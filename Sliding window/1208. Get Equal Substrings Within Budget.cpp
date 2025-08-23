#include <iostream>
#include <string>
using namespace std;


int equalSubstring(string s, string t, int maxCost) {
    int left = 0;
    int currCost = 0;
    int maxLen = 0;

    for(int right=0; right<s.size(); right++) {
        currCost += abs(s[right]-t[right]); // calcs the current cost

        while(currCost > maxCost) { //when the cost will exceed 
            currCost -= abs(s[left]-t[left]);
            left++;
        } // now left pointer pointing to valid

        maxLen = max(maxLen, right-left+1); // checking maximum length
    }

    return maxLen;
}



int main() {

    return 0;
}