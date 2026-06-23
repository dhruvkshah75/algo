// ========================================================== DSU =======================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/

/* Explanation: DSU 
   This question doesnt appear that it involves the use of dsu at all 
   but the biggest clue that we solve the question is using dsu is that 
   if x, y can be swapped and y, z can be swapped then x, y, z can be swapped in such a way that 
   all possible combinations can be achieved 
   so it forms a component which can easily be handled using DSU 

   Now how to get the connections ? 
   sort the array and compare elements at adjacent positions if their diff <= limit then connect them using DSU 
   and do the same thing for all indices => now we have all the positions that are interchangeable now place 
   the smallest value at lowest index to get the lexicographically smallest array */

#define pii pair<int,int>
#define all(x) x.begin(), x.end() 
#define rall(x) x.rbegin(), x.rend()

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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pii> v;

        for(int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        sort(all(v));

        DSU d(n);
        // nodes in the DSU are the indices => 0,1,...n-1

        for(int i = 0; i+1 < n; i++) {
            if(v[i+1].first - v[i].first <= limit) 
                d.unite(v[i].second, v[i+1].second);
        }

        unordered_map<int,vector<int>> mp;

        for(int i = 0; i < n; i++) {
            int p = d.find(i);
            mp[p].push_back(nums[i]);
        }

        // now we must sort all components in decreasing order 
        for(auto &[p, vec]: mp) 
            sort(rall(vec));

        for(int i = 0; i < n; i++) {
            int p = d.find(i);

            nums[i] = mp[p].back();
            mp[p].pop_back();
        }

        return nums;
    }
};