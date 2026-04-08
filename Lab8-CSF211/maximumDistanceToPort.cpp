#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/2172/M

void solve(int n, int m, int k, vector<pair<int,int>> &edges, vector<int> &product) {
    // prepare the adjaceny list 
    vector<vector<int>> adjL(n+1);

    for(int i = 0; i < m; i++) {
        auto [u, v] = edges[i];
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    vector<bool> vis(n+1, false);
    vector<int> result(k+1, -1);
    // product => 1 to k

    queue<int> q;
    // q = node
    int dist = 0;

    q.push(1);
    vis[1] = true;
    result[product[1]] = dist;

    while(!q.empty()) {
        int qSize = q.size();
        dist++;

        while(qSize--) {
            int node = q.front();
            q.pop();

            for(int nbg: adjL[node]) {
                if(vis[nbg]) continue;

                // since we want max dist we will push all the unvisited nodes
                int nbgProduct = product[nbg];

                q.push(nbg);
                vis[nbg] = true;
                result[nbgProduct] = max(result[nbgProduct], dist);
            }
        }
    }

    // now we print 1 to k result 
    for(int i = 1; i <= k; i++) 
        cout << result[i] << " ";
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> product(n+1);
    // product[i] = product produced by the ith city 

    for(int i = 1; i <= n; i++)
        cin >> product[i];

    vector<pair<int,int>> edges(m);

    for(auto &[u, v]: edges)
        cin >> u >> v;

    solve(n, m, k, edges, product);

}