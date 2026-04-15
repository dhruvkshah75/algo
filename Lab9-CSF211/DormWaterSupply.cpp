#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/107/A

void dfs(vector<vector<pair<int,int>>> &adjL, vector<bool> &vis, vector<int> &indeg, vector<int> &outdeg, int &end, int curr, int &maxWater) {
    vis[curr] = true;

    int cnt = 0;
    for(auto [nbg, w]: adjL[curr]) {
        if(vis[nbg]) continue;
        cnt++;
        maxWater = min(maxWater, w);
        dfs(adjL, vis, indeg, outdeg, end, nbg, maxWater);
    } 

    if(cnt == 0) end = curr;
}

void solve(int n, int p, vector<tuple<int,int,int>> &pipes) {
    // max => indegree 1 and outdegree = 1

    vector<int> indegree(n+1, 0), outdegree(n+1, 0);
    vector<vector<pair<int,int>>> adjL(n+1);

    for(auto [u, v, d]: pipes) {
        outdegree[u]++;
        indegree[v]++;
        adjL[u].push_back({v, d});
    }

    vector<bool> vis(n+1, false);

    vector<tuple<int,int,int>> result;

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;

        if(indegree[i] == 0 && outdegree[i] == 1) {
            int start = i;

            int end = -1, maxWater = INT_MAX;

            dfs(adjL, vis, indegree, outdegree, end, start, maxWater);

            result.push_back({start, end, maxWater});
        }
    }

    cout << result.size() << endl;

    for(auto [tank, tap, water]: result) 
        cout << tank << " " << tap << " " << water << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;
    // n houses, p pipes 

    vector<tuple<int,int,int>> pipes(p);

    for(auto &[u, v, d]: pipes) 
        cin >> u >> v >> d;

    solve(n, p, pipes);
}