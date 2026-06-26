// ============================================================== dp on strings ============================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/edit-distance/description


// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

/* Explaination: 
   At each step there were 3 possible options if the char didnt match 
   1. insert a new character in s1 
   2. delete the char in s1 and try finding somewhere else 
   3. replace the char in s1 to match
   
   to explore all these paths => use recursion 
   among all the options when char dont match => return the minimum of the three options or paths 

   recurrence f(i, j) => min no of operations to convert s1[0...i] to string s2[0....j]
*/

class RecursiveSolution {
private:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case: j < 0 (s2 done) => delete the remaining i
        if(j < 0) return i + 1;

        // base case: i < 0 (s1 done) => insert the remaining j chars 
        if(i < 0) return j + 1;

        if(dp[i][j] != -1) return dp[i][j];

        // explore all paths => when chars match and when they dont 
        if(s1[i] == s2[j]) 
            return dp[i][j] = f(i-1, j-1, s1, s2, dp);

        int ins = 1 + f(i, j-1, s1, s2, dp);   // inserted a new char in s1
        int del = 1 + f(i-1, j, s1, s2, dp);   // deleted s1[i] 
        int rep = 1 + f(i-1, j-1, s1, s2, dp); // replaced the char in s1 and matched 

        return dp[i][j] = min({ins, del, rep});
    }

public:
    int minDistance(string &s1, string &s2) {
        int n1 = s1.length(), n2 = s2.length();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return f(n1-1, n2-1, s1, s2, dp);
    }
};

// =========================================================================================================================================================
//                                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

class Solution {
private:
    /*
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case: j < 0 (s2 done) => delete the remaining i
        if(j < 0) return i + 1;

        // base case: i < 0 (s1 done) => insert the remaining j chars 
        if(i < 0) return j + 1;

        if(dp[i][j] != -1) return dp[i][j];

        // explore all paths => when chars match and when they dont 
        if(s1[i] == s2[j]) 
            return dp[i][j] = f(i-1, j-1, s1, s2, dp);

        int ins = 1 + f(i, j-1, s1, s2, dp);   // inserted a new char in s1
        int del = 1 + f(i-1, j, s1, s2, dp);   // deleted s1[i] 
        int rep = 1 + f(i-1, j-1, s1, s2, dp); // replace the char in s1 and match
        
        return dp[i][j] = min({ins, del, rep});
    }
    */

public:
    int minDistance(string &s1, string &s2) {
        int n1 = s1.length(), n2 = s2.length();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // dp[i][j] = min no of operations to make s1[0..i] equal to s2[0...j]

        // base case: j < 0 => dp = i (1 based indexing)
        for(int i = 1; i <= n1; i++) 
            dp[i][0] = i;

        // base case: i < 0 => dp = j
        for(int j = 1; j <= n2; j++) 
            dp[0][j] = j;


        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                // when chars match 
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                // when chars dont match => 3 possible paths to explore 
                else {
                    int ins = 1 + dp[i][j-1];   // insert the char in s1
                    int del = 1 + dp[i-1][j];   // delete s1[i]
                    int rep = 1 + dp[i-1][j-1]; // replace the char in s1 and match
                    dp[i][j] = min({ins, del, rep});
                }
            }
        }

        return dp[n1][n2];
    }   
};


// The tabulation solution can be space optimised to use O(min(N1, N2)) space complexity 

// ===============================================================================================================================================================
//                                                     Space Optimised Bottom up approach (Tabulation) dp
// ===============================================================================================================================================================

class SpaceOptimisedSolution {
private:
    /*
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case: j < 0 (s2 done) => delete the remaining i
        if(j < 0) return i + 1;

        // base case: i < 0 (s1 done) => insert the remaining j chars 
        if(i < 0) return j + 1;

        if(dp[i][j] != -1) return dp[i][j];

        // explore all paths => when chars match and when they dont 
        if(s1[i] == s2[j]) 
            return dp[i][j] = f(i-1, j-1, s1, s2, dp);

        int ins = 1 + f(i, j-1, s1, s2, dp);   // inserted a new char in s1
        int del = 1 + f(i-1, j, s1, s2, dp);   // deleted s1[i] 
        int rep = 1 + f(i-1, j-1, s1, s2, dp); // replace the char in s1 and match

        return dp[i][j] = min({ins, del, rep});
    }
    */

public:
    int minDistance(string &s1, string &s2) {
        // keep s2 as the smaller string 
        if(s1.length() < s2.length()) swap(s1, s2);

        int n1 = s1.length(), n2 = s2.length();

        vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);
        // prev => dp[i - 1] and curr => dp[i]  
        // dp[i][j] = min no of operations to make s1[0..i] equal to s2[0...j]

        // base case: j < 0 => dp = i (1 based indexing)
        // base case: i < 0 => dp = j
        
        for(int j = 1; j <= n2; j++) prev[j] = j;

        for(int i = 1; i <= n1; i++) {
            curr[0] = i;

            for(int j = 1; j <= n2; j++) {
                // when chars match 
                if(s1[i-1] == s2[j-1]) {
                    curr[j] = prev[j-1];
                }
                // when chars dont match => 3 possible paths to explore 
                else {
                    int ins = 1 + curr[j-1];   // insert the char in s1
                    int del = 1 + prev[j];   // delete s1[i]
                    int rep = 1 + prev[j-1]; // replace the char in s1 and match
                    curr[j] = min({ins, del, rep});
                }
            }

            swap(prev, curr);
        }

        return prev[n2];
    }   
};