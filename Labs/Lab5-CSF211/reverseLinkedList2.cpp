#include<bits/stdc++.h>
using namespace std;

// question link:  https://leetcode.com/problems/reverse-linked-list-ii/description/
// Important reversal of linked list question 

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Use dummy to handle the case where left = 1
        ListNode* dummy = new ListNode(0, head);
        ListNode* beforeLeft = dummy;

        // Move beforeLeft to the node at position (left - 1)
        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }
        // now the beforeLeft is at left - 1 node 

        // Standard Reversal Logic
        ListNode* curr = beforeLeft->next; // curr is at the left position 
        ListNode* prev = nullptr;          // at the start the prev is nullptr 
        ListNode* tailOfSublist = curr;    // Keep track to connect to the 'right + 1' node later

        for (int i = 0; i <= (right - left); i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Reconnect the reversed section
        beforeLeft->next = prev;        // prev is now the 'right' node
        tailOfSublist->next = curr;    // curr is now the 'right + 1' node

        ListNode* result = dummy->next;
        delete dummy; 
        
        return result;
    }
};