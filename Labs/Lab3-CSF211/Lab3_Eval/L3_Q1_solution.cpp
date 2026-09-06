#include <bits/stdc++.h>
using namespace std;

int solve(int n, std::vector<int> &difficulty, std::vector<int> &profit, int m, std::vector<int> &worker) {
    // n is the no of jobs = size of profits and // m is the no of workers 
    // binary search on the profit 

    vector<pair<int,int>> jobs(n);
    for(int i=0; i<n; i++) {
        jobs[i] = {difficulty[i], profit[i]};
    }

    sort(jobs.begin(), jobs.end());

    // make an array which stores the max profit till that index (inclusive)
    vector<int> max_profit(n+1);
    max_profit[0] = jobs[0].second;
    for(int i=1; i<n; i++) {
        max_profit[i] = max(jobs[i].second, max_profit[i-1]);   
    }
    max_profit[n] = max_profit[n-1];


    int ans = 0;
    // find what are the jobs that a worker can do using upper bound 
    for(int i=0; i<m; i++) {
        // implement the upper bound 
        int l = 0, r = n - 1;
        int idx = -1;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if(jobs[mid].first > worker[i]) r = mid;
            else l = mid;
        }
        if(jobs[l].first > worker[i]) idx = l-1;
        else if(jobs[r].first > worker[i]) idx = r-1;
        else if(r == n - 1) idx = n;   // when all the jobs can be included 

        // no job can be done by the worker m
        if(idx < 0) 
            continue;
        
        // now we have to figure out which job gives most profit between 0 and idx (inclusive)
        ans += max_profit[idx];
    }

    return ans;
}
