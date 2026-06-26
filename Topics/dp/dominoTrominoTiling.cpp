// =============================================== multi state dp + counting dp =======================================

#include<bits/stdc++.h> 
using namespace std;

// question link: https://leetcode.com/problems/domino-and-tromino-tiling/description/

/* Explanation: multi state dp 
 * Seems quite complex at first but simple if the question is defined in terms of states 
 * state = 0 => the new tile that we can place has both rows available 
 * state = 1 => tromino tile was placed earlier and now we are at (1, ind)
 * state = 2 => tromino tile was placed and now we are at (0, ind) and (1, ind) is already filled 
 *
 * Base case:
 * if the tile placed earlier exceeds out of the cell then return 0
 * or if just finished the grid with state = 0 (means no tile reaching outside the grid) both rows are available at ind = n 
 *
 * Recurrence => f(ind, state) => ind is the index for the column in the grid and state denotes what rows are available  
 * to us now for placing newer tiles 
 */

typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;
    static constexpr int N = 1e3+1;
    int dp[N][3];

    int f(int ind, int state, int n) {
        // base case: if the tiles exceed the grid => invalid 
        if(ind > n) return 0;

        // base case: if the grid is filled completely with both rows at ind = n available 
        if(ind == n) return (state == 0);

        if(dp[ind][state] != -1) return dp[ind][state];

        ll res = 0;

        // consider all ways of placing the tiles depending on the prev_state
        if(state == 0) {
            // place either domino or tromino 
            int domino = (f(ind+2, 0, n) * 1LL + f(ind+1, 0, n)) % MOD;
            int tromino = (f(ind+1, 1, n) * 1LL + f(ind+1, 2, n)) % MOD;

            res = (res + domino + tromino) % MOD;
        }
        else if(state == 1) {
            // currently at (1, ind) 
            int domino = f(ind+1, 2, n);
            int tromino = f(ind+2, 0, n);

            res = (res + domino + tromino) % MOD;
        }
        else if(state == 2) {
            // currently at (0, ind)
            int domino = f(ind+1, 1, n);
            int tromino = f(ind+2, 0, n);

            res = (res + domino + tromino) % MOD;
        }

        return dp[ind][state] = res % MOD;
    }

public:
    int numTilings(int n) {
        memset(dp, -1, sizeof(dp));

        // start from ind = 0 with both rows available => state = 0
        return f(0, 0, n);
    }
};