#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/lru-cache/description/

// Important Question on Linked List 

class LRUCache {
    // we will maintain a doubly linked list and keep adding new keys before the head 
    // and remove the last node 
    struct ListNode {
        int key;
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {};
    };

    ListNode* head;
    ListNode* end;

    unordered_map<int,ListNode*> mp;

    int lengthLL;
    int curLength;

    void moveToFront(ListNode* curr) {
        // base case if the current is head no need to move anywhere 
        if(curr == head) return;
        
        ListNode* prev = curr->prev;
        ListNode* next = curr->next;

        prev->next = next;
        if(next != nullptr) next->prev = prev;
        else end = prev;  // curr was end sothing to connect 

        curr->prev = nullptr;
        curr->next = head;
        head->prev = curr;
        head = curr;     // update member head
    }

public:
    LRUCache(int capacity) {
        lengthLL = capacity;
        curLength = 0;
        head = nullptr;
        end = nullptr;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) 
            return -1;
        // if the key is accessed then the key must be moved to the front 
        moveToFront(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        // if key exists then change the value and then move the key to start  
        if(mp.find(key) != mp.end()) {
            mp[key]->val = value;
            moveToFront(mp[key]);
            return;
        }

        ListNode* temp = new ListNode(key, value);
        
        if(curLength == 0) {
            head = temp;
            end = temp;
            curLength++;
            mp[key] = temp;
            return;
        }

        // ALWAYS add to the front (MRU) => most recently used 
        temp->next = head;
        head->prev = temp;
        head = temp;
        mp[key] = temp;

        if(curLength < lengthLL) {
            curLength++;
        } 
        else {
            // Delete the end (LRU) => least recenetly used cache 
            ListNode* toDelete = end;
            mp.erase(toDelete->key);
            
            if(toDelete->prev) {
                end = toDelete->prev;
                end->next = nullptr;
            } 
            else {  // Capacity was 1, list is now empty (though temp was just added)
                // But since we added temp to head first, this case is handled by head/end logic
                head = temp;
                end = temp;
            }
            delete toDelete;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */