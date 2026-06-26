#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

/* Explanation: LIS variant with the only diff being that we know what element comes before and after 
   Since we know what element waht comes before => use a hash map to store all the indices of the occurring element 
   f(ind) => length of longest arithmetic sequence ending in arr[ind]
   Using a hash map to store the length of the longest arithmetic subsequence ending at each value.(instead of index)
*/

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int diff) {
        int n = arr.size();

        unordered_map<int,int> dp;
        // dp[element] = max length of the sequence ending with this element 
        int res = 1;

        for(int ind = 0; ind < n; ind++) {
            int nxt = arr[ind] - diff;
            int curr = arr[ind];

            if(dp.count(nxt)) {
                // found the prev element of the seq 
                dp[curr] = dp[nxt] + 1;
            }
            else {
                // did not find the prev element => start a new sequence 
                dp[curr] = 1;
            }

            res = max(res, dp[curr]);
        }

        // finally return the max length of seq ending in any value 
        return res;
    }
};