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

// question link: https://codeforces.com/problemset/problem/919/D

// dp + topological sort ==> Important Question 

void solve(int n, int m, string &str, vector<vector<int>> &adj, vector<int> &indeg) {
    
    /* Use Kahn's algorithm for topological sorting and then at each node we use dp[i][k] 
       dp[i][k] = count of number of K (0 - 26 aka 'a' to 'z') occurrences till the ith node 
       suppose A -> C and B -> C we have a choice to reach C from B or A => so we must take max at dp */

    vector<vector<int>> dp(n+1, vector<int>(26, 0));

    queue<int> q;
    // we store the topological sort order to check if there is no cycle 
    vector<int> topoSort;

    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) {
            q.push(i);
            int k = str[i-1] - 'a';
            dp[i][k] += 1;
        }
    }

    int result = INT_MIN;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);

        // update the ans at each node being processed 
        for(int k = 0; k < 26; k++) {
            result = max(result, dp[node][k]);
        }

        for(int nbg: adj[node]) {
            indeg[nbg]--;

            // update the dp for this nbg node for all 26 characters 
            for(int i = 0; i < 26; i++) {
                dp[nbg][i] = max(dp[nbg][i], dp[node][i]);
            }

            if(indeg[nbg] == 0) {
                q.push(nbg);
                int k = str[nbg-1] - 'a';
                dp[nbg][k]++;
            }
        }
    }

    if(topoSort.size() != n) {
        // there is cycle in the graph so Not a DAG 
        cout << -1 << endl;
        return;
    } 

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // directed edge u -> v
        indegree[v]++;
    }

    solve(n, m, str, adj, indegree);
}