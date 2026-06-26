#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/stone-game/description/

/* Explanation: dp on multiple states 
   true if Alice wins the game and false if Bob wins the game 
   sum(piles[i]) is odd => means a tie cannot occur 
   Alice or Bob can take stones from the end or the start => either taking ith or jth 
   When Alice and bob both play optimally means both try to win 

   So frame the question like diff = Alice Sum - Bob Sum 
   if the diff > 0 => Alice wins and if negative Bob wins (cant be 0 as total sum is odd)
   recurrence => f(i, j) => i and j are pointers to denote the start and end choice we have 
   We dont need a player state => if even number of elements are left then Alice turn 
   and when odd number of elements are left then 

   The solution is actually quite basic => Alice starts first so she always wins => return true
*/

class Solution {
private:
    static constexpr int N = 500;
    int dp[N][N];

    int f(int i, int j, vector<int> &piles) {
        // base case: when no more stones are left
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // alice or bob both try to minimize each others score 
        // alice turn => even piles left, bobs turn => odd piles left
        int add_i = ((j-i+1) % 2 == 0) ? piles[i] : -piles[i];
        int add_j = ((j-i+1) % 2 == 0) ? piles[j] : -piles[j];

        int pick_i = add_i + f(i+1, j, piles);
        int pick_j = add_j + f(i, j-1, piles); 

        return dp[i][j] = max(pick_i, pick_j);
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        memset(dp, -1, sizeof(dp));

        int res = f(0, n-1, piles);

        // if res is positive then Alice Sum > Bob sum return true otherwise false
        return (res > 0);
    }
};