// ================================== front partition dp =================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/palindrome-partitioning-iii/description/

/**
 * we are suppose to create k paritions starting from the front 
 * if the partition is not a valid palindrome then we are allowed to change any number of characters 
 * in it to get the a palindrome 
 * eg: abc => to make this into a palindrome we can just replace c by a 
 * 
 * precompute the number of changes needed to convert all the substrings into palindromes 
 * this can be done by using dp as well => changes (dp array) changes[i][j] = min number of 
 * character changes that are needed to convert this substring into palindrome
 * This method is similar to check if the substring is palindrome or not in O(N^2)
 * 
 * Then using the main recurrence => f(ind, cuts_left)
 * start cuts_left = k-1 as k-1 cuts results into k partitions 
 * */

class Solution {
private:
	static constexpr int N = 1e2+10;
	int n;
	int dpChanges[N][N], dp[N][N];

	int minimal_moves(int i, int j, string &s) {
		// base case: when the interval [i..j] becomes invalid
		if(i > j) return 0;

		if(dpChanges[i][j] != -1) return dpChanges[i][j];

		int add = (s[i] != s[j]) ? 1 : 0;
		return dpChanges[i][j] = add + minimal_moves(i+1, j-1, s);
	}

	int f(int ind, int cuts_left, string &s) {
		// base case: if ind is out of bounds and cuts are left 
		if(ind == n) {
            return (cuts_left == 0) ? 0 : 1e8;  
        }

		// base case: all cuts made => return the number of moves to make s[ind...n-1] into a palindrome
		if(cuts_left == 0) return dpChanges[ind][n-1];
		
		if(dp[ind][cuts_left] != -1) return dp[ind][cuts_left];

		// try out all the partitions 
		int res = 1e8;

		for(int j = ind; j < n-cuts_left; j++) {
			// partition is made -> j | j+1
			res = min(res, dpChanges[ind][j] + f(j+1, cuts_left-1, s));
		}

		return dp[ind][cuts_left] = res;
	}

public:
    int palindromePartition(string &s, int k) {
        n = s.length();

        // calculate the min moves to convert every substring into palindrome
        memset(dpChanges, -1, sizeof(dpChanges));

        for(int i = 0; i < n; i++) {
        	for(int j = i; j < n; j++) {
        		int temp = minimal_moves(i, j, s);
        	}
        }

        memset(dp, -1, sizeof(dp));

        // start with k-1 cuts => k-1 cuts lead to k paritions 
        return f(0, k-1, s);
    }
};
