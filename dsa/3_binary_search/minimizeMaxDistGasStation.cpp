#include<bits/stdc++.h>
using namespace std;

// question link: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
// DSA Sheet HARD Question

class Solution {
  public:
    // predicate function returns FFFFFFTTTT
    bool isDist(vector<int>& stations, int k, double dist) {
        // is the max distance between all the stations <= dist after placing K stations
        int ctr = 0;
        int n = stations.size();
        for (int i = 1; i < n; i++) {
            // Find how many stations are needed to plug this gap
            double gap = stations[i] - stations[i-1];
            ctr += (int)(gap / dist);
        }
        return (ctr <= k);
    }

    double minMaxDist(vector<int> &stations, int K) {
        // apply binary search on the answer i.e. distance 
        int n = stations.size();

        double l = 0, r = stations[n-1] - stations[0]; // Absolute max possible gap
        while(r - l > 1e-6) { 
            double mid = l + (r - l) / 2;
            if (isDist(stations, K, mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stations(n);
    for(int i=0; i<n; i++)
        cin >> stations[i];

    Solution s = Solution();
    cout << s.minMaxDist(stations, k) << endl;
}