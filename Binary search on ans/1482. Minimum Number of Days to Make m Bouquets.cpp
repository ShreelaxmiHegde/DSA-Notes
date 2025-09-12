#include <iostream>
#include <vector>
using namespace std;

// means from the mid day range can we make the boque of consecutive flowers
int isPossible(vector<int> bloomDay, int mid, int flowerNum) {
    int consecFlowers = 0;
    int possibleBoq = 0;

    for(int i=0; i<bloomDay.size(); i++) {
        if(bloomDay[i] <= mid) { //finding k consecutive flowers
            consecFlowers++;
        } else {
            consecFlowers = 0;
        }

        if(consecFlowers == flowerNum) { //we can make a boq
            possibleBoq++;
            consecFlowers = 0;
        }
    }

    return possibleBoq;
}

int minDays(vector<int> bloomDay, int boqNum, int flowerNum) {
    if ((long long)boqNum * flowerNum > bloomDay.size()) return -1;
    
    int earliestBloom = bloomDay[0];
    int latestBloom = 0;
    for(int i=0; i<bloomDay.size(); i++) {
        earliestBloom = min(earliestBloom, bloomDay[i]);
        latestBloom = max(latestBloom, bloomDay[i]);
    }

    int left = earliestBloom;
    int right = latestBloom;
    int minDays = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(isPossible(bloomDay, mid, flowerNum) >= boqNum) {
            minDays = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return minDays;
}


int main() {
    vector<int> bloomDay = {7,7,7,7,12,7,7};
    int m = 2, k = 3;
    minDays(bloomDay, m, k);

    return 0;
}