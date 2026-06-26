#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/decode-ways/description/

/* Explaination: Linear dp => only one state is used to describe and based on counting 
   each number can itself be decoded except '0' so 0 cannot be left alone => it must be combined with 1 or 2 that is prev to it 
   if something else is in the prev then simply return 0
   only '1' (0...9) and '2' (0...6) can combine with the next number 
*/

class Solution {
private: 
    static constexpr int N = 100;
    int dp[N];

    int f(int ind, string &s) {
        // base case: string processed completely 
        if(ind == s.length()) return 1;

        // base case: current element is '0' => invalid decoding
        if(s[ind] == '0') return 0;

        if(dp[ind] != -1) return dp[ind];

        // case 1: each element can itself be decoded 
        int ways = f(ind+1, s);

        // case 2: s[ind] = 1 can combine with any of the next number 
        if(ind+1 < s.length() && s[ind] == '1') 
            ways += f(ind+2, s);

        // case 3: s[ind] = 2 can combine with next char [0..6] and can be decoded
        if(ind+1 < s.length() && s[ind] == '2' && s[ind+1] <= '6' && s[ind+1] >= '0')
            ways += f(ind+2, s);

        return dp[ind] = ways;
    }

public:
    int numDecodings(string &s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));

        // start decoding the string from the first index 
        return f(0, s);
    }
};
// Space Complexity = O(N) + O(N), Time Complexity = O(N)