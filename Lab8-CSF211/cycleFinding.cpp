#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://cses.fi/problemset/task/1197

void solve(int n, int m, vector<tuple<int,int,int>> &edges) {
    // start from 1  as out main goal is just negative cycle detection
    
    // if there are multiple connnected components then start from dist = 0 => as we dont have just one starting node

    // ======================== CYCLE DETECTION USING BELLMAN FORD ===============================================
    // ===========================================================================================================
    vector<ll> dist(n+1, 0);     
    vector<int> parent(n+1, -1);   // for building the path 
    dist[1] = 0;

    // Bellman Ford
    for(int i = 0; i < n-1; i++) {
        // relax the edge n-1 times 
        for(auto [u, v, w]: edges) {
            // relax u -> v
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // detect the negative cycle 
    int curr = -1;
    // relax the edges for the Nth time
    for(auto [u, v, w]: edges) {
        if(dist[u] + w < dist[v]) {
            // V.IMP: update the parent for the cycle 
            parent[v] = u;
            curr = v;   // v is the node affected by the negative cycle 
            break;
        }
    }

    if(curr == -1) {
        no;
    }
    else {
        yes;

        unordered_set<int> inStack;
        stack<int> st;

        while(!inStack.count(curr)) {
            // mark that the node is now in the stack 
            inStack.insert(curr);
            st.push(curr);
            curr = parent[curr];
        }   

        // now curr points to the node where cycle repeats => print nodes from stack until curr repeats 
        cout << curr << " ";

        while(st.top() != curr) {
            cout << st.top() << " ";
            st.pop();
        }
        // print the curr node again for complete cycle 
        cout << curr << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges(m);

    for(auto &[u, v, w]: edges) 
        cin >> u >> v >> w;

    solve(n, m, edges);
}