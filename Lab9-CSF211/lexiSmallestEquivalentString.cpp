#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/

// similar to Love Rescue Codeforces 
// Here we make some alterations to the existing DSU data structure definition 

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // similar to codeforces DSU question Love Rescue 
        // mark a = 0 to z = 26 
        DSU d(27);
        // We make small iterations in the ultimate parent of dsu logic where we keep the ultimate parent as the smallest node

        // populate the DSU graph using s1 and s2
        for(int i = 0; i < s1.length(); i++) {
            int c1 = (int)(s1[i] - 'a'), c2 = (int)(s2[i] - 'a');
            // connect the edges between c1 to c2 to make edges 
            d.unite(c1, c2);
        }

        string result = "";

        for(int i = 0; i < baseStr.length(); i++) {
            int c = (int)(baseStr[i] - 'a');

            result += (char)(d.find(c) + 'a'); 
        }

        return result;
    }

private:
    // in dsu make the the ultimate parent as the smallest lexi char
    struct DSU {
        vector<int> parent;

        DSU(int n) : parent(n) {
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
            // always keep the smallest as the ultimate parent
            if(pu > pv) swap(pu, pv);
            parent[pv] = pu;
        }
    };
};