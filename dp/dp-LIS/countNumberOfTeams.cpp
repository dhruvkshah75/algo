// ======================================================= dp - LIS ======================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// question link: https://leetcode.com/problems/count-number-of-teams/description/

/* Explaination: This question can be thought of as LIS variant 
   Reccurrence => f(ind, picked, asc) 
   ind => index of the array, picked => number of elements taken in the sequence
   asc => 0 = ascending and 1 = descending 
   2 types of sequences => rating[i] < rating[j] < rating[k] and rating[i] > rating[j] > rating[k]
   picked = 2 => means sequence of 3 is now ready 
*/

// =====================================================================================================================================================
//                                                  Top Down Approach Memoization dp 
// =====================================================================================================================================================

class Solution {
private:
    static constexpr int N = 1e4;
    int dp[N][2][2];

    int f(int ind, int picked, int asc, vector<int> &rating) {
        // base case: when the sequence is complete => picked a team of 3 
        if(picked == 2) return 1;

        if(dp[ind][picked][asc] != -1) return dp[ind][picked][asc];

        int cnt = 0;
        // ind is the first element of the seq => picked = 0 then asc does not matter 
        for(int j = 0; j < ind; j++) {
            if((picked == 0 || asc == 0) && rating[j] < rating[ind]) {
                // ascending seq => asc = 0
                cnt += f(j, picked+1, 0, rating);
            }
            else if((picked == 0 || asc == 1) && rating[j] > rating[ind]) {
                // descending seq => asc = 1
                cnt += f(j, picked+1, 1, rating);
            }
        }

        return dp[ind][picked][asc] = cnt;
    }

public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        memset(dp, -1, sizeof(dp));

        // calculate all the teams ending at the ith element (seq)
        int res = 0;

        for(int ind = 0; ind < n; ind++) {
            // initially we picked no element so picked = 0 => so asc doesnt matter 
            res += f(ind, 0, 0, rating);
        }

        return res;
    }
};

// =====================================================================================================================================================
//                                                  Bottom up Approach Tabulation dp 
// =====================================================================================================================================================

class Solution {
private:
    /*
    static constexpr int N = 1e4;
    int dp[N][2][2];

    int f(int ind, int picked, int asc, vector<int> &rating) {
        // base case: when the sequence is complete => picked a team of 3 
        if(picked == 2) return 1;

        if(dp[ind][picked][asc] != -1) return dp[ind][picked][asc];

        int cnt = 0;
        // ind is the first element of the seq => picked = 0 then asc does not matter 
        for(int j = 0; j < ind; j++) {
            if((picked == 0 || asc == 0) && rating[j] < rating[ind]) {
                // ascending seq => asc = 0
                cnt += f(j, picked+1, 0, rating);
            }
            else if((picked == 0 || asc == 1) && rating[j] > rating[ind]) {
                // descending seq => asc = 1
                cnt += f(j, picked+1, 1, rating);
            }
        }

        return dp[ind][picked][asc] = cnt;
    }
    */

public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        int dp[n][3][2];
        // dp[ind][picked][asc] = number of teams ending with ind 

        memset(dp, 0, sizeof(dp));

        // base case: picked == 2 => dp = 1
        for(int i = 0; i < n; i++) {
            for(int j: {0, 1}) {
                dp[i][2][j] = 1;
            }
        }   

        // in memo => picked goes from 0 to 2

        for(int ind = 0; ind < n; ind++) {
            for(int picked = 1; picked >= 0; picked--) {
                for(int asc: {0, 1}) {
                    // apply the logic of LIS 
                    int cnt = 0;

                    // if picked == 0 => then the first element so asc doesnt matter 
                    for(int j = 0; j < ind; j++) {
                        if((picked == 0 || asc == 0) && rating[j] < rating[ind]) {
                            // ascending seq => asc = 0
                            cnt += dp[j][picked+1][0];
                        }
                        else if((picked == 0 || asc == 1) && rating[j] > rating[ind]) {
                            // descending seq => asc = 1
                            cnt += dp[j][picked+1][1];
                        }
                    }

                    dp[ind][picked][asc] = cnt;
                }
            }
        }

        // the number of teams would be all the teams ending in ith index with 0 picked 
        int res = 0;

        for(int ind = 0; ind < n; ind++) {
            res += dp[ind][0][0];
        }

        return res;
    }
};