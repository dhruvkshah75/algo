// =========================================================== state-machine dp ==================================================================

#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/paint-house-iii/description/

/* Note: houses != 0 => already painted last summer 
   We must paint the houses not painted already such that cost of painting is minimum 
   and there are exactly target number of neighbourhoods 
   eg. [2, 2, 1, 2, 3] => this has 4 neighbourhoods = [{2, 2}, {1}, {2}, {3}]
   At the end there should be exactly target number of neighbourhoods

   f(ind, prev_color, nbg) => 3 states needed to describe the problem 
   ind => currently at what house, prev_color => what is the color of the previously painted house 
   nbg => number of neighbourhoods left 
*/

// ================================================================================================================================================================
//                                                      Memoization Top Down Approach dp
// ================================================================================================================================================================

class RecursiveSolution {
private:
    int M, N;

    const int inf = 1e8; 
    int dp[105][25][105];

    int f(int ind, int prev_color, int nbg, vector<int> &houses, vector<vector<int>> &cost) {
        // base case: if target neigbourhoods exceeded => painting becomes invalid
        if(nbg < 0) return inf;

        // base case: all houses processed with a valid case 
        if(ind < 0) {
            if(nbg == 0) return 0;
            else return inf;
        }

        if(dp[ind][prev_color][nbg] != -1) return dp[ind][prev_color][nbg];

        // case 1: House already painted or case 2: house needs to be painted
        int res = inf;

        if(houses[ind] != 0) {
            // already painted in color = house[ind]
            int curr_color = houses[ind];
            int newNbg = (curr_color == prev_color) ? nbg : nbg - 1;

            res = min(res, f(ind-1, curr_color, newNbg, houses, cost));
        }
        else {
            // house to be painted => try out all possible colors 
            for(int j = 1; j <= N; j++) {
                // prev painted house color is the same 
                int newNbg = (j == prev_color) ? nbg : nbg - 1;
                res = min(res, cost[ind][j-1] + f(ind-1, j, newNbg, houses, cost));
            }
        }

        return dp[ind][prev_color][nbg] = res;
    }

public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->M = m;
        this->N = n;
        // m houses and n colors (1 to n)
        memset(dp, -1, sizeof(dp));

        int ans = f(M-1, 0, target, houses, cost);

        return (ans >= inf) ? -1 : ans; 
    }
};
// Time Complexity = O(M * N * Target * N), Space Complexity = O(M * N * Target) + O(M)


