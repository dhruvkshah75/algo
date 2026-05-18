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

// question link: https://codeforces.com/contest/1573/problem/C

// dp + topological sorting => Very Important 

void solve(int n) {
    
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);

    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            // x -> i (directed edge)
            adj[x].push_back(i);
            indegree[i]++;
        }
    }

    // we apply modified Kahn's Algorithm 

    vector<int> dp(n+1, 0); 

    /* dp[i] = pass number in which we read ith chapter 
       In this if we go from u -> v then 
       1. u > v => dp[v] = dp[u] + 1 => we need one more pass to understand this chapter 
       2. u < v => dp[v] = dp[u] => in the same no of pass number as u we understand this chapter */

    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            dp[i] = 1;   // initially all the chapters are read in 1 pass 
        }
    }

    int processed = 0;    // if all n nodes are proccessed then it is a valid topological sort
    int maxReads = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        processed++;

        // the node which takes the maximum pass number is our answer 
        maxReads = max(maxReads, dp[node]);

        for(int nbg: adj[node]) {
            indegree[nbg]--;

            // the nbg chapter must satisfy the hardest prereq 
            if(node < nbg)  dp[nbg] = max(dp[node], dp[nbg]);
            else dp[nbg] = max(dp[nbg], dp[node] + 1); // need a new passing to read it 
               
            if(indegree[nbg] == 0) {
                q.push(nbg);
            }
        }
    }

    if(processed != n) 
        cout << -1 << endl;
    else 
        cout << maxReads << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        solve(n);
    }
}