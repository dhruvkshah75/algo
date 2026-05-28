// ==================================================== dp on Subsequences ==============================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int,int>
#define pll pair<ll,ll>

// question link: https://takeuforward.org/plus/dsa/problems/count-subsets-with-sum-k

/*
    Count subsets with sum equal to K 
    Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K. Return the result modulo (1e9 + 7).
    Constraints

    1 <= n <= 100
    1 <= arr[i] <= 1e3
    1 <= K <= 1e3

    If there are negative integers then we can use vector<map<int,int>> dp to store the negative sums as well 

    The code below gives wrong answer if the array contains 0 
    So how to fix this ?
    Calculate the cnt0 => and then figure out the number of ways to represent 0
    eg {0, 0, 1} => cnt0 = 2 => can be reprsented in 4 ways => {0}, {0}, {0, 0}, {}  => 2 ^ cnt0
    so the final answer will be dp[n - 1][target] * pow(2, cnt0)

    How to fix this in recurrence itself 
    (alter the base cases)
    issue was caused by if(sum == 0) return 1
    
*/

// fix => changes in the base case when arr[i] = 0 is allowed 
int f(int x, int sum, vector<int> &arr) {
    if(x == 0) {
        // we can take and not take the arr[0] => both cases are valid 
        if(sum == 0 && arr[0]) return 2;

        // 1 way is to not take the arr[0] != 0 or the sum = arr[0] then take the element 
        if(sum == 0 || sum == arr[0]) return 1;

        // rest all cases are not valid 
        return 0;
    }
}


// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class RecursiveSolution{
private:
    const int mod = 1e9 + 7;
    const static int N = 1e3 + 1;

    int dp[101][N];

    int f(int x, int sum, vector<int> &arr) {
        // base case => when target is reached => found a subset
        if(sum == 0) return 1;

        // last index reached 
        if(x == 0) return (arr[0] == sum) ? 1 : 0;

        if(dp[x][sum] != -1)
            return dp[x][sum];

        ll not_take = f(x - 1, sum, arr);
        ll take = 0;
        if(sum >= arr[x]) take = f(x - 1, sum - arr[x], arr);

        return dp[x][sum] = (take + not_take) % mod;
    }

public:
	int perfectSum(vector<int> &arr, int K){
        int n = arr.size();

        memset(dp, -1, sizeof(dp));

        return f(n - 1, K, arr);
	}
};


// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

/* From Memoization => tabulation 
   1. Start from the base cases 
   2. form the nested loops from the states of the recurrence in memoization 
   3. Copy the recurrence relation from the memoization and convert to dp instead of recursive calls 
*/

#define all(x) x.begin(), x.end()
typedef long long ll;

class Solution {
private:
    const int mod = 1e9 + 7;
public: 
    int perfectSum(vector<int> &arr, int K) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        // starting with the base cases (index = 0 and sum = 0)
        if(arr[0] <= K) dp[0][arr[0]] = 1;

        for(int i = 0; i < n; i++) 
            dp[i][0] = 1;

        // loops for the states 
        for(int i = 1; i < n; i++) {
            for(int sum = 1; sum <= K; sum++) {
                ll not_take = dp[i - 1][sum];
                ll take = 0;

                if(sum >= arr[i]) take = dp[i - 1][sum - arr[i]];

                dp[i][sum] = (take + not_take) % mod;
            }
        }

        // dp[n - 1][0..j..K] contains all number of all subsets with sum = j 
        // final result will be number of subsets with sum = K 
        return dp[n - 1][K];
    }
};


// the above solution can be space optimised to get into dp[0...K] as each calculation depends only the previous indexed dp array 

class spaceOptimisedSolution {
private:
    const int mod = 1e9 + 7;
public: 
    int perfectSum(vector<int> &arr, int K) {
        int n = arr.size();

        // at the start prev denotes the contents of row 0 
        vector<int> prev(K+1, 0), curr(K + 1);

        // starting with the base cases (index = 0 and sum = 0)
        if(arr[0] <= K) prev[arr[0]] = 1;
        
        prev[0] = 1;

        // loops for the states 
        for(int i = 1; i < n; i++) {
            // base case for each row (sum = 0)
            curr[0] = 1; 

            for(int sum = 1; sum <= K; sum++) {
                ll not_take = prev[sum];
                ll take = 0;

                if(sum >= arr[i]) take = prev[sum - arr[i]];

                curr[sum] = (take + not_take) % mod;
            }

            prev = curr;
        }

        // dp[n - 1][0..j..K] contains all number of all subsets with sum = j 
        // final result will be number of subsets with sum = K => prev denotes the last row n - 1
        return prev[K];
    }
};


// ============================================ Count Partitions with given Differences =======================================================================================

/* Anathor question based on this Count Partitions with given difference  
   This question can be solved using the continuation of the above question (count subsets with sum K)

   Question: 
   Given an array arr of n integers and an integer diff, count the number of ways to partition the array into two subsets S1 and S2 such that: ∣S1−S2∣ = diff and S1 ≥ S2
   Where |S1| and |S2| are sum of Subsets S1 and S2 respectively.
   Return the result modulo 109 + 7.


   Using the previous question's tabulation approach note that the dp[n - 1][0....j....K] contains the numbers of subsets with sum = j
   We have 
   S1 - S2 = Diff and S1 + S2 = total 
   basically find the numbers of subsets with sum = (total + Diff) / 2
*/

class Solution {
private:
    const int mod = 1e9 + 7;

public: 
    int countPartitions(int diff, vector<int>& arr) {
        int n = arr.size();

        int total = accumulate(all(arr), 0);

        if((total + diff) & 1) 
            return 0;

        int target = (total + diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // starting with the base cases (index = 0 and sum = 0)
        if(arr[0] <= target) dp[0][arr[0]] = 1;

        for(int i = 0; i < n; i++) 
            dp[i][0] = 1;

        // loops for the states 
        for(int i = 1; i < n; i++) {
            for(int sum = 1; sum <= target; sum++) {
                ll not_take = dp[i - 1][sum];
                ll take = 0;

                if(sum >= arr[i]) take = dp[i - 1][sum - arr[i]];

                dp[i][sum] = (take + not_take) % mod;
            }
        }

        // using the same logic for count subsets with sum K 
        // we se want no of subsets with diff of sums S1 - S2 = D 
        // We know that S1 + S2 = total and S1 - S2 = D => S1 = (total + D) / 2

        // dp[n - 1] contains number of subsets for each target ranging from 0 to total  
        return dp[n - 1][target];
    }
};