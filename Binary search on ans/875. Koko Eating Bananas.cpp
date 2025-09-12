#include <iostream>
#include <vector>
using namespace std;


long long helper(vector<int>& piles, int mid) { //total hour needed if koko eats in the speed of mid
    long long hours = 0;

    for(int i=0; i<piles.size(); i++) {
        hours += (piles[i] + mid - 1) / mid;
    }

    return hours;
}

int minEatingSpeed(vector<int>& piles, int h) { 
    int maxPile = 0;
    for(int i=0; i<piles.size(); i++) {
        maxPile = max(maxPile, piles[i]);
    }

    int left = 1;
    int right = maxPile; //right boundary
    int ans = 0;

    while(left <= right) {
        int mid = left + (right - left) / 2; // eating speed of koko
        
        if(helper(piles, mid) <= (long long)h) { //he can finish
            ans = mid;
            right = mid-1; //try to minimise more
        } else { // koko cant finish in time in the speed of mid
            left = mid+1; //try for larger
        }
    }

    return ans;
}
