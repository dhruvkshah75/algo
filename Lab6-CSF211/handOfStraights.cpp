#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/hand-of-straights/

/*
    Important Question to build intuition on PQs 
    We store all the unqiue cards in the min heap and cnt in a map and then for each first card we find groupSize consecutive elements 
    instead of poping all of them out => pop only those whose count becomes 0 

    We run a loop for first to first + groupSize - 1 => if this works out then pop the only those whose count becomes 0

*/

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        // if groupSize * x != n then we cannot rearrange them 
        if(n % groupSize != 0)
            return false;

        // we put all the elements in the min heap => for duplicates use hash map 

        priority_queue<int, vector<int>, greater<int>> minHeap;

        unordered_map<int,int> cnt;

        for(int card: hand) {
            cnt[card]++;
        }
    
        // now we push all the unique elements in the min heap 
        // and if the top of min heap is 1 then it must belong to the group of [1, 2, .. k]
        for(auto &[hand, count]: cnt) {
            minHeap.push(hand);
        }

        while(!minHeap.empty()) {
            int first = minHeap.top();
            // first is the smallest card available 
            // if this card is not a part of any group then pop it 
            if(cnt[first] == 0) {
                minHeap.pop();
                continue;
            }

            // the first card is a part of a group whose cards range from first to groupSize+first-1
            for(int i = first + 1; i < first + groupSize; i++) {
                if(cnt.find(i) == cnt.end() || cnt[i] < cnt[first]) {
                    return false;
                }
                // subtract the part used in this group as this element can also be used in other groups
                cnt[i] -= cnt[first];

                if(cnt[i] == 0) 
                    minHeap.pop();
            }
            // pop out the first hand as all the groups it is a part of is taken care of 
            minHeap.pop();
        }

        return true;
    }
};