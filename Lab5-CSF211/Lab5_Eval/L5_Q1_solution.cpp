#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

/*
 * Syntax reference for linked lists:
 *
 * Node* n = new Node(val);  // Create a new node
 * int x = n->data;          // Access the node's value
 * n = n->next;              // Move to the next node
 * delete n;                 // Free the node's memory
 */

// create a function to reverse the list correctly and return the correct start point 
Node* reverseList(Node* head) {
    // maintain two pointers 
    Node* prev = head;
    Node* curr = head->next;
    prev->next = nullptr;

    while(curr != nullptr) {
        Node* target = curr->next;
        curr->next = prev;
        prev = curr;
        curr = target;
    }
    // the prev points at the first node of the reversed list
    return prev;
}

Node *solve(Node *list_x, Node *list_y) {
    if(list_x == nullptr) {
        return list_y;
    }
    if(list_y == nullptr) {
        return list_x;
    }
    // first we remove the leading zeros from both the lists 
    // find the len of the two and keep the curr1 as the bigger one 

    Node* head1 = list_x;
    while(head1->next != nullptr && head1->data == 0) {
        head1 = head1->next;
    }
    Node* head2 = list_y;
    while(head2->next != nullptr && head2->data == 0) {
        head2 = head2->next;
    }
    // leading zeros are removed 

    int len1 = 0;
    Node* temp1 = head1;
    while(temp1 != nullptr) {
        temp1 = temp1->next;
        len1++;
    }

    int len2 = 0;
    Node* temp2 = head2;
    while(temp2 != nullptr) {
        temp2 = temp2->next;
        len2++;
    }
    // always keep the head1 as the larger list of the two 
    if(len2 > len1) {
        swap(head1, head2);
    }

    // now the head1 and head2 point to the start of the number

    // we have our reversed lists 
    Node* curr1 = reverseList(head1);
    Node* curr2 = reverseList(head2);

    Node* start = curr1;

    int carry = 0;
    // now we add the two lists 
    while(curr1 != nullptr && curr2 != nullptr) {
        int add = curr1->data + curr2->data + carry;
        curr1->data = add % 10;
        carry = add / 10;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    if(carry == 1) {
        // list two traversal is completed 
        // we are supposed to add carry continuously 
        Node* prev1 = curr1;
        while(curr1 != nullptr) {
            int add = curr1->data + carry;
            curr1->data = add % 10;
            carry = add / 10;
            prev1 = curr1;
            curr1 = curr1->next;
        }
        if(carry == 1) {
            // if at the last carry remains 1 then add a last node with 1 
            prev1->next = new Node(carry);
        }
    }
    // now reverse the final list 
    Node* ans = reverseList(start);
    return ans;
}