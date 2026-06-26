// =================================================== dp on subsequences ==========================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/tallest-billboard/description/

// ================================================= Very Important Question =================================================================

/* Explaination: 
   Maximum sum of a subset that can be achieved is total / 2 
   Try out all possible subset sums and then when all rod pieces are proccessed choose 
   max sum of the subset 
   Here we have the choice to consider the case where the rod piece is not taken for both the subsets 

   Recurrence f(ind, s1, s2) => tracking s1 sum and s2 sum is expensive => so track the diff of the two 
   diff = s1 - s2 => when rod is added to s1 then diff + rod and when  added to s2 => diff - rod
   Use a offset of 5000 as the diff could go negative 

   The correct Reccurence:
   f(ind, diff): The maximum height of the taller pile when the difference between Pile 1 and Pile 2 is diff
*/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class Solution {
private:
    static constexpr int N = 1e5+1;

    int dp[20][N];

    // f(ind, diff) = maximum height of the pile 1 (s1) where s1 - s2 = diff

    int f(int ind, int diff, vector<int> &rods) {
        // track the s1 - s2 = diff 
        // base case: all elements processed 
        if(ind < 0) {
            return (diff == 0) ? 0 : -1e8;
        }

        if(dp[ind][diff+5000] != -1) return dp[ind][diff+5000];

        // s1 => pile 1 and s2 => pile2

        // case 1: dont take rods[ind] in either subsets
        int not_take = f(ind-1, diff, rods);

        // case 2: take the rod piece in either subset
        // if taken in s1 => diff + rods[ind] and taken in s2 => diff - rods[ind]
        int take1 = rods[ind] + f(ind-1, diff + rods[ind], rods);

        int take2 = f(ind-1, diff-rods[ind], rods);

        return dp[ind][diff+5000] = max({take1, take2, not_take});
    }

public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();

        memset(dp, -1, sizeof(dp));

        return f(n-1, 0, rods);
    }
};
// Space Complexity = O(1e5 * N) + O(N) and Time Complexity = O(1e5 * N)
// The auxiliary stack space of O(N) is very small here so memoization is very similar to tabulation 