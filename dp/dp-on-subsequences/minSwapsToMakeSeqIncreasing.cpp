// ===================================================== dp on subsequences ====================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(). x.rend()
#define pii pair<int,int> 
#define pll pair<ll,ll>

// question link: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

/* @brief Explanation: dp on subsequences with extra needed state 
   At each index ind we have two options either swap the element in nums1 and nums2 
   or do not swap them (for this to correctly we must know whether the previous element was swapped or not)
   prev element is at ind+1 => swap = 0 => not swapped at ind+1 and swap = 1 => swapped at ind+1
   Both swap and not swap cases must be done in such a way that suffix [ind...n] is increasing 

   f(ind, swap) = min number of swaps to make suffix[ind...n] strictly increasing
   for not swapping and for swapping at ind th element it must staisfy the increasing case with ind+1 th elements 
*/

// ========================================================================================================================================================
//                                                      Top Down Approach Memoization dp
// ========================================================================================================================================================

class Solution {
private:    
    const int inf = 1e8;
    static constexpr int N = 1e5+1;
    int dp[N][2];

    int f(int ind, int swap, vector<int> &nums1, vector<int> &nums2) {
        // base case: if the array is completely processed 
        if(ind < 0) return 0;

        if(dp[ind][swap] != -1) return dp[ind][swap];

        // get the prev values (ind+1) depending on swap = 0 or 1 
        // default case: swap = 0
        int v1 = nums1[ind+1], v2 = nums2[ind+1];
        if(swap == 1) std::swap(v1, v2);

        // try both cases of swapping and not swapping the elements 
        int res = inf;

        if(nums1[ind] < v1 && nums2[ind] < v2) {
            // not swap case is allowed 
            res = min(res, f(ind-1, 0, nums1, nums2));
        }

        if(nums1[ind] < v2 && nums2[ind] < v1) {
            // swap case is allowed at ind th index 
            res = min(res, 1 + f(ind-1, 1, nums1, nums2));
        }

        return dp[ind][swap] = res;
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // add infinity at the end of sequences to keep uniformity in reccurence
        nums1.push_back(inf);
        nums2.push_back(inf);

        // now nums becomes n+1 => nums1[n] = inf

        memset(dp, -1, sizeof(dp));

        return f(n-1, 0, nums1, nums2);
    }
};
// Space Complexity = O(2*N) + O(N), Time Complexity = O(2*N)