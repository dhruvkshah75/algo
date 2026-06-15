// ============================================================= linear dp + 0-1 knapsack dp =======================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/delete-and-earn/description/

// ===================================================== Very Important Question ==================================================================

// the most important step would be to use maps to store the freq and have only non duplicate elements after that the question is a simple 0-1 knapsack 

/* Explanation: linear dp (0-1 knapsack) with hashing trick 
   recurrence => f(ind) = max points earned by applying operations in the suffix [ind...n]
   since we can consider a nums[i] and delete it to get nums[i] points we must skip out nums[i]-1 and nums[i]+1
   Store only the non duplicate elements in the array and store their freq in a hash map 
   Now iterate from the back n-1 to 0

   At each step => 2 options (take or not_take)
   if we delete nums[ind] element we get nums[ind] * freq[nums[ind]] points 
   and we must skip the element nums[ind]-1 if it exists (1 of 0-1 knapsack)
   OR simply skip this element and move to the next one (0 of 0-1 knapsack) 
   Following this handles the case of deleting all nums[ind]-1 and nums[ind]+1
*/

// ==============================================================================================================================================
//                                                  Top Down Approach Memoization dp
// ==============================================================================================================================================

#define all(x) x.begin(), x.end()

class Solution {
private:
    static constexpr int N = 2e4+1;
    int dp[N];

    int f(int ind, vector<int> &arr, unordered_map<int,int> &mp) {
        // base case: all elements of arr processed 
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        // 0-1 knapsack
        int not_take = f(ind-1, arr, mp);

        int take = mp[arr[ind]] * arr[ind];
        if(ind > 0) {
            // 2 cases => if ind-1 is nums[ind]-1 or not => depending on this we move to the next index 
            int nxt = ((arr[ind-1] == arr[ind]-1) ? ind-2 : ind-1);
            
            take += f(nxt, arr, mp);
        }

        return dp[ind] = max(take, not_take);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        memset(dp, -1, sizeof(dp));

        unordered_map<int,int> mp;
        // mp to store the frequencies of elements 

        for(int i = 0; i < n; i++)
            mp[nums[i]]++;

        vector<int> arr;
        // arr => store the non duplicate elements 

        for(auto [val, cnt]: mp)
            arr.push_back(val);

        // sort the array so nums[i]-1 and nums[i] are adjacent to each other 
        sort(all(arr)); 
        int last = arr.size();

        return f(last-1, arr, mp);
    }
};
// Space Complexity = O(N) + O(arr.size) + O(N)