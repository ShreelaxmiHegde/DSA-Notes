#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool validParentheses(string s) {
    stack<int> st;

    for(int i=0; i<s.length(); i++) {
        if((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
            st.push(s[i]);
        } else {
            if(s.empty()) return false;

            if(!s.empty() &&
                (st.top() == '(' && s[i] == ')') ||
                (st.top() == '[' && s[i] == ']') ||
                (st.top() == '{' && s[i] == '}')
            ) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.size() == 0;
}