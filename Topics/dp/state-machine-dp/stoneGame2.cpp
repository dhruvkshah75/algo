#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/stone-game-ii/description/

// Pretty easy question => important for understanding dp with game theory in memoization 

/* Explanation: multi state dp 
   dp with game theory => current recurrence means current player and the recursive call that 
   is made it indicates the next player 

   the recurrence must contain two states => index denoting the what piles are available from here 
   and M indicating number of max number of piles that can be taken 

   recurrence = f(ind, M) => ind = stones piles in suffix[ind...n]
   f => the diff between the stones gained by alice and bob => alice - bob = diff
   we know alice + bob = total => alice = (total + diff) / 2
   To maximize alice's stones => we must maximize the diff i.e. the recurrence 
*/

class Solution {
private:
    static constexpr int N = 1e2+1;
    int dp[N][N];

    int f(int ind, int M, vector<int> &prefix, int n) {
        // base case: all stones piles are processed 
        if(ind > n) return 0;

        if(dp[ind][M] != -1) return dp[ind][M];

        // current player collects the X piles (1 <= X <= 2*M)
        int maxi = -1e8;

        for(int j = ind; j <= min(ind + 2*M - 1, n); j++) {
            // take ind -> j piles 
            int taken = j-ind+1;
            int next_m = max(M, taken);

            // subtract the next player's taken piles
            int curr = (prefix[j] - prefix[ind-1]) - f(j+1, next_m, prefix, n);
            maxi = max(maxi, curr);
        }

        return dp[ind][M] = maxi;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // using prefix sum to get the sum of ranges in O(1) => 1 based indexing 
        vector<int> prefix(n+1, 0);

        for(int i = 1; i <= n; i++) 
            prefix[i] = prefix[i-1] + piles[i-1];

        int total = prefix[n];

        memset(dp, -1, sizeof(dp));

        return (total + f(1, 1, prefix, n)) / 2;
    }
};
