// =============================================== Longest Increasing Subsequence ===============================================================

#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/longest-increasing-subsequence/description/

// =============================================================================================================================================
//                                                  Top Down Approach Memoization dp
// =============================================================================================================================================

/* Explaination: 
   lis => longest increasing subsequence 
   f(ind) => returns the length of lis till the index ind 
   We look at all the smaller elements in the prefix [0...ind-1]
*/

class Solution {
private:
    int f(int ind, vector<int> &nums, vector<int> &dp) {
        // base case is implicit: => if loop doesnt run then 1 iis returned 

        if(dp[ind] != -1) return dp[ind];

        // try all the smaller element than nums[ind] in nums[0...ind]
        // if nothing found then the current element is part of a standalone LIS of length 1 
        int maxi = 1;

        for(int i = 0; i < ind; i++) {
            if(nums[i] < nums[ind]) {
                maxi = max(maxi, 1 + f(i, nums, dp));
            }
        }

        return dp[ind] = maxi;
    }

public: 
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();

        vector<int> dp(n, -1);
        // dp[i] = length of lis till the ith element 

        // check the length of lis for all indexes 
        int longest = 0;

        for(int i = 0; i < n; i++) 
            longest = max(longest, f(i, nums, dp));

        return longest;
    }
};
// Space Complexity = O(N), Time Complexity = O(N^2)


// Anathor approach to solve this question using memoization is using the take not take concept 
/* Explaination: 
   Reccurence => f(ind, prev_ind) ==> this denotes the prev index of the element in that sequence 
   start by calling f(0, -1) => starting from the 0th index and no element previous to it  

   f(ind, prev_ind) => length of lis starting from ind whose prev element is prev_ind 

   Make the array indexing 1 based so that we can deal with the case of no prev element
*/

class RecursiveSolution2 {
private:
    int f(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp) {
        // base cases: array proccessed completely
        if(ind > (int)nums.size()) return 0;

        if(dp[ind][prev_ind] != -1) return dp[ind][prev_ind];

        // explore the case of take and non_take
        // case 1: dont take the current element in lis
        int len = f(ind+1, prev_ind, nums, dp);

        // case 2: take the element in the lis 
        if(prev_ind == 0 || nums[prev_ind-1] < nums[ind-1]) 
            len = max(len, 1 + f(ind+1, ind, nums, dp));

        return dp[ind][prev_ind] = len;
    }

public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        // array => 1 based indexing 
        // f => recurrence returns the max length of the lis starting from the ind whose prev element was prev_ind 
        return f(1, 0, nums, dp);
    }
};




// ===========================================================================================================================================
//                                              Bottom Up Approach Tabulation dp
// ===========================================================================================================================================

// Tabulation of LIS is pretty much basic and easy to understand 

#define all(x) x.begin(), x.end()

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        // dp[i] = length of the lis ending with the ith element
        // defaul value = 1 => every single element is itself a lis of length = 1

        for(int ind = 0; ind < n; ind++) {
            // try finding smaller elemens in prefix nums[0..ind-1]
            int maxi = 1;

            for(int i = 0; i < ind; i++) {
                if(nums[i] < nums[ind]) maxi = max(maxi, 1 + dp[i]);
            }

            dp[ind] = maxi;
        }

        // return the max length of lis ending at any index 
        return *max_element(all(dp));
    }
};
// Space Complexity = O(N), Time Complexity = O(N^2)

// =========================================== Printing the LIS Sequence ===========================================================================

// for printing the lis => O(N^2) time complexity is required => optimal solution of O(N * Log(N)) just gives the length of lis 

#define all(x) x.begin(), x.end()

class Solution {
public: 
    vector<int> lis(vector<int> &nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        // dp[i] = length of lis ending with ith element 
        
        vector<int> prev(n, -1);
        // using the prev element => reconstruct the lis 

        for(int ind = 0; ind < n; ind++) {
            // try finding the smaller elements in the prefix [0...ind-1]
            int maxi = 1;

            for(int i = 0; i < ind; i++) {
                if(nums[i] < nums[ind]) {
                    // maxi = max(maxi, 1 + dp[i])
                    if(1 + dp[i] > maxi) {
                        maxi = 1 + dp[i];
                        prev[ind] = i;
                    }
                }
            }
            dp[ind] = maxi;
        }

        // now get the maximum length of lis from the dp and reconstruct the lis 
        int ind = 0, longest = 1;

        for(int i = 0; i < n; i++) {
            if(longest < dp[i]) {
                longest = dp[i];
                ind = i;
            }
        }

        // now retrace from the ind to get the lis 
        vector<int> res;

        while(ind != -1) {
            res.push_back(nums[ind]);
            ind = prev[ind];
        }

        reverse(all(res));

        return res;
    }
};


// There exists a better solution than O(N^2) 
// Optimal Time Complexity = O(N * Log(N)) using Binary search 

// =====================================================================================================================================================
//                              Optimised solution using Binary Search (Time Complexity = O(N * Log(N)))
// =====================================================================================================================================================

/* Explaination: => Very Important - Non Intuitive Solution 
   Maintain a array of increasing sequence and keep finding the the lower bound for placing the
   newly found number in the array and then overwrite the new number there 
   The array formed in the end is not the subsequence but its size is the final length of longest lis 
   
   Example: 
   nums => [1, 7, 8, 4, 5, 6, -1, 9]
   ind = 0 => temp = {1} 
   ind = 1 => temp = {1, 7}
   ind = 2 => temp = {1, 7, 8}
   ind = 3 => temp = {1, 4, 8}  => overwrites 7 
   ind = 4 => temp = {1, 4, 5}  => overwrites 8
   ind = 5 => temp = {1, 4, 5, 6}
   ind = 6 => temp = {-1, 4, 5, 6} => overwrites 1
   ind = 7 => temp = {-1, 4, 5, 6, 9} 
   length = 5 => but the temp array does not contain the correct lis sequence 
   */

#define all(x) x.begin(), x.end()

class Solution {
public: 
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();

        // using binary search we get O(N * Log(N))

        vector<int> temp;

        for(int ind = 0; ind < n; ind++) {
            auto it = lower_bound(all(temp), nums[ind]);
            int index = distance(temp.begin(), it);

            int sz = temp.size();
            
            // if lower bound does not exist then add the number in the end 
            // otherwise overwrite the existing number in the temp array
            if(index == sz) temp.push_back(nums[ind]);
            else temp[index] = nums[ind];
        }

        // temp => this does not ressemble the lis but the length of the temp array is the length of lis 
        
        int res = temp.size();
        return res;
    }
};
// Time Complexity = O(N * Log(N)), Space Complexity = O(N)