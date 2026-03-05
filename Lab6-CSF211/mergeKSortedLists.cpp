#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/merge-k-sorted-lists/description/
// implementation of this using Heaps instead of merge Sort 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        // we use min heap to solve this question 
        // define k pointers at the start of the each list that store them in the min heap
        auto cmp = [&](ListNode* a, ListNode* b) {
            // return true if 'a' has less priority than 'b'
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        // prepopulate the heap with first element of all the lists 
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr)
                minHeap.push(lists[i]);
        }

        ListNode* mergedList = new ListNode(0);
        ListNode* curr = mergedList;

        while(!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // make the node and then move the node forward 
            curr->next = new ListNode(smallest->val);
            curr = curr->next;

            if(smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        return mergedList->next;
    }
};