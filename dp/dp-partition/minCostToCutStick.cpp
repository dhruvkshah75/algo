// ============================================================= Partition dp =============================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

// question link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

/* i, j is used to denote the entire block => i is the start index anf j is the end index 
   try out all the cuts possible 
   j and i represent the indices of the cut array 
   => at the start it is given by i = 0 and j = m - 1 (representing the entire block)
   insert cut = 0 and cut = N (The end points) in the cuts array so that the entire stick gets represented 

   The partition made will be f(i, k) and f(k, j) not f(k+1, j) 
   As this will completely ignore the rod of length cuts[k+1] - cuts[k] => which is logical error
*/

// ========================================================================================================================
//                                  Memoization - Top Down Approach dp 
// ========================================================================================================================

#define all(x) x.begin(), x.end()

class Solution {
private:

    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        // base case: partition has no cuts in between (j - i = 1)
        if(j - i <= 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // try out all the partitions 
        int res = 1e9;

        for(int k = i+1; k < j; k++) {
            int cost = (cuts[j] - cuts[i]) + f(i, k, cuts, dp) + f(k, j, cuts, dp);
            res = min(res, cost);
        }

        return dp[i][j] = res;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        // add the boundary conditions to make the dp work 
        cuts.push_back(0);
        cuts.push_back(n);

        int m = cuts.size();
        // m number of cuts are to made 
        // sort the cuts array so we uniformly check all possible cut options 
        sort(all(cuts));

        vector<vector<int>> dp(m, vector<int>(m, -1));

        // start from the entire block => complete rod length (as we added 0 and N in the cuts)
        return f(0, m-1, cuts, dp);
    }
};


// =========================================================================================================================
//                                Tabulation - Bottom Up approach dp
// =========================================================================================================================

class Solution {
private:
    
    /*
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        // base case: partition is invalid
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // try out all the partitions 
        int res = 1e9;

        for(int k = i; k <= j; k++) {
            int cost = (cuts[j+1] - cuts[i-1]) + f(i, k-1, cuts, dp) + f(k+1, j, cuts, dp);
            res = min(res, cost);
        }

        return dp[i][j] = res;
    }
    */

public:
    int minCost(int n, vector<int>& cuts) {
        // add the boundary conditions to make the dp work 
        cuts.push_back(0);
        cuts.push_back(n);

        int m = cuts.size();
        // m number of cuts are to made 
        // sort the cuts array so we uniformly check all possible cut options 
        sort(all(cuts));

        vector<vector<int>> dp(m, vector<int>(m, 0));

        // in memo => i = 1 to m-2 => i goes reverse in tabulation 
        // memo => j = m-2 to 1 =>j goes reverse

        for(int i = m-2; i >= 1; i--) {
            for(int j = i; j <= m-2; j++) {
                // cuts[i...j] contains all allowed partitions, stick endpoints are cuts[j+1] and cuts[i-1]
                int res = 1e9;

                for(int k = i; k <= j; k++) {
                    int cost = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    res = min(res, cost);
                }

                dp[i][j] = res;
            }
        }

        // return the min cost to break a stick from cuts[1..m-2]
        return dp[1][m-2];
    }
};