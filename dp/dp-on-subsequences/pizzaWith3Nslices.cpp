// ====================================================== knapsack dp =========================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/pizza-with-3n-slices/description/

/* Explanation: knapsack dp variant 
   This question transalates to a very simple question => Out of the given 3n elements 
   u are supposed to pick up n elements to get the max score in such a way that no two elements are adjacent 
   and the given array is circular 

   So we write a simple recurrence f(ind, remaining) to get the max score 
   to deal with the circular array part => use the concept og House Robber 2
   first solve for the array slices[1...n-1] and then for slices [0...n-2] => this ensures that 0th element and 
   n-1 th element are never taken at the same time  

   f(ind, remaining) = max points gained in the suffix[ind..end] with remaining picks
*/

class Solution {
private: 
    int dp[500][170];
    // dp[ind][remaining]

    int f(int ind, int remaining, vector<int> &slices, int end) {
        // base case: when all remaining elements are taken 
        if(remaining == 0) return 0;

        // base case: all elements explored but N elements arent picked 
        if(ind > end) return -1e9;

        if(dp[ind][remaining] != -1) return dp[ind][remaining];

        // 0-1 knapsack 
        // case 1: dont take the element => go to ind+1
        int not_take = f(ind+1, remaining, slices, end);

        // case 2: take the element => go to ind+2 (adjacent cant be taken)
        int take = slices[ind] + f(ind+2, remaining-1, slices, end);

        return dp[ind][remaining] = max(take, not_take);
    }


public:
    int maxSizeSlices(vector<int>& slices) {    
        int n = slices.size();

        // f(.., end) => end indicates the last allowed index of element 
        // to deal with circular array (arr[n-1], arr[0]) => take max of two instances 
        
        int res = -1e9;

        memset(dp, -1, sizeof(dp));
        // 1. considering the vector as [0...n-2] (skipping out arr[n-1] => last element)
        res = max(res, f(0, n/3, slices, n-2));

        memset(dp, -1, sizeof(dp));
        // 2. considering the vector as [1...n-1] (skipping out arr[0] => first element)
        res = max(res, f(1, n/3, slices, n-1));

        return res;
    }
};