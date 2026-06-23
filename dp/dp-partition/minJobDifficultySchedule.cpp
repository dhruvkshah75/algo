// ================================================================== front partition dp ====================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/

// ===================================================== Important Question ===========================================================

/* Explanation: front partition dp => we create d partitions 
   but the partition happens from the front as to do the ith task => all previous tasks must be done 
   recurrence => f(i, j) => i = index for the job and j = index for the day 
   0 <= j < d => 0 based indexing for days 
   Each job must be done as we traverse through the jobs vector (just decide on which day)
   Only base case when the job scheduling is valid => all jobs are completeled and all days exhausted  
   difficulty of that day => max difficulty of the jobs done on that day
*/

class Solution {
private: 
    static constexpr int N = 300;
    int dp[N][10];

    int f(int i, int j, vector<int> &jobs, int n, int d) {
        // base case: all days and all jobs exhausted => valid case 
        if(i == n && j == d) return 0;

        // base case: either got exhausted first => inavlid case 
        if(i == n || j == d) return 1e8;

        if(dp[i][j] != -1) return dp[i][j];

        // allott x jobs in prefix [i...n] on the jth day 
        int mini = 1e9, max_ele = 0;

        for(int k = i; k < n; k++) {
            max_ele = max(max_ele, jobs[k]);
            
            mini = min(mini, max_ele + f(k+1, j+1, jobs, n, d));
        }

        return dp[i][j] = mini;
    }

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        // base case: each day must have at least one job 
        if(n < d) return -1;

        memset(dp, -1, sizeof(dp));

        // starting on the 0th day from the 0th job 
        return f(0, 0, jobDifficulty, n, d);
    }
};