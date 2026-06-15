// ================================================================== front partition dp ====================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/partition-array-for-maximum-sum/description/

// Very important question and logic based on partition dp or front partition 

/* Explanation: uses the concept of front partition dp variant 
   This has a anathor trick in the question where the partition length must be at most k 
   recurrence => f(ind) => when we create partitions such that the length of partition created 
   is at most k 
   so inner loop for(int j = ind -> ind+k-1)
*/

typedef long long ll;

class Solution {
private:
    static constexpr int N = 501;
    ll dp[N];

    ll f(int ind, int n, int k, vector<int> &arr) {
        // base case: all elements of arr explored 
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        // try all possible front partiions 
        ll maxi = 0, max_ele = arr[ind];
        // end can go only till n and must be of max lenfth of k 
        int end = min(n, ind+k);

        for(int j = ind; j < end; j++) {
            // we make a partitions => j | j+1
            max_ele = max(max_ele, (ll)arr[j]);
            
            ll curr = (j-ind+1) * max_ele + f(j+1, n, k, arr);
            maxi = max(maxi, curr);        
        }

        return dp[ind] = maxi;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();

        memset(dp, -1, sizeof(dp));

        return (int)f(0, n, k, arr);
    }
};