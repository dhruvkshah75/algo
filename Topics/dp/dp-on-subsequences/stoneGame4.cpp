// ===================================================== linear dp and dp with game theory ===========================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/stone-game-iv/description/

/* Explanation: linear dp + dp with game theory 
   In game theory dp questions use the current instance of recurrence to denote the current player 
   when the recurrence is called in the main function => alice is the current player 
   and whenever the recurrence is recursively called it is the next players turn that comes in 

   Here for n stones => try picking out all possible stones (perfect squares) sqrt(N)
   when does a player lose => 1. stones == 0 => no more turns are possible 
   2. when the next player wins => recursive call of f returns true 
*/

class Solution {
private:
    static constexpr int N = 1e5+1;
    int dp[N];

    bool f(int stones) {
        // base case: when no more stones are left 
        if(stones == 0) return false;

        if(dp[stones] != -1) return dp[stones];

        // current player picks all possible cases of perfect squares 
        for(int i = 1; i*i <= stones; i++) {
            int remaining = stones - i*i;

            // with the remaining stones the next player loses then curr player wins (true)
            if(!f(remaining)) {
                return dp[stones] = 1;
            }
        }

        // any no of stones picked by curr player does not make the other player loose 
        // then the curr player has lost => return false
        return dp[stones] = 0;
    }

public:
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));

        // in the start alice is the current player and we want the case of alice's winning or loosing 
        return f(n);
    }
};