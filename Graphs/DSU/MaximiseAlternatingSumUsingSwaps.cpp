// ============================================= DSU =================================================

#include<bits/stdc++.h> 
using namespace std;

// question link: https://leetcode.com/problems/maximize-alternating-sum-using-swaps/description/

/* Explanation: DSU 
   All swaps are interchangable and any possible config can be achieved so each swappable positions 
   forms a component 
   We must maximize the sum of even indices (put all maximum elements here) and minimize the sum at odd indices 
   Using dsu keep a track of the number of odd indices and even indices in the component

   Time Complexity = O(N*Log(N) + m*alpha(n))

   This question involves modification of the DSU structure to hold extra information 
*/

typedef long long ll;

#define all(x) x.begin(), x.end()
#define pii pair<int,int>

class Solution {
private:
    struct DSU {
        vector<int> parent, size;
        vector<pii> v;

        DSU(int n) : parent(n), size(n, 1), v(n) {
            // v.first = cnt of even indices, v.second = cnt of number of odd indices 
            for(int i = 0; i < n; i++) {
                parent[i] = i;
                if(i & 1) v[i] = {0, 1};
                else v[i] = {1, 0};
            }
        } 

        int find(int u) {
            if(parent[u] != u) parent[u] = find(parent[u]);
            return parent[u];
        }

        void unite(int x, int y) {
            int px = find(x), py = find(y);
            if(px == py) return;

            if(size[py] > size[px]) swap(px, py);
            parent[py] = px;
            size[px] += size[py];
            // update the cnt of even and odd indices 
            v[px].first += v[py].first;
            v[px].second += v[py].second;
        }
    }; 

public:
    ll maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size(), m = swaps.size();

        DSU d(n);
        // nodes are indices of nums => 0..n-1

        for(int j = 0; j < m; j++) {
            d.unite(swaps[j][0], swaps[j][1]);
        }

        // store all the elements in the same component in a map in increasing order 
        unordered_map<int,vector<int>> mp;

        for(int i = 0; i < n; i++) 
            mp[d.find(i)].push_back(nums[i]);

        for(auto &[p, v]: mp) 
            sort(all(v));

        // now final maximised calculation of alternating sum 
        ll res = 0;

        for(auto &[par, vec]: mp) {
            auto [even, odd] = d.v[par];

            // add the ones to be placed at even position (max elements) 
            while(even--) {
                res += vec.back();
                vec.pop_back();
            }

            // subtract the elements at odd positions 
            while(odd--) {
                res -= vec.back();
                vec.pop_back();
            }
        }

        return res;
    }
};