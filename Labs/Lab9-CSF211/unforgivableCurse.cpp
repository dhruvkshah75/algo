#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1800/E1 and https://codeforces.com/contest/1800/problem/E2
// IMPORTANT QUESTION 

/*
    Important Note:
    This question involves swapping positions 
    So it does not mean that two characters can be be replaced with one anathor any where 
    The correct interpretation would be that what places can be reached from i 
    that would be i to i+3, i+4 and then i+3 to i+6, i+7 so on
    These connections of what spots are reachable from i is done by DSU efficiently 

    Then for s1 to be converted to s2, the components in dsu must have the same characters 
*/

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

void solve(int n, int k, string &s1, string &s2) {
    // we simply connect which letter can be replaced by what and make dsu connections 

    // dsu connections should be indexes => as we are doing replacements => this does not allow use transitive properties 
    DSU d(n);

    // dsu gives connections => meaning which spot is changable with what 

    for(int i = 0; i < n; i++) {
        if(i+k < n) 
            d.unite(i, i+k);
        
        if(i+k+1 < n) 
            d.unite(i, i+k+1);   
    }

    // now make a map storing what characters can be rearranged using dsu connections
    unordered_map<int,vector<int>> comp1, comp2;
    // group the characters by components 
    for(int i = 0; i < n; i++) {
        comp1[d.find(i)].push_back(s1[i] - 'a');
        comp2[d.find(i)].push_back(s2[i] - 'a');
    }

    // eg => componen1 contains changable indexes => {1, 4, 5} => s1 has {a, e, c} at these spots then s2 must have these same characters in any spot 
    // i connects to i+3, i+4, then i+3 connects to something and so on 

    for(auto &[root, v1]: comp1) {
        auto &v2 = comp2[root];

        int freq[26] = {};
        // increase the frequencies for chars in v1 and decrese them v2 if all the elements are 0 then okay 
        for(int val: v1) 
            freq[val]++;
        
        for(int val: v2) 
            freq[val]--;
        
        for(int cnt: freq) 
            if(cnt != 0) {
                no;
                return;
            }
    }

    yes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        string s1, s2;
        cin >> s1 >> s2;

        solve(n, k, s1, s2);
    }
}