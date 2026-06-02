// ==================================================================== dp on subsequences ===================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://takeuforward.org/plus/dsa/problems/rod-cutting-problem

/* We are supposed to cut the rod of length N into pieces such that sum of all pieces is N (obviously)
   price[i] = p => p is price of rod of length i 
   Break the rod into pieces to get the price sum as maximum 
   This is simple unbounded Knapsack 
*/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class RecursiveSolution {
private: 
    int f(int x, int sum, vector<int> &price, vector<vector<int>> &dp) {
        // base case: last index reached
        if(x == 0) {
            // can x + 1 inches make up sum inches of rod => true always 1 inch can be added multiple times 
            if(sum % (x + 1) == 0) return sum * price[0];
        }

        if(dp[x][sum] != -1) return dp[x][sum];

        // option 1: dont take the current (x + 1) length piece 
        int not_take = f(x - 1, sum, price, dp);

        // option 2: take this current (x + 1) length piece 
        int take = -1e8;
        if(sum >= x + 1) take = price[x] + f(x, sum - (x + 1), price, dp);

        return dp[x][sum] = max(take, not_take);
    }

public: 
    int cutRod(vector<int> &price, int N) {
        int m = price.size();   
        // there are prices of m pieces of rods 
        // target = N

        vector<vector<int>> dp(m, vector<int>(N + 1, -1));

        return f(m - 1, N, price, dp);
    }   
};

// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

class Solution {
private: 
    /*
    int f(int x, int sum, vector<int> &price, vector<vector<int>> &dp) {
        // base case: last index reached
        if(x == 0) {
            // can x + 1 inches make up sum inches of rod => true always 1 inch can be added multiple times 
            if(sum % (x + 1) == 0) return sum * price[0];
        }

        if(dp[x][sum] != -1) return dp[x][sum];

        // option 1: dont take the current (x + 1) length piece 
        int not_take = f(x - 1, sum, price, dp);

        // option 2: take this current (x + 1) length piece 
        int take = -1e8;
        if(sum >= x + 1) take = price[x] + f(x, sum - (x + 1), price, dp);

        return dp[x][sum] = max(take, not_take);
    }
    */

public: 
    int cutRod(vector<int> &price, int N) {
        int m = price.size();   
        // there are prices of m pieces of rods 
        // target = N

        vector<vector<int>> dp(m, vector<int>(N + 1, 0));

        // base case: => x = 0
        for(int sum = 0; sum <= N; sum++) {
            // with x = 0 => length of rod piece = 1 we can always break the rod into sizes of t
            dp[0][sum] = sum * price[0]; 
        }

        for(int i = 1; i < m; i++) {
            for(int sum = 0; sum <= N; sum++) {
                // explore the 2 options 
                int not_take = dp[i - 1][sum];
                int take = -1e8;
                if(sum >= i + 1) take = price[i] + dp[i][sum - (i + 1)];

                dp[i][sum] = max(take, not_take);
            }
        }

        // max price earned in breaking the rod of length N till the m - 1 th index 
        return dp[m - 1][N];
    }       
};


// This tabulation solution can be space optimised to get space complexity = O(N)
// replacing dp[i - 1][t] = prev[t] and dp[i][t] = curr[t]  


class SpaceOptimisedSolution {
private: 
    /*
    int f(int x, int sum, vector<int> &price, vector<vector<int>> &dp) {
        // base case: last index reached
        if(x == 0) {
            // can x + 1 inches make up sum inches of rod => true always 1 inch can be added multiple times 
            if(sum % (x + 1) == 0) return sum * price[0];
        }

        if(dp[x][sum] != -1) return dp[x][sum];

        // option 1: dont take the current (x + 1) length piece 
        int not_take = f(x - 1, sum, price, dp);

        // option 2: take this current (x + 1) length piece 
        int take = -1e8;
        if(sum >= x + 1) take = price[x] + f(x, sum - (x + 1), price, dp);

        return dp[x][sum] = max(take, not_take);
    }
    */

public: 
    int cutRod(vector<int> &price, int N) {
        int m = price.size();   
        // there are prices of m pieces of rods 
        // target = N

        vector<int> prev(N + 1, 0), curr(N + 1, 0);

        // base case: => x = 0
        for(int sum = 0; sum <= N; sum++) {
            // with x = 0 => length of rod piece = 1 we can always break the rod into sizes of t
            prev[sum] = sum * price[0]; 
        }

        for(int i = 1; i < m; i++) {
            for(int sum = 0; sum <= N; sum++) {
                // explore the 2 options 
                int not_take = prev[sum];
                int take = -1e8;
                if(sum >= i + 1) take = price[i] + curr[sum - (i + 1)];

                curr[sum] = max(take, not_take);
            }

            swap(curr, prev);
        }

        // max price earned in breaking the rod of length N till the m - 1 th index 
        return prev[N];
    }       
};