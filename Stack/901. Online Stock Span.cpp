#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> s; //<price, day>
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1; //days count
        while(!s.empty() && s.top().first <= price) {
            span += s.top().second; //increase days
            s.pop();
        }

        s.push({price, span});

        return span;
    }
};