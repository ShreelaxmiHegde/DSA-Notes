#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s; //stores indices

    //find next smaller left maximum height
    vector<int> nsl(n);
    nsl[0] = -1;
    s.push(0);
    for(int i=1; i<n; i++) { //forward loop
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }

        if(s.empty()) {
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        }

        s.push(i);
    }


    //empty the stack - to reuse the same stack
    while(!s.empty()) {
        s.pop();
    }

    //find rignt max height
    vector<int> nsr(n);
    nsr[n-1] = n;
    s.push(n-1);
    for(int i=n-2; i>=0; i--) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }

        if(s.empty()) {
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
        }
        s.push(i);
    } 

    // compute the l & r heights to
    int maxArea = 0;
    for(int i=0; i<n; i++) {
        int width = nsr[i] - nsl[i] - 1;
        int area = heights[i] * width;

        maxArea = max(area, maxArea);
    }

    return maxArea;
}