#include <bits/stdc++.h>
using namespace std;

// ================================== Topological Sorting =======================================

std::vector<int> solve(int n, int m, const std::vector<std::pair<int,int>> &c) {
    // we must find the unique permutations 

    // Kahn's algorithm
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);

    for(int i = 0; i < m; i++) {
        int u = c[i].first, v = c[i].second;
        // u < v => u -> v
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    int temp_cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            temp_cnt++;
        }
    }

    vector<int> perm;
    // non unique permutation exists 
    if(temp_cnt > 1) 
        return {};

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        perm.push_back(node);

        int cnt = 0;

        for(int nbg: adj[node]) {
            indegree[nbg]--;
            if(indegree[nbg] == 0) {
                q.push(nbg);
                cnt++;
            }
        }

        if(cnt > 1) 
            return {};
    }

    if((int)perm.size() != n) 
        return {};

    // now we must fill the numbers in indices at the perm 
    vector<int> result(n);

    for(int i = 0; i < n; i++) {
        result[perm[i] - 1] = i + 1;
    }

    return result;
}