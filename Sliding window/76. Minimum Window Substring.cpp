#include <iostream>
#include <unordered_map>
using namespace std;


string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    unordered_map<char, int> need, have;
    for (char c : t) need[c]++;

    int required = need.size();   // unique chars we need
    int formed = 0;              // unique chars matched in window
    int left = 0, right = 0;
    int minLen = INT_MAX, start = 0;

    while (right < s.size()) {
        char c = s[right];
        have[c]++;

        // char frequency requirement satisfied
        if (need.count(c) && have[c] == need[c]) {
            formed++;
        }

        // shrink window if all required chars matched
        while (left <= right && formed == required) {
            // update answer
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            // pop from left
            char lchar = s[left];
            have[lchar]--;
            if (need.count(lchar) && have[lchar] < need[lchar]) {
                formed--;
            }
            left++;
        }

        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}


int main() {

    return 0;
}