#include <iostream>
#include <vector>
using namespace std;



int characterReplacement(string s, int k) {
vector<int> freq(26,0);
int left = 0;
int maxFreq = 0;
int maxLen = 0;

for(int right=0; right<s.size(); right++) {
    freq[s[right]-'A']++;
    maxFreq = max(maxFreq, freq[s[right]-'A']);

    // If replacements needed > k, shrink window
    while((right-left+1)-maxFreq > k) {
        freq[s[left]-'A']--;
        left++;
    }

    maxLen = max(maxLen, right - left + 1);
}
return maxLen;
}

int main() {
    string s = {"BAAA"};
    int k = 1;

    return 0;
}