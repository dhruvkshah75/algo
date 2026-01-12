#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/longest-consecutive-sequence/description/ 
/*
    Algorithm:
        Here is the brief algorithm for your solution:

        1. **Hash & De-duplicate:** Insert all elements from the vector into an `unordered_set`. This removes duplicates and allows for **O(1)** lookups.
        2. **Iterate:** Loop through every element `x` currently in the set.
        3. **Identify Sequence Start:** Check if `x - 1` exists in the set.
        * **If `x - 1` exists:** `x` is *not* the start of a sequence (it is part of a sequence started by a smaller number). **Skip it.**
        * **If `x - 1` does not exist:** `x` is the **start** of a new sequence. Proceed to Step 4.
        4. **Measure Sequence:** Starting from `x`, strictly increment the number (`x+1`, `x+2`...) and check if it exists in the set. Keep counting until the sequence breaks.
        5. **Update Max:** Compare the length of this current sequence against the global maximum (`longest`).

        Why this is O(N) ? 
            Even though there is a `while` loop inside the iterator loop, the inner `while` loop only runs for the **start** of a sequence. 
            This ensures that every number in the array is visited at most twice (once by the main iterator, and once by the inner expansion loop).

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        unordered_set<int> s;
        for(int i=0; i<len; i++) {
            s.insert(nums[i]);
        }

        unordered_set<int>::iterator it = s.begin();
        int longest = 1; // the ans
        // this is only O(N)
        while(it != s.end()) {
            if(s.find(*it - 1) == s.end()){
                int ctr = 0;
                int val = *it;
                while(s.find(val) != s.end()) {
                    val++;
                    ctr++;
                }
                longest = max(longest, ctr);
            }
            it++;
        }
        return longest;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    
    Solution s = Solution();
    int ans = s.longestSequence(nums);
    cout << ans << endl;
}
