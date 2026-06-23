#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

/* Explanation: dp with states (dp on subsequences) 
   No overlapping jobs can be done at the same time => we use dp as a choice now affects the future 
   greedy doesnt work here => taking a job with less profit might open up a job with more profit later (no uniformity)

   At each index we have 2 choices => 1. take the job and get the curr profit 2. skip this job and take the next one 
   taking the job we cant do any more jobs in the time [start_time, end_time] so we use binary search to get the 
   index of the next available job 

   recurrence => f(ind) = max profit earned by doing jobs in the prefix[0...ind]
   This question is a classical example of (take, not_take) dp on subsequences
*/

class Solution {
private: 
    struct Job {
        int start_time, end_time, profit;
        
        Job(int st, int et, int p) : start_time(st), end_time(et), profit(p) {}
    };

    static constexpr int N = 5e4+1;
    int dp[N];

    // lower bound gives >= x (index) and first occurrence of x 
    int lb(int x, vector<Job> &v) {

        int low = 0, high = v.size() - 1;
        // if no lb then return n (v.end())
        int res = v.size();

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(x <= v[mid].start_time) {
                high = mid-1;
                res = mid;
            }
            else low = mid + 1;
        }
        return res;
    }

    int f(int ind, vector<Job> &v) {
        // base case: all jobs explored 
        if(ind == (int)v.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        // case 1: skip the current job 
        int not_take = f(ind+1, v);

        // case 2: take the current job and move to the next one 
        // we can pick up a new job whose start time >= curr end_time 
        int nxt = lb(v[ind].end_time, v);
        int take = v[ind].profit + f(nxt, v);

        return dp[ind] = max(take, not_take);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        // sort the jobs on basis of their start_time so binary search can be applied 
        vector<Job> v;

        for(int i = 0; i < n; i++) {
            v.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(v.begin(), v.end(), [&](const Job &a, const Job &b){
            return a.start_time < b.start_time;
        });

        memset(dp, -1, sizeof(dp));

        // start from the 0th job and try all possible options
        return f(0, v);
    }
};
