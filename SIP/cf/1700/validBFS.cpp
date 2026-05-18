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

// question link: https://codeforces.com/contest/1037/problem/D

void solve(int n, vector<vector<int>> &adj, vector<int> &bfsOrder) {
    
    /* apply BFS from 1 and then after each level traversal check if the vertices are there or not 
       and then store the veritces in the queue again in that order */

    if(bfsOrder[0] != 1) {
        no; return;
    }

    int j = 1;

    vector<bool> vis(n+1, false);
    queue<int> q;

    q.push(1);
    vis[1] = true;

    while(!q.empty()) {
        
        int node = q.front();
        q.pop();

        // count the unvisited neighbours of the node => they must appear togethor 
        int cnt = 0; 

        for(int nbg: adj[node]) {
            if(vis[nbg]) continue;
            cnt++;
        }

        // instead of adding in our order => check bfsOrder and then go 

        // next cnt elements in bfsOrder must all be neighbors of node
        unordered_set<int> nbrs(adj[node].begin(), adj[node].end());

        for(int k = j; k < j + cnt; k++) {
            // if we ran out of elements or this nbrs does not cotinain these neighbours togethor 
            if(k >= n || !nbrs.count(bfsOrder[k])) {
                no; return;
            }
            vis[bfsOrder[k]] = true;
            q.push(bfsOrder[k]);
        }

        j += cnt;
    }

    // if all the elements of bfs order were visited then yes 
    if(j == n) {
        yes;
    }
    else {
        no;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> bfsOrder(n);

    for(int i = 0; i < n; i++) 
        cin >> bfsOrder[i];

    solve(n, adj, bfsOrder);
}