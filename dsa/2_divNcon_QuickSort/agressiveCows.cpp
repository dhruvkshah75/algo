#include<bits/stdc++.h>
using namespace std;

// question link: https://www.geeksforgeeks.org/problems/aggressive-cows/1

/*
    Algorithm: We use a predicate function such that can we place k agg cows at a min distance of dist 
    to find the max distance we find the Last T occurence in the result of the predicate function: TTTTTTTTFFFFFFF
                                                                                                          | 
    Advanced Binary Search: Aggressive Cows SPOJ                                                                                                      
*/

class Solution {
public:
    // this bool predicate function will return TTTTTTTFFFFFF, so we find the last occurence of the T
    bool placeCows(vector<int> &stalls, int k, int dist) {
        // returns true or false if we can place k cows each at a distance of dist
        int ctr = 1;
        int idxPrevCow = 0;
        for(int i=1; i<stalls.size(); i++) {
            if(stalls[i] - stalls[idxPrevCow] >= dist) {
                idxPrevCow = i;
                ctr++;
            }
            if(ctr >= k) return true;
        }

        return false;
    }

    int aggCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int l = 0, r = stalls.back() - stalls.front();  
        int ans = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(placeCows(stalls, k, mid)) {
                ans = mid;    
                l = mid + 1;
            } 
            else r = mid - 1;
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> stalls(n);

        for(int i=0; i<n; i++) {
            cin >> stalls[i];
        }

        Solution s = Solution();

        cout << s.aggCows(stalls, k) << endl;
    }

}