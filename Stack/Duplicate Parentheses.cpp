#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool duplicateParentheses(string s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == ')') { //closing bracket
            if(st.top() == '(') { //duplicate find
                return true;
            }

            while(s[i] != '(') {
                st.pop();
            }
            st.pop();
        } else { //non closing bracket chars
            st.push(s[i]);
        }
    }
    
    return false;
}

int main() {
    cout << duplicateParentheses("(x+y)");

    return 0;
}