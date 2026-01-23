#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;
    // sort the intervals in ascending order
    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals[0]);

    for(int i=1; i<n; i++) {
        int l = ans.size()-1;
        // ans[l] this is the one with which we compare the intervals[i] 
        if(intervals[i][0] >= ans[l][0] && intervals[i][0] <= ans[l][1]) {
            ans[l] = {ans[l][0], max(ans[l][1], intervals[i][1])};
        }
        else {
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}
