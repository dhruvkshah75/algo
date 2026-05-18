#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/
// very important question => HARD Leetcode 

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// solve without reversing is using stack that is reversing and the other is using stacks 
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // we have to traverse through the list in reverse direction 
        // by storing the nodes in stack 
        stack<ListNode*> st;
        ListNode* ptr = head;
        while(ptr != nullptr) {
            st.push(ptr);
            ptr = ptr->next;
        }

        int carry = 0;
        while(!st.empty()) {
            ListNode* curr = st.top();
            st.pop();
            int val = curr->val * 2 + carry;
            curr->val = val % 10;
            carry = val / 10;
        }

        if(carry == 1) {
            ListNode* ans = new ListNode(1, head);
            return ans;
        }
        else 
            return head;
    }
};