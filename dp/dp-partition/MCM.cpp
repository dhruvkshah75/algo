// ===================================================== partition dp ================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


/* Partition dp is used when we are asked to solve the question in a prticular orrder or way 
   => each way results in a different answer 
   eg. (1 + 2 + 3) * (5) or (1 + 2) + (3 * 5) => both ways gives different results 

   we have i => starting point and j => ending point and we use k to define partitions 
   

   Matrix Chain Multiplication (MCM):
   
   Suppose we multiply two matrices => M1 (10 * 30) and M2 (30 * 5) =>  operations needed is 10 * 30 * 5
   The resultant matrix will be Mr (10 * 5) 

   eg. A * B * C => to be done in a way with minimum number of operations 
   A => 10 * 30, B = 30 * 5 and C = 5 * 60 
   
   (A * B) * C => operations => 10 * 30 * 5 for A * B => now A * B = R (10 * 5) => R * C => 10 * 5 * 60
   Total operations = 10 * 30 * 5 + 10 * 5 * 60 = 4500

   A * (B * C) => operations = 30 * 5 * 60 + 30 * 60 * 10 = 27000

   2nd way is much more expensive => for dealing with this problem we use partition dp and this problem 
   is called matric chain multiplication 


   Question on MCM: 
   Given: Array => arr[] = {10, 20, 30, 40, 50} => N = 5 => this array gives the dimensions of the N-1 matrices 
   Dimension of a matrix would be (arr[i] * arr[i + 1])
*/


/* Partition DP Rules 
   1. start with the entire block or the entire array => start breaking the problem into smaller problems and then move ahead 
      i and j are used as pointers to denote the start and the end index of each broken down block 
      eg. (A * B) * (C * D)
           i   j     i   j 
    The block is always represented by starting index i and ending index j => f(i, j)

   2. Try all partitions => run a loop to try all partitions => similar to explore all paths 
   3. return the 2 best partitions 

   arr = {10, 20, 30, 40, 50} 
              A   B   C   D
    Each matrix is arr[i-1] * arr[i]
    i = 1 and j = 4 (i and j are the starting and the ending indices of the blocks) 

    Solution: (Writing the recurrence)

    1. step to write the recurrence => start from the entire block 
    f(i, j) = min number of operations to multiply matrix 1 to matrix 4 
    So start from f(1, 4)
    In every move we shrink the current block into partitions making it smaller and smaller 

    Base Case: (i == j) return 0 => if i and j are the same matrix then no of operations to multiply is 0

    2. try out all partitions => similar to trying out all the paths 
    run a loop with k = i -> j - 1 => the new partitions will be f(i, k) and f(k + 1, j) => k + 1 <= j
    to multiply f(i, k) ad f(k+1, j) => nums[i-1] * nums[k] * nums[j]

*/

// ========================================================================================================================
//                                  Memoization - Top Down Approach dp 
// ========================================================================================================================

// Recursion -> Memoization Time Complexity = O(N ^ 3) => this can cause TLE due to extra space of Auxiliary stack space
// Space Complexity = O(N * N) + O(N)  

class RecursiveSolution {
private:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        // base cases: when i and j point to the same matrix 
        if(i == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // try out all the partitions => k is intermediate index
        int res = 1e8;

        for(int k = i; k < j; k++) {
            // op is the number of steps needed to multiply with k as the partition
            int op =  nums[i-1] * nums[k] * nums[j] + f(i, k, nums, dp) + f(k+1, j, nums, dp);
            res = min(res, op);
        }

        return dp[i][j] = res;
    }

public:
	int matrixMultiplication(vector<int>& nums){
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        // the starting block is 1st matrix to the last matrix => f(1, n-1)
        return f(1, n-1, nums, dp);
    }
};


// Tabulation solution is very important for this question 
 
// =========================================================================================================================
//                                Tabulation - Bottom Up approach dp
// =========================================================================================================================

class Solution {
private:
    /*
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        // base cases: when i and j point to the same matrix 
        if(i == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // try out all the partitions => k is intermediate index
        int res = 1e8;

        for(int k = i; k < j; k++) {
            // op is the number of steps needed to multiply with k as the partition
            int op =  nums[i-1] * nums[k] * nums[j] + f(i, k, nums, dp) + f(k+1, j, nums, dp);
            res = min(res, op);
        }

        return dp[i][j] = res;
    }
    */

public: 
    int matrixMultiplication(vector<int>& nums){
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        // dp[i][j] = min number of operations to multiply Ai, Ai+1, ...., Aj

        // base case: i == j => dp = 0
        for(int i = 0; i < n; i++) 
            dp[i][i] = 0;

        // in memoization i goes from 1 to N => here it must go from N to 1 
        // in memo j went from N to 1 so in tabulation j must go in opposite direction => 1 to N 
        // and since j is always to the right of i then j = i + 1 

        for(int i = n - 1; i >= 1; i--) {
            for(int j = i + 1; j < n; j++) {
                // try out all the partitions 
                int res = 1e8;

                for(int k = i; k < j; k++) {
                    // partition will f(i, k) and f(k+1, j)
                    int op = nums[i-1] * nums[k] * nums[j] + dp[i][k] + dp[k+1][j];
                    res = min(op, res);
                }

                dp[i][j] = res;
            }
        }

        // the answer will be the min number of operations from A1,.....,An-1 = dp[1][n-1]
        return dp[1][n-1];
    }
};
