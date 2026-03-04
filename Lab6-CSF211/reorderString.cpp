#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/reorganize-string/description/

// Important question on heaps with custom priority and greedy solution approach 

/*
    what will be the optimised way to place them => start by placing the char with max count 
    at alternative postitions and keep doing this 

    Time Complexity: O(N + K*LogK)  
    => K is the number of unique characters 
    N as the no matter how big the outer while loop is The inner loop will run totally for N times 
    => as we populate the string 
*/


class Solution {
public:
    string reorganizeString(string s) {
        // store the unique characters in a heap with a custom priority with top having the max priority 
        // we place the one with most count alternative places 
        int n = s.length();

        unordered_map<char,int> freq;

        // update the frequency map 
        for(char c: s) freq[c]++;
        
        auto cmp = [&](char a, char b) {
            // return true if a has lower priority than b (a must be below b in the heap)
            return freq[a] < freq[b];
        };
        // max heap with custom priority based on count (max count at the top)
        priority_queue<char, vector<char>, decltype(cmp)> maxHeap(cmp);

        // populate the heap with unique characters 
        for(auto &[ch, count]: freq) {
            maxHeap.push(ch);
        }

        if(freq[maxHeap.top()] > (n+1)/2)
            return "";

        // define the ans string 
        string ans(n, ' ');
        // this bool tells where to fill the elements => at even or indices 
        int j = 0;     // for keeping the count of indices  

        while(!maxHeap.empty()) {
            char c = maxHeap.top();
            int cnt = freq[c];
            // we can do one thing first we fill out the even places and then we can fill the even places 
            // we fill cnt no of characters at alternate position 
            while(j < n && cnt > 0) {
                ans[j] = c;
                j += 2;
                cnt--;
            }
            // if even indices are placed then shift the pointer to odd indices 
            if(j >= n) {
                j = 1;
                // if even places are filled out then place them at odd positions 
                while(j < n && cnt > 0) {
                    ans[j] = c;
                    j += 2;
                    cnt--;
                }
            }
            // pop the character that we placed 
            maxHeap.pop();
        }
        return ans;
    }
};