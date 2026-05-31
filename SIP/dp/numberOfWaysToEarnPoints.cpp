// ==================================================================== dp on subsequences =====================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/number-of-ways-to-earn-points/description/
// leetcode hard question

// ====================================================== Very Important Question on Knapsack =====================================================================

/* This question is similar to coin change where we have options to select the question type 
   In coin change => infinite supply of coins was available 
   Here we have a finite supply of same type of questions 
   Base Case: 
   types[0] = {no of questions, points} => sum / points <= questions 
   if the number of questions needed exceeds the number of available question then return 0 
   
   Two options available at each question 
   option 1: dont solve any number of questions 
   option 2: solve x number of questions from the current question and move to the next question 
             (can only be solved if => sum - solved * marks >= 0) */


// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ================================================================================================================================================================== 

typedef long long ll;

class RecursiveSolution {
private:    
    const int mod = 1e9 + 7;

    int f(int x, int sum, vector<vector<int>> &types, vector<vector<int>> &dp) {
        // base case: last index reached 
        if(x == 0) {
            if(sum % types[0][1] == 0 && sum / types[0][1] <= types[0][0]) return 1;
            else return 0;
        }

        if(dp[x][sum] != -1) return dp[x][sum];

        // option 1: dont take from the current 
        ll not_take = f(x - 1, sum, types, dp);

        // option 2: take x from the current for all x (solve x questions)
        int marks = types[x][1], q = types[x][0];

        ll take = 0;
        for(int solved = 1; solved <= q; solved++) {
            if(sum < solved * marks) break;

            take = (take + f(x - 1, sum - solved * marks, types, dp)) % mod;
        }

        return dp[x][sum] = (take + not_take) % mod;
    }

public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        // n is the number of questions 

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, types, dp);
    }
};


// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

typedef long long ll;

class Solution {
private:    
    const int mod = 1e9 + 7;

    /*
    int f(int x, int sum, vector<vector<int>> &types, vector<vector<int>> &dp) {
        // base case: last index reached 
        if(x == 0) {
            if(sum % types[0][1] == 0 && sum / types[0][1] <= types[0][0]) return 1;
            else return 0;
        }

        if(dp[x][sum] != -1) return dp[x][sum];

        // option 1: dont take from the current 
        ll not_take = f(x - 1, sum, types, dp);

        // option 2: take x from the current for all x (solve x questions)
        int marks = types[x][1], q = types[x][0];

        ll take = 0;
        for(int solved = 1; solved <= q; solved++) {
            if(sum < solved * marks) break;

            take = (take + f(x - 1, sum - solved * marks, types, dp)) % mod;
        }

        return dp[x][sum] = (take + not_take) % mod;
    }
    */

public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        // n is the number of questions 

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        int q = types[0][0], mks = types[0][1];

        // base case: x = 0 
        for(int sum = 0; sum <= target; sum++) {
            if(sum % mks == 0 && sum / mks <= q) dp[0][sum] = 1;
        }

        for(int i = 1; i < n; i++) {
            for(int sum = 0; sum <= target; sum++) {
                int q = types[i][0], mks = types[i][1];

                // option 1: dont take from the current 
                ll not_take = dp[i - 1][sum];

                // option 2: solve x questions from the current 
                ll take = 0;
                for(int solved = 1; solved <= q; solved++) {
                    if(sum < solved * mks) break;
                    take = (take + dp[i - 1][sum - solved * mks]) % mod;
                }

                dp[i][sum] = (take + not_take) % mod;
            }
        }

        return dp[n - 1][target];
    }
};


// ============================================== Space Optimised Solution =============================================================================

// this space optimised solution uses prev and curr 1d arrays instead dp[x][W] => space complexity = O(Target)

class SpaceOptimisedSolution {
private:    
    const int mod = 1e9 + 7;

    /* Memoization 
    int f(int x, int sum, vector<vector<int>> &types, vector<vector<int>> &dp) {
        // base case: last index reached 
        if(x == 0) {
            if(sum % types[0][1] == 0 && sum / types[0][1] <= types[0][0]) return 1;
            else return 0;
        }

        if(dp[x][sum] != -1) return dp[x][sum];

        // option 1: dont take from the current 
        ll not_take = f(x - 1, sum, types, dp);

        // option 2: take x from the current for all x (solve x questions)
        int marks = types[x][1], q = types[x][0];

        ll take = 0;
        for(int solved = 1; solved <= q; solved++) {
            if(sum < solved * marks) break;

            take = (take + f(x - 1, sum - solved * marks, types, dp)) % mod;
        }

        return dp[x][sum] = (take + not_take) % mod;
    }
    */

public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        // n is the number of questions 

        vector<int> prev(target + 1, 0), curr(target + 1, 0);
        // prev => dp[i - 1] and curr => dp[i]

        int q = types[0][0], mks = types[0][1];

        // base case: x = 0 
        for(int sum = 0; sum <= target; sum++) {
            if(sum % mks == 0 && sum / mks <= q) prev[sum] = 1;
        }

        for(int i = 1; i < n; i++) {
            for(int sum = 0; sum <= target; sum++) {
                int q = types[i][0], mks = types[i][1];

                // option 1: dont take from the current 
                ll not_take = prev[sum];

                // option 2: solve x questions from the current 
                ll take = 0;
                for(int solved = 1; solved <= q; solved++) {
                    if(sum < solved * mks) break;
                    take = (take + prev[sum - solved * mks]) % mod;
                }

                curr[sum] = (take + not_take) % mod;
            }

            swap(prev, curr);
        }

        // after all the iterations prev => dp[n - 1]
        return prev[target];
    }
};