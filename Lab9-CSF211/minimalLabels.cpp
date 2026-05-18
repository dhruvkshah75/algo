#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/825/E

void solve(int n, int m, vector<pii> &edges) {
    /* In this we are suppose v -> u ==> label v < label u 
       we want lexicographically smallest => label[1] label[2] ... label[n]
       So reverse the edges and then run Kahn's algorithm and assign them labels from n to 1 
       and use a max heap to get the biggest node on the top so we can mark them with the biggest label available 
    */

    int mark = n;

    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0), labels(n+1);

    for(auto [u, v]: edges) {
        // reverse the edge 
        adj[v].push_back(u);
        indegree[u]++;
    }

    priority_queue<int> pq;

    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int node = pq.top();
        pq.pop();

        labels[node] = mark;
        mark--;

        for(int nbg: adj[node]) {
            indegree[nbg]--;

            if(indegree[nbg] == 0) 
                pq.push(nbg);
        }
    }

    // now the labels will be correctly marked in the smallest lexicographical order 
    for(int i = 1; i <= n; i++) 
        cout << labels[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<pii> edges(m);

    for(auto &[u, v]: edges)
        cin >> u >> v;

    solve(n, m, edges);
}