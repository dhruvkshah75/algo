// =========================================================== partition dp =========================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

// question link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

/* Explanation: partition dp question 
   We create partitions => [i..k] and [k+1..j]
   both the partitions indicate the left and right subtree for the node whose children are [i..j]
   The value of this non leaf node is product of max of leaf nodes in the left substree and right subtree 
   max(arr[i..k]) * max(arr[k+1..j]) => to calculate the max for any any range we precompute the max elements 
   in time complexity = O(N^3) => this prevents the entire code going into the time complexity of O(N^4)

   Final Time Complexity = O(N^3) 

   Base cases => if there are even leaf nodes then i+1 == j => 2 nodes left no more partition can be created 
   if(i+1 == j) return arr[i] * arr[j]
   and the other base case is for odd leaf nodes => if(i == j) return arr[i] 
*/

class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<int>> mx;

    int f(int i, int j, vector<int> &arr) {
        // base case: only 2 nodes left => both leaf nodes (so a parent exists)
        if(i+1 == j) return arr[i] * arr[j];

        // base case: partition becomes invalid 
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // try all possible partitions 
        int res = 1e9;

        for(int k = i; k < j; k++) {
            // create a partition k | k+1
            int curr = mx[i][k] * mx[k+1][j] + f(i, k, arr) + f(k+1, j, arr); 
            res = min(res, curr); 
        }

        return dp[i][j] = res;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        dp.resize(n, vector<int>(n, -1));
        mx.resize(n, vector<int>(n, -1));

        // mx[i][j] = max element in the subarray => arr[i...j]
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                // find max element in arr[i..j]
                int maxi = -1;

                for(int k = i; k <= j; k++) 
                    maxi = max(maxi, arr[k]);

                mx[i][j] = maxi;
            }
        }
        // O(N^3)

        return f(0, n-1, arr);
    }
};