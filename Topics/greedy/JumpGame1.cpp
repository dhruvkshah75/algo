// ================================================ greedy =================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/jump-game/

/* Explanation: greedy solution
 * Simple thought is when cant we not reach the end index => if we get stuck at 0
 * So if array does not contain 0 then we can always reach 
 * Now maintain a variable of max index that we can reach by using the jump at the current index 
 * if at some point maxIndex > curr_idx => return false as we could never reach this index whatever path we followed 
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        bool hasZero = false;

        for(int num: nums) {
            if(num == 0) {
                hasZero = true;
                break;
            }
        }
            
        if(!hasZero) return true;

        int maxIdx = 0;

        for(int i = 0; i < n; i++) {
            // we cannot reach this index whatever path we followed 
            if(maxIdx < i) return false;
            maxIdx = max(maxIdx, i + nums[i]);
        }
        
        return true;
    }
};