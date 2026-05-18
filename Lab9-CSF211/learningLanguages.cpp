#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/277/A

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

void solve(int n, int m, vector<vector<int>> &emp) {
    // consider the employees (0 to n-1) as nodes of graph 
    // people are connected if if they know the same language 

    bool any_known = false; // Flag to track if at least one language is known

    unordered_map<int,vector<int>> lang;

    for(int i = 0; i < n; i++) {
        if (!emp[i].empty()) any_known = true;
        for(int j = 0; j < emp[i].size(); j++) {
            // ith employee knows language emp[i][j]
            lang[emp[i][j]].push_back(i);
        }
    }

    // Special Case: Nobody knows anything
    if (!any_known) {
        cout << n << endl;
        return;
    }

    DSU d(n);

    // create the graph where we connect emp i to emp j if they know the same language 
    for(auto &[languageId, empId]: lang) {
        for(int i = 0; i+1 < empId.size(); i++) {
            d.unite(empId[i], empId[i+1]);
            // connect the person i to i+1 as both of them speak the same language 
        }
    }

    // since every employee should be able to talk each other => via middle man is allowed 
    // this is the same as the number of connected components 
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(d.find(i) == i) count++;
    }

    cout << count - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    // n employees (0 to n-1) => m languages (1 to m)

    vector<vector<int>> emp(n);
    // emp[i] = languages known by ith employee 

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        while(k--) {
            int x;
            cin >> x;
            emp[i].push_back(x);
        }
    }

    solve(n, m, emp);

}