// ==================================================================== dp on subsequences ===================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://www.naukri.com/code360/problems/unbounded-knapsack_1215029

/* You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.
   You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.

   Simple solution similar to coin change solution => infinite supply when we consider the take case 

   Constraints
        1 <= n <= 10^3
        1 <= w <= 10^3
        1 <= profit[i] , weight[i] <= 10^8   ==> use ll 
*/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class RecursiveSolution {
private:  
    int f(int x, int sum, vector<int> &profit, vector<int> &wt, vector<vector<int>> &dp) {
        // base case: last item reached 
        if(x == 0) {
            if(sum % wt[0] == 0) return (sum / wt[0]) * profit[0];
            else return -1e8;
        }

        if(dp[x][sum] != -1) return dp[x][sum];

        // explore the cases of picking or not 
        int not_take = f(x - 1, sum, profit, wt, dp);
        int take = -1e8;
        if(sum >= wt[x]) take = profit[x] + f(x, sum - wt[x], profit, wt, dp);
    
        return dp[x][sum] = max(take, not_take);
    }

public: 
    int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight){
        
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        int res = f(n - 1, W, profit, weight, dp);

        return ((res <= 0) ? 0 : res);
    }
};


// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

class Solution {
public:
    int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &wt){
        
        vector<vector<int>> dp(n, vector<int>(W + 1, -1e8));

        // base cases: x = 0 (last indexed element)
        for(int t = 0; t <= W; t++) {
            if(t % wt[0] == 0) dp[0][t] = (t / wt[0]) * profit[0];
        }

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= W; t++) {
                
                int not_take = dp[i - 1][t];
                int take = -1e8;
                if(t >= wt[i]) take = profit[i] + dp[i][t - wt[i]];

                dp[i][t] = max(take, not_take);
            }
        }

        int res = dp[n - 1][W];

        return ((res <= 0) ? 0 : res);
    }
};


// This solution can be space optimised as each dp[i][t] depends on either the current row or the prev row 
// space complexity of optimised solution is O(Target)

// ========================================================= Space Optimised Solution ===============================================================

class SpaceOptimisedSolution {
public:
    int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &wt){
        
        vector<int> prev(W + 1, -1e8), curr(W + 1, -1e8);
        // prev => dp[i - 1] and curr => dp[i]

        // base cases: x = 0 (last indexed element)
        for(int t = 0; t <= W; t++) {
            if(t % wt[0] == 0) prev[t] = (t / wt[0]) * profit[0];
        }

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= W; t++) {
                
                int not_take = prev[t];
                int take = -1e8;
                if(t >= wt[i]) take = profit[i] + curr[t - wt[i]];

                curr[t] = max(take, not_take);
            }

            swap(prev, curr);
        }   

        // after all the iterations prev denotes dp[n - 1]
        int res = prev[W];

        return ((res <= 0) ? 0 : res);
    }
};