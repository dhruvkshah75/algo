// ==================================================================== dp on subsequences ===================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/

/* The states in the recurrence are f(i, j, k) => ith pile and jth coin in that pile and k number of coins 
   If a coin is not taken we cannot go down in the pile we must select a new pile from the start 
   This solution using f(i, j, k) => recurrence is brute force dp which uses 3d dp => ineffecient 

   Better solution can be achieved 
   The solution is to basically remove the j from the dp state and just run a loop with j as being a variable 

   Option 1: as always to skip the complete pile and move to the next pile 
   Option 2: take x coins from the current pile and then move to the next pile => do this for all possible x coins 
   This reduces the dp to dp[i][k]
*/


// brute force DP solution can be used to built intuition on how exaclty the take and not take situation works 

class BruteForcDpSolution {
private:  
    int f(int i, int j, int k, vector<vector<int>> &piles, vector<vector<vector<int>>> &dp) {
        // base case: all the coins are taken or invalid cell accessed 
        if(k == 0 || i < 0) return 0;

        // base case: all the coins in the current pile are over 
        if(j >= (int)piles[i].size()) return f(i - 1, 0, k, piles, dp);

        if(dp[i][j][k] != -1) return dp[i][j][k];

        // explore all the possible moves to take the coin 
        // option 1: switch to the next pile 
        int not_take = f(i - 1, 0, k, piles, dp);

        // option 2: take the current coin and move to next coin in the pile 
        int take = piles[i][j] + f(i, j + 1, k - 1, piles, dp);
        
        return dp[i][j][k] = max(take, not_take);
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        vector<vector<vector<int>>> dp(n);

        for(int i = 0; i < n; i++) {
            dp[i].resize(piles[i].size());

            for(int j = 0; j < (int)dp[i].size(); j++) 
                dp[i][j].resize(k + 1, -1);
        }

        // call the recurrence starting from the last pile 
        return f(n - 1, 0, k, piles, dp);
    }
};

// =========================================================================================================================================================
//                                                  Optimal Top Down Approach (Memoization) dp
// =========================================================================================================================================================

/* The recurrence f(i, k) => i denotes the pile we are in and k denotes the number of coins left to be taken 
   Option 1: as always to skip the complete pile and move to the next pile 
   Option 2: take x coins from the current pile and then move to the next pile => do this for all possible x coins 
   This reduces the 3d dp to 2d dp[i][k]
*/

class Solution {
private:  
    int f(int i, int k, vector<vector<int>> &piles, vector<vector<int>> &dp) {
        // base case: all the coins are taken or invalid cell accessed 
        if(k == 0 || i < 0) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        // explore all the possible moves to take the coin 
        // option 1: switch to the next pile 
        int res = f(i - 1, k, piles, dp);

        // option 2: try taking x coins from current pile 
        int current_sum = 0;
        for(int x = 1; x <= min((int)piles[i].size(), k); x++) {
            current_sum += piles[i][x - 1];

            res = max(res, current_sum + f(i - 1, k - x, piles, dp));
        }
        
        return dp[i][k] = res;
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        // call the recurrence starting from the last pile 
        return f(n - 1, k, piles, dp);
    }
};

// ===============================================================================================================================================
//                                              Bottom Up Approach (Tabulation) dp  
// ===============================================================================================================================================

// To avoid the Auxialiary stack space we write the tabulation for this qustion 

class Solution {
public: 
    int maxValueOfCoins(vector<vector<int>> &piles, int k) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        // base case: k = 0 => already implemented
        // base case: i == 0 (reached last pile) => take x coins 
        int curr_sum = 0;

        for(int x = 1; x <= min((int)piles[0].size(), k); x++) {
            curr_sum += piles[0][x - 1];
            dp[0][x] = curr_sum;
        }

        for(int i = 1; i < n; i++) {
            for(int c = 1; c <= k; c++) {
                // 2 options => dont take anything so switch the pile or take x coins in same pile 

                int not_take = dp[i - 1][c];

                int take = -1e8, sum = 0;

                for(int x = 1; x <= min((int)piles[i].size(), c); x++) {
                    sum += piles[i][x - 1];
                    take = max(take, sum + dp[i - 1][c - x]);
                }

                dp[i][c] = max(take, not_take);
            }
        }

        return dp[n - 1][k];
    }
};

// This question can further be space optimised into O(K) where we use 2 1d arrays prev and curr 
// prev deenotes the [i - 1] and curr denotes the [i] row of the tabulation dp 

class SpaceOptimisedSolution {
public: 
    int maxValueOfCoins(vector<vector<int>> &piles, int k) {
        int n = piles.size();

        vector<int> prev(k +1, 0), curr(k + 1, 0);
        // prev => dp[i - 1] and curr => dp[i]

        // base case: k = 0 => already implemented
        // base case: i == 0 (reached last pile) => take x coins 
        int curr_sum = 0;

        for(int x = 1; x <= min((int)piles[0].size(), k); x++) {
            curr_sum += piles[0][x - 1];
            prev[x] = curr_sum;
        }

        for(int i = 1; i < n; i++) {
            for(int c = 1; c <= k; c++) {
                // 2 options => dont take anything so switch the pile or take x coins in same pile 

                int not_take = prev[c];

                int take = -1e8, sum = 0;
                for(int x = 1; x <= min((int)piles[i].size(), c); x++) {
                    sum += piles[i][x - 1];
                    take = max(take, sum + prev[c - x]);
                }

                curr[c] = max(take, not_take);
            }
            swap(prev, curr);
        }

        return prev[k];
    }
};