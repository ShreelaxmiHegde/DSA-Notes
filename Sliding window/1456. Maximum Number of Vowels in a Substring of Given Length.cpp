#include <iostream>
#include <string>
using namespace std;

int maxVowels(string s, int k) {
    int left = 0;
    int maxVowel = 0;
    int currVowel = 0;

    for(int right=0; right<s.length(); right++) {
        if(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u') {
            currVowel++;
        }

        if(right-left+1 > k) {
            if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u') {
                currVowel--;
            }
            left++;
        }
        
        if(right-left+1 == k) {
            maxVowel = max(currVowel, maxVowel);
        }
    }
    return maxVowel;
}


int main() {
    string s = "abciiidef";
    int k = 3;

    return 0;
}