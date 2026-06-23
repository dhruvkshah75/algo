#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/stone-game-iii/description/

// Easy + Important question

/* Explanation: linear dp with game theory 
   The same concept of game theory where each recurrence instance indicates the current player status 
   and when f is recursively called then it indicates the turn of the other player 
   Here the recurrence f(ind) => diff between alice and bob's score 
   This can be considered as the MinMax game where Alice tries to maximize the diff = f
   and Bob tries to minimize the score 
   Starting with Alice's turn => if diff > 0 => alice wins, diff = 0 => tie and otherwise bob
*/

class Solution {
private:    
    static constexpr int N = 5e4+1;
    int dp[N];

    int f(int ind, vector<int> &stones, int n) {
        // base case: when all stones are picked => no more left 
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        // try all possible options of picking stones => 1, 2, 3
        int curr_sum = 0, maxi = INT_MIN;

        for(int j = ind; j < min(n, ind+3); j++) {
            curr_sum += stones[j];
            // subtract the score of the next player (recursive call)
            maxi = max(maxi, curr_sum - f(j+1, stones, n));
        }

        return dp[ind] = maxi;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        memset(dp, -1, sizeof(dp));

        // start the game from alice's turn
        int score = f(0, stoneValue, n);

        if(score > 0) return "Alice";
        else if(score == 0) return "Tie";
        else return "Bob";
    }
};
