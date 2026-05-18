#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-space-wasted-from-packaging/description/

// HARD LEETCODE 

// Question Algorithm: It is pretty staightforward 
/*
    We have to find the supplier with whom the wasted space is minimum 
    What will the wasted space ?
        Total Waste = Sum(BoxSize * No of packages put in that box Size) - Sum(Packages size)
        Sum of Packages is constant and 
        we calculate the the no of packages put in that box size using upper bound (Binary search)
*/

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size();
        sort(packages.begin(), packages.end());

        long long total = accumulate(packages.begin(), packages.end(), 0LL);
        long long ans = LLONG_MAX;

        for (vector<int> &supplier : boxes) {
            sort(supplier.begin(), supplier.end());

            // Check if the largest box of this supplier can fit the largest package
            if (supplier.back() < packages.back()) 
                continue;

            long long ctr = 0;
            int lastIdx = 0;

            for (int box : supplier) {
                // Find how many packages fit in the current box
                // upper_bound returns iterator to first element > box
                auto it = upper_bound(packages.begin() + lastIdx, packages.end(), box);
                int currentIdx = distance(packages.begin(), it);

                if (currentIdx > lastIdx) {
                    long long numPackages = currentIdx - lastIdx;
                    ctr += numPackages * 1LL * box;
                    lastIdx = currentIdx;
                }
                // all the packages were fitted in the boxes   
                if (lastIdx == n) break; 
            }
            
            ans = min(ans, ctr);
        }
        // no suplier can fit the packages 
        if (ans == LLONG_MAX) return -1;
        
        int mod = 1e9 + 7;
        // Final Wasted Space = (Sum of box sizes used) - (Sum of package sizes)
        return (ans - total) % mod;
    }
};