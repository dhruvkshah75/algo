// =================================================================== dp on subsequences =============================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/reducing-dishes/description/

/* Explaination: This is a 0-1 Knapsack question
   As there is a choice to make the dish or not 
   explore both the cases => the chef makes the current dish at time t to get satisfaction[i]
   Recurrence => f(ind, time) = max like-time coffecient till the ind th dish in time 
   
   When q says can be processed in any order => something greedy comes in or sorting can be used 

   Since the dished can be made in any order => it is a greedy choice to get the dish with more satisfaction 
   be made at a higher time so sort the dishes based on satisfaction
*/

// ========================================================================================================================================
//                                                 Top Down Approach Memoization dp
// =========================================================================================================================================

#define all(x) x.begin(), x.end()

class Solution {
private:
    static constexpr int N = 501;
    int dp[N][N];

    int f(int ind, int time, vector<int> &s) {
        // base case: when all the dishes were proccessed 
        if((size_t)ind == s.size()) return 0;

        if(dp[ind][time] != -1) return dp[ind][time];

        // case 1: dont make the current dish so time remains the same 
        int not_take = f(ind+1, time, s);

        // case 2: make the current dish so time for making the next dish becomes time+1
        int take = time * s[ind] + f(ind+1, time+1, s);

        return dp[ind][time] = max(not_take, take);
    }

public:
    int maxSatisfaction(vector<int> &s) {
        int n = s.size();

        // sort the dishes based on their satisfaction to greedily make the dish with higher s[i] at a later time 
        sort(all(s));

        memset(dp, -1, sizeof(dp));

        // starting from the 0th dish and to make the first dish at time t = 1
        return f(0, 1, s);
    }
};
// Space Complexity = O(N^2) + O(N)


// ====================================================================================================================================
//                                          Bottom up Approach Tabulation dp
// ====================================================================================================================================

#define all(x) x.begin(), x.end()

class Solution {
private:
    static constexpr int N = 501;
    int dp[N][N];

    /*
    int f(int ind, int time, vector<int> &s) {
        // base case: when all the dishes were proccessed 
        if((size_t)ind == s.size()) return 0;

        if(dp[ind][time] != -1) return dp[ind][time];

        // case 1: dont make the current dish so time remains the same 
        int not_take = f(ind+1, time, s);

        // case 2: make the current dish so time for making the next dish becomes time+1
        int take = time * s[ind] + f(ind+1, time+1, s);

        return dp[ind][time] = max(not_take, take);
    }
    */

public:
    int maxSatisfaction(vector<int> &s) {
        int n = s.size();

        // sort the dishes based on their satisfaction to greedily make the dish with higher s[i] at a later time 
        sort(all(s));

        memset(dp, 0, sizeof(dp));

        // base case: ind == n => dp = 0
        for(int j = 0; j < n; j++) 
            dp[n][j] = 0;


        for(int ind = n-1; ind >= 0; ind--) {
            for(int t = n; t >= 1; t--) {
                // case 1: dont make the current dish so time remains the same
                int not_take = dp[ind+1][t];

                // case 2: make the current dish so time for making the next dish becomes time+1
                int take = t * s[ind];
                if(t+1 <= n) take += dp[ind+1][t+1];

                dp[ind][t] = max(take, not_take);
            }
        }

        // return for the 0th day and at time t = 1
        return dp[0][1];
    }
};
// Space Complexity = O(N^2)


// The above solution can also be space optimised as each entry depends on dp[ind+1]

#define all(x) x.begin(), x.end()

class SpaceOptimisedSolution {
private:
    // static constexpr int N = 501;
    // int dp[N][N];

    /*
    int f(int ind, int time, vector<int> &s) {
        // base case: when all the dishes were proccessed 
        if((size_t)ind == s.size()) return 0;

        if(dp[ind][time] != -1) return dp[ind][time];

        // case 1: dont make the current dish so time remains the same 
        int not_take = f(ind+1, time, s);

        // case 2: make the current dish so time for making the next dish becomes time+1
        int take = time * s[ind] + f(ind+1, time+1, s);

        return dp[ind][time] = max(not_take, take);
    }
    */

public:
    int maxSatisfaction(vector<int> &s) {
        int n = s.size();

        // sort the dishes based on their satisfaction to greedily make the dish with higher s[i] at a later time 
        sort(all(s));

        vector<int> ahead(n+1, 0), curr(n+1, 0);
        // ahead => dp[ind+1] and curr => dp[ind] 

        // base case: ind == n => dp = 0

        for(int ind = n-1; ind >= 0; ind--) {
            for(int t = n; t >= 1; t--) {
                // case 1: dont make the current dish so time remains the same
                int not_take = ahead[t];

                // case 2: make the current dish so time for making the next dish becomes time+1
                int take = t * s[ind];
                if(t+1 <= n) take += ahead[t+1];

                curr[t] = max(take, not_take);
            }
            swap(curr, ahead);
        }

        // return for the 0th day and at time t = 1
        return ahead[1];
    }
};
// Space Complexity = O(N), Time Complexity = O(N^2)