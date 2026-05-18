#include<bits/stdc++.h>
using namespace std;


// question link in the document: https://leetcode.com/problems/merge-k-sorted-lists/description/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1); // make the first node dummy node and then return ans->next
        ListNode* current = ans;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val){
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        }
        // now we add some of the left out elements 
        // attach remaining list
        current->next = l1 ? l1 : l2;
        return ans->next; // as the first node is dummy 
    }

    // Divide and Conquer -->> exactly like merge sort 
    ListNode* divNCon(int p , int q , vector<ListNode*>& lists){
        if(p == q){
            return lists[p];
        }
        int mid = (p+q)/2;
        ListNode* l1 = divNCon(p , mid , lists);
        ListNode* l2 = divNCon(mid + 1 , q , lists);
        return mergeTwoList(l1 , l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        if(n == 1) return lists[0];

        return divNCon(0 , n-1 , lists);  
    }
};

/*  
The merging of K sorted lists is like being already at the halfway will sorting the entire linked list as we are given sorted K lists 
This is Exactly merge sort but instead of elements it is just Linked lists 
Algorithm:
    Merging k sorted linked lists one by one can be inefficient.
    Instead of merging lists sequentially, we can apply a Divide and Conquer strategy, similar to merge sort.

    By repeatedly splitting the list of linked lists into halves and merging them pairwise, we reduce the overall time complexity.

    Approach
    Merge Two Sorted Lists
    Use a recursive merge approach:
    Compare current nodes
    Attach the smaller node
    Recursively merge the remaining part
    Divide and Conquer
        Recursively divide the range [p, q] of linked lists into two halves
        Merge the left half and right half
        Combine the results using the two-list merge function

    Base Cases
        If there are no lists → return NULL
        If there is only one list → return it directly
        This way, each node participates in log k merge operations.

    Complexity
    Time complexity:
        O(Nlogk)
        where N is the total number of nodes across all lists and k is the number of lists.

    Space complexity:
        O(logk)
        due to recursion stack from divide and conquer.

*/
