// ====================================== sliding window =======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-the-number-of-good-subarrays/description

/* Explanation: sliding window + minimum sliding window type 
   since we want the at least k such pairs => so find a smallest valid window ending in r 
   window [l...r] has at least k such pairs => so all subarrays ending in r => [0..r], [1..r],..., [l...r] will be good subarrays 
   cnt += (l+1)

   Now the question is how to calculate the number of such pairs in the window in O(1) while passing 
   one way is whenever a number is encountered whose initial cnt = x now it becomes x+1 
   so add the new pairs that will be formed 
   
   Always expand the window by 1 to the right r++ and shrink until the valid window remains valid 
   so in this way we get the smallest possible valid window ending in r => so we can get the number of good subarrays 
*/

typedef long long ll;

class Solution {
public:
    ll countGood(vector<int> &nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        // map to store the frequencies of elements in the window 

        int l = 0;
        ll res = 0, pairs = 0;

        for(int r = 0; r < n; r++) {
            // expand on the right 
            mp[nums[r]]++;
            pairs += mp[nums[r]] - 1;

            // shrink the valid window until it remains to valid 
            while(pairs >= k) {
                int removed = mp[nums[l]]-1;
                if(pairs - removed < k) break;
                // cannot shrink if the window becomes invalid 

                pairs -= removed;
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            } 

            if(pairs >= k) res += (l+1);
        }

        return res;
    }
};