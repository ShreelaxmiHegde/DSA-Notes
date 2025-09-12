#include <iostream>
#include <vector>
using namespace std;


int countDays(vector<int>& weights, int mid) {
    int days = 1; //at least one day needed
    int load = 0;

    for(int w: weights) {
        if(load + w > mid) { //need another day
            days++;
            load = 0;
        } 
        load += w;
    }

    return days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int maxWeight = 0;
    int totalWeight = 0;
    for(int i=0; i<weights.size(); i++) {
        maxWeight = max(maxWeight, weights[i]);
        totalWeight += weights[i];
    }

    int left = maxWeight; // at least the heaviest package
    int right = totalWeight; // at most sum of all weights
    int ans = 0;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        int daysNeeded = countDays(weights, mid);

        if(daysNeeded <= days) {
            ans = mid;
            right = mid - 1; // feasible → try smaller capacity
        } else {
            left = mid + 1; // not feasible → need more capacity
        }
    }

    return ans;
}

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    shipWithinDays(weights, days);


    return 0;
}