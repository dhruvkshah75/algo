#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/top-k-frequent-words/description/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // use a min heap with the smallest count at the top 
        unordered_map<string,int> cnt;

        for(auto s: words)
            cnt[s]++; 

        auto cmp = [&](string &a, string &b) {
            // return true if a has lower priority than b 
            if(cnt[a] == cnt[b])
                return a < b;
            else 
                return cnt[a] > cnt[b];
        };

        priority_queue<string, vector<string>, decltype(cmp)> minHeap(cmp);
        // always maintain the size of the heap as k 

        for(auto &[str, count] : cnt) {
            // always push and just pop out if the size becomes bigger than k  
            minHeap.push(str);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<string> result;

        while(!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        // use the same cmp to sort them 
        sort(result.begin(), result.end(), cmp);

        return result;
    }
};