// ======================================================== partition dp ======================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

/* Explanation: partition dp 
   So is simple words we are supposed to make n-2 triangles by picking 3 vertices 
   So keep i, j fixed and then try for all k vertices => partition dp 
   Start with the entire block of polygon => Vertex 0 to Vertex N-1 
   after choosing the k as the partition index => triangle formed is (i, k, j) 
   then the problem divides into two subrproblems where further more triangles can be formed 
   subproblems are f(i, k) and f(k, j) 

   recurrence => f(i, j) => i, j are the fixed vertices of the polygon with i and j 
   as the starting and ending vertices 
*/

class Solution {
private:
    int dp[50][50];

    int f(int i, int j, vector<int> &values) {
        // base case: no triangle can be formed for the current subproblem
        if(j-i < 2) return 0;

        // base case: this is the last triangle (no further subproblems)
        if(j-i == 2) return values[i] * values[i+1] * values[i+2];

        if(dp[i][j] != -1) return dp[i][j];

        // try all possible partitions 
        int res = 1e9;

        for(int k = i+1; k < j; k++) {
            // form a triangle => i,k,j
            int curr = values[i] * values[k] * values[j] + f(i, k, values) + f(k, j, values);
            res = min(res, curr);
        }

        return dp[i][j] = res;
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        memset(dp, -1, sizeof(dp));

        // starting from the entire problem of n sides convex polygon 
        return f(0, n-1, values);
    }
};