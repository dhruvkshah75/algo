#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/smallest-string-with-swaps/description/

/*
    We use DSU to connect those positions which can be swapped in some way 
    And then store all the characters in the map and then sort it in reverse and then start placing them 
    into the result string 
*/

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // create a DSU to store the positions that are interchangeable 
        int n = s.size(), m = pairs.size();

        DSU d(n);

        for(int j = 0; j < m; j++) {
            int u = pairs[j][0], v = pairs[j][1];
            d.unite(u, v);
        } 
           
        unordered_map<int,vector<char>> mp;
        // parent = key -> value = all the chars that can we swapped 

        for(int i = 0; i < n; i++) {
            int p = d.find(i);
            mp[p].push_back(s[i]);
        }

        for(auto &[parent, v]: mp) {
            sort(v.rbegin(), v.rend());
        }

        // now we fill the positions to get the lexicographically smallest 
        string result = "";

        for(int i = 0; i < n; i++) {
            int pi = d.find(i);
            result += mp[pi].back();
            mp[pi].pop_back();
        }

        return result;
    }

private: 
    struct DSU {
        vector<int> parent, size;

        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int u) {
            if(parent[u] != u) 
                parent[u] = find(parent[u]);
            return parent[u];
        }

        void unite(int u, int v) {
            int pu = find(u), pv = find(v);
            if(pu == pv) return;

            if(size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    };
};