#include<bits/stdc++.h>
using namespace std;


// question link: https://leetcode.com/problems/sort-list/description/
// question is based on merge sorting on linked lists 
// very important algorithm for sorting 

class Solution {
public:
    // VERY IMPORTANT: get the mid point of the linked list using fast and slow pointers 
    ListNode* getMid(ListNode* head) {
        // fast pointer moves 2 times whereas the slow one moves 1 time 
        ListNode* slow = head;
        ListNode* fast = head->next; 
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // the slow will point to the mid of the list
    }

    // the merge function
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            } 
            else {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }
        // add the leftover 
        curr->next = (l1 != nullptr) ? l1 : l2;
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        // Base case: if list is empty or has one node
        if (head == nullptr || head->next == nullptr) return head;

        // Split the list into two halves by using 2 pointers-> slow and fast pointer 
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // BREAK the list into two pieces

        // Recursively sort
        left = sortList(left);
        right = sortList(right);
        // Merge
        return merge(left, right);
    }
};

/*
    We have to split the the linked list into 2 linked lists mark them as left and right 
    we separate them by making right as mid->next 
    How do we get the mid ?
        We use the slow and fast pointer approach: we have two pointers slow and fast both pointing the head of the linked list.
        we traverse through the list: slow moves one step and the fast moves 2 steps with the while condition as fast != nullptr && fast->next != nullptr
        So the slow is the one that is the mid 
    The left is left = head and right is the right = mid->next
    by using merge sort algorithm we sort it 
    We recursively sort the left and right by breaking them into smaller ones and then merge them using the merge function 
*/

