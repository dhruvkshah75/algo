#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1167/C
// Question is based on connected group 

void solve(int n, vector<vector<int>> &groups) {
    // we must form the number of connected groups => the person in the part of the connedcted group know each other 

    // we dont need all the edges we just need to form the connected components 
    // so connect edges only of all the nodes only with starting element of the group 

    int m = groups.size();

    vector<vector<int>> adjL(n+1);

    for(int i = 0; i < m; i++) {
        // connect all the nodes of the same group with their 0th node => to form a connect component
        // all the elements of the same connected component can share news to same number of people
        for(int j = 1; j < groups[i].size(); j++) {
            adjL[groups[i][0]].push_back(groups[i][j]);
            adjL[groups[i][j]].push_back(groups[i][0]);
        }
    }

    vector<bool> vis(n+1, false);

    vector<int> result(n+1, 0);   // this is the component size of which the ith node is a part of 

    // apply bfs => for all non visited nodes => as there are multiple non connected nodes 

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;

        queue<int> q;
        q.push(i);
        vis[i] = true;
        // nodes set holds all the nodes that are the part of the same connected component 
        unordered_set<int> nodes;  
        nodes.insert(i);   // insert the starting node

        while(!q.empty()) {
            int currNode = q.front();
            q.pop();

            for(int nbg: adjL[currNode]) {
                if(vis[nbg]) continue;

                vis[nbg] = true;
                nodes.insert(nbg);
                q.push(nbg);
            }
        }

        for(int node: nodes) 
            result[node] = nodes.size();
    }
    
    // now print the resulting array

    for(int i = 1; i <= n; i++)  
        cout << result[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> groups(m);

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < x; j++) {
            int y;
            cin >> y;
            groups[i].push_back(y);
        }
    }

    solve(n, groups);
}