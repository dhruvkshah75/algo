// ======================================================= DSU + Number theory ======================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-connected-components-in-lcm-graph/description

/* Explanation: DSU + Number Theory 
   so here lcm of nums[i] and nums[j] <= threshold for them to be connected 
   So we can just make connections of nums[i] with its multiples and nums[j] with its multiples 
   if their lcm is less than threshold then nums[i] and nums[j] both end up in the same component 
   Then using DSU we get the number of componets wrt to nums (as there will be many virtual nodes)

   Time Complexity = O(N * Log(N)) 
   As traversing to all the multiples of nums[i] takes Log(nums[i]) <= threshold

   Note: nums[i] <= 1e9 so it cant have lcm if nums[i] > threshold so this element is itself a component 
*/
 
#define all(x) x.begin(), x.end()

class Solution {
private:
    struct DSU {
        vector<int> parent, size;

        DSU(int n) : parent(n), size(n, 1) {
            iota(all(parent), 0);
        }

        int find(int u) {
            if(parent[u] != u) parent[u] = find(parent[u]);
            return parent[u];
        }

        void unite(int u, int v) {
            int pu = find(u), pv = find(v);
            if(pu == pv) return;

            if(size[pv] > size[pu]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    };

public:
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();

        // we only consider nums[i] or multiples <= threshold
        DSU d(threshold+1);

        for(int num: nums) {
            if(num > threshold) continue;

            for(int j = num; j <= threshold; j += num) {
                d.unite(num, j);
            }
        }
        // O(N*Log(N))

        // all those elements such that lcm(nums[i], nums[j]) <= threshold now belong to the same component

        int res = 0;
        unordered_set<int> seen;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > threshold) { 
                res++; 
                continue; 
            }

            int p = d.find(nums[i]);
            if(!seen.count(p)) {
                res++;
                seen.insert(p);
            }
        } 

        return res;
    }
};