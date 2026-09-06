#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/
// very important question => HARD Leetcode 

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    Algorithm: 
        We simply create a new function to reverse k elements and store the end and the front of the updated reversed 
        k nodes in the list and then return these two front and end variables 
        In the main function we maintain two pointers to point to the k+1 node and the -1 node of the updating list 
        and then we connect the -1->next to the front var and end->next to the k+1 node of the main list 
        
    we first if the k+1 node exists i.e. are there k nodes to reverse in the list => if yes then we reverse and 
    connect based on the logic mentioned above 

    Time Complexity: O(N)
*/

class Solution {
    ListNode* front;
    ListNode* end;
    // reverse these k elements in the list and return their front and end for joining to the main ll 
    void reverseList(ListNode* head, int k) {
        // the start will become the end after reversing 
        end = head; 
        // simply reverse using curr and prev pointers and then update the new front 
        ListNode* curr = head->next;
        ListNode* prev = head;
        int ctr = 0;
        while(ctr + 1 < k) {
            ListNode* target = curr->next;
            curr->next = prev;
            prev = curr;
            curr = target;
            ctr++;
        }
        // now my prev points to last node i.e. the first node of reversed list 
        front = prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // first we insert a dummy for preventing case handling 
        ListNode* dummy = new ListNode(0, head);

        ListNode* ptr = dummy->next;
        ListNode* prev = dummy;        // the prev is connected to the front of the reversed group 
                                       // initially it is at the dummy for easy solving 
        while(ptr != nullptr) {
            int ctr = 0;
            while(ptr != nullptr && ctr < k) {
                ctr++;
                ptr = ptr->next;
            }
            if(ctr == k) {
                // now ptr holds the node k + 1 
                reverseList(prev->next, k);
                // now the front points to the reversed end 
                prev->next = front;
                end->next = ptr;
                // update the prev to node 
                prev = end;
            }
        }
        // dont return the head as the head gets shuffled, but the dummy->next points to the start of the list
        return dummy->next;
    }
};

int main() {
    int n, k; 
    cin >> n >> k;

    // input of the first value 
    int val;
    cin >> val;
    ListNode* head = new ListNode(val);

    ListNode* curr = head;

    for(int i=1; i<n; i++) {
        int val;
        cin >> val;
        curr->next = new ListNode(val);

        // now move the current to the next node 
        curr = curr->next;
    }

    Solution s = Solution();

    ListNode* ans = s.reverseKGroup(head, k);
    
}