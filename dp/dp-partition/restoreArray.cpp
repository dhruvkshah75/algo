// ================================================================== front partition dp ====================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/restore-the-array/description/

// ===================================================== Important Question ===========================================================

/* Explanation: Front partition dp 
   we must create partition that can have a max length of digits[k]
   so in the worst case it can be 10 as k <= 1e9 (10 digits) 
   
   recurrence => f(ind) = no of different possible sequences be formed such that each partition belongs to [1,k]
   in suffix s[ind...n]
   d => digits in k 
   base case must include the case to prevent partitions with numbers having leading zeros 

   instead of using the digits logic => keep the count of the current number (instead of string) 
   and compare with k in O(1) and then whenever the curr > k break as increasing one more digit will also make it big 
   If the number exceeds k, any further digits will also exceed k 
*/

typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;
    static constexpr int N = 1e5;
    int dp[N];

    int f(int ind, int k, string &s) {
        // base case: string s fully explored 
        if(ind == s.length()) return 1;

        // base case: ind is 0 => the partition will have leading zeros 
        if(s[ind] == '0') return 0;

        if(dp[ind] != -1) return dp[ind];
        
        // try partitioning with max size of d 
        // maintain a number instead of string for O(1) comparision
        ll res = 0, curr = 0;

        for(int j = ind; j < s.length(); j++) {
            // create a partition j | j+1
            curr = curr * 10 + (s[j]-'0');

            if(curr > k) break;

            res = (res + f(j+1, k, s)) % MOD;
        }

        return dp[ind] = res % MOD;
    }

public:
    int numberOfArrays(string &s, int k) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));

        return f(0, k, s);
    }
};