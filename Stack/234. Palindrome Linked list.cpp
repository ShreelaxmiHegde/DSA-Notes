#include <iostream>
#include <vector>
#include <stack>
using namespace std;



class Node {
public:
    Node* next;
    int data;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

bool isPalindrome(Node* head) {
    Node* temp = head;

    //calculate list size
    int idx = 0;
    while(temp != NULL) {
        idx++;
        temp = temp->next;
    }
    temp = head;

    stack<int> st;
    for(int i=0; i<idx; i++) {
        // skip middle element in odd length
        if(idx % 2 == 1 && i == idx/2) {
            temp = temp->next;
            continue;
        }
        
        if(idx/2 > i) {
            st.push(temp->data);
        } else {
            if(st.top() != temp->data) {
                return false;
            } 
            st.pop();
        }

        temp = temp->next;
    }

    return true;
}