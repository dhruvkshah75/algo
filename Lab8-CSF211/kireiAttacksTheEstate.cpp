#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/2114/E
// dp on dfs => bottom up approach 

void dfs(vector<vector<int>> &adjL, vector<int>&A, vector<bool> &visited, 
            vector<pair<ll,ll>> &dp, int node, int parent) {
    
    // Recurrence Relation 
    // dpMax(node) = max(An, An - dpMin(p)) & dpMin(node) = min(An, An - dpMax(p)) => p is the parent of node
    visited[node] = true;

    if(parent == -1) {
        dp[node] = {A[node], A[node]};
    }
    else {
        auto [maxP, minP] = dp[parent];
        dp[node].first = max(A[node] * 1LL, A[node] - minP);
        dp[node].second = min(A[node] * 1LL, A[node] - maxP);
    }

    // call dfs on the neighbours 
    for(int nbg: adjL[node]) {
        if(!visited[nbg]) {
            dfs(adjL, A, visited, dp, nbg, node);
        }
    }
}

void solve(vector<pair<int,int>> &edges, vector<int> &A, int n) {
    // dp[i] = {max, min} => max and min alternating sum of path from 1 to ith node 
    vector<pair<ll,ll>> dp(n+1, {-1,-1});

    // Recuurence realtions 
    // max Sn = an - min Sp (p is the parent of n) and min Sn = an - max Sp
    vector<bool> visited(n+1, false);

    vector<vector<int>> adjL(n+1);

    for(int i = 0; i+1 < n; i++) {
        auto [a, b] = edges[i];
        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }

    // start with dfs on the root node (1)
    dfs(adjL, A, visited, dp, 1, -1);

    for(int i = 1; i <= n; i++)
        cout << dp[i].first << " ";
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> nodes(n+1);

        for(int i = 1; i <= n; i++) 
            cin >> nodes[i];

        // tree has only n-1 edges 
        vector<pair<int,int>> edges(n-1);

        for(int i = 0; i + 1 < n; i++) {
            cin >> edges[i].first >> edges[i].second;
        }

        solve(edges, nodes, n);
    }
}