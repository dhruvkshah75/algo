#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/linked-list-cycle/description/
// Important usage of slow and fast pointers 


/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) 
            return false;

        // maintains two pointers fast and slow => 
        // if slow and fast land on each other then cycle is present 
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            // if fast and slow land on the same node there is cycle 
            if(slow == fast)
                return true;
        }

        // if the loop is finished then there is no cycle 
        return false;
    }
};