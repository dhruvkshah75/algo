// ==================================================== dp on Subsequences ==============================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int,int>
#define pll pair<ll,ll>

// question link: https://takeuforward.org/plus/dsa/problems/subset-sum-equals-to-target

/* NOTE:
   This is dp on subsequences / Subsets 
   Subsequence => contigous or non contigous elements of the array => must appear in the order in which they appear in the array 

   Q: Given an array arr of n integers and an integer target, determine if there is a subset of the given array with a sum equal to the given target.
   Brute force => generate all subsequences and then check 

   We can use recursion and then check for subset with target sum and with some optimisation 

   Recurrence 
   1. express everything in indexes or states => i, target sum 
      NOTE: For subsequences => states are (index, target)
   2. Explore possibilities of that index => i.e. either it is a part of the subsequence or not 
   3. return true or false depending on whether the subset sum equals target 


   The recurrence f(n - 1, target) means till the n-1 th index does this contain a subset with target sum 

    Using the Top Down Approach from index n - 1 to 0 
    f(0, target) => till the 0th index can i achieve the target => here we can 

    to explore all the paths we either select this element in our subset or not 
    => call for the previous element with target - arr[x] (choosing it) OR target (means not choosing this index) 

    This is 0/1 KnapSack => we either take or not_take

    In the recursion tree of this problem we get that it contains overlapping subproblems so we can use memoization using dp 
*/

// ================================================================================================================================================
//                                                     Top Down Approach (Memoization) dp        
// ================================================================================================================================================

class Solution {
private:    
    const static int N = 5e3 + 1;
    
    int dp[101][N];

    bool f(int x, int target, vector<int> &arr) {
        // target already achieved => base case for target  
        if(target == 0) return true;

        // last index reached => base case for index of elements 
        if(x == 0) return (target == arr[0]);

        // memoization step => dp optimisation 
        if(dp[x][target] != -1) 
            return (dp[x][target] == 1) ? true : false;

        // explore the possibilities for this index => 0/1 
        bool not_take = f(x - 1, target, arr);
        bool take = false;
        // we can only choose (1) this index if target - arr[x] is non negative 
        if(target >= arr[x]) {
            take = f(x - 1, target - arr[x], arr);
        }

        dp[x][target] = ((take || not_take) ? 1 : 0);
        return take || not_take;
    }

public:
    bool isSubsetSum(vector<int> &arr, int target) {
        int n = arr.size();

        memset(dp, -1, sizeof(dp));

        return f(n - 1, target, arr);
    }
};



// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================














/* 
    =========================================================================================================================================================
    =========================================================================================================================================================
    =========================================================================================================================================================
    =========================================================================================================================================================
    =========================================================================================================================================================

        Anathor variant of the question => subset sum equals target 

        question link: https://leetcode.com/problems/partition-equal-subset-sum/description/

        Here the target sum changes everything else remains the same 
        Similar to subset sum equals target => here the one we take goes into the subset 1 and the one left goes into the subset 2 
        same concept of take and not_take
   
        We only keep index and target sum (sum of subset 1) 
        target that we want is target = total / 2 => for two subsets to have same sum they must add up to get the same sum 

    =========================================================================================================================================================
    //                                                Top Down Approach (Memoization) dp 
    =========================================================================================================================================================
*/

#define all(x) x.begin(), x.end()

class Solution {
private: 
    int total;
    const static int N = 2e4 + 1;

    int dp[201][N];

    // now the question is the same as target 

    bool f(int x, int target, vector<int> &nums) {
        // target reached 
        if(target == 0) return true;

        // last index reached => base case for the index 
        if(x == 0) return (target == nums[0]);

        if(dp[x][target] != -1) 
            return (dp[x][target] == 1) ? true : false;

        // 0/1 => take or not take this element to be a part of the subset
        bool not_take = f(x - 1, target, nums);

        bool take = false;
        if(target >= nums[x]) take = f(x - 1, target - nums[x], nums);

        dp[x][target] = ((take || not_take) ? 1 : 0);
        return take || not_take;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        this->total = accumulate(all(nums), 0);

        memset(dp, -1, sizeof(dp));

        // Find a subset with target sum that we want is target = total / 2 => total must be div by 2 
        if(total & 1) return false;

        int target = total / 2;

        return f(n - 1, target, nums);
    }
};