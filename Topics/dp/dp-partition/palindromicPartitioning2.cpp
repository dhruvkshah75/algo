// ================================================================== partition dp ====================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/palindrome-partitioning-ii/description/

// Very Difficult question involving the use of 2 concepts of longest palindromic substring and front partition 

/* different from mcm partition dp question
   we use a concept called front partition => why we use this becuase the worst answer is equal to N-1 partitions 
   we start from the front index and check cases by creating partitions at each step

   eg. baba... => we start from i at b and do something like 1 + (aba...) => we create a partition there 
   we try all these partitions in this way => but we only create valid partitions such that the one we got in the front 
   is a palindrome => we cannot create a  partition like ba + (ba....) as ba is not a palindrome 

   This is front partition as we gone from the front and then keep checking the possible partitions 

   We are splitting into subproblems based on how we make the first cut in s[ind....n]
   this makes the question into a front partition => much more intutive then mcm partition logic 

   Recurrence = f(ind) => we need to know only one starting index => this is where we start making our partitions 

   Also use anathor dp vector to use caching for palindromic checks for s[i...j] is a palindrome 
*/

class Solution {
private:
    static constexpr int N = 2e3;
    int dp[N];
    int dpPalindrome[N][N];

    // precompute dpPalindrome in O(N^2) using longest palindromic concept
    bool isPalindrome(int i, int j, string &s) {
        // base case: check all characters in s[i..j]
        if(i > j) return true;

        if(dpPalindrome[i][j] != -1) return dpPalindrome[i][j];

        bool res = false;
        if(s[i] == s[j]) res = isPalindrome(i+1, j-1, s);
        
        return dpPalindrome[i][j] = res;
    }


    int f(int ind, int n, string &s) {
        // base case: complete string is explored 
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        // using concept of front partition to get min cuts needed 
        int mini = 1e8;

        for(int j = ind; j < n; j++) {
            // make the cut between j and j+1 => (j | j+1)
            if(dpPalindrome[ind][j]) {
                mini = min(mini, 1 + f(j+1, n, s));
            }
        }

        return dp[ind] = mini;
    }

public:
    int minCut(string &s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));

        // precompute all substrings of s are palindromes or not using dp using the concept of longest palindromic substring in O(N^2)
        memset(dpPalindrome, -1, sizeof(dpPalindrome));

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                // we just want to call the function for all possible i,j
                if(isPalindrome(i, j, s)) {}
            }
        }

        // return the case of complete string => start partitioning from the start 
        // f returns the total number of partitions made (cuts = partitions - 1)
        return f(0, n, s) - 1;
    }
};