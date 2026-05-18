#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1676/G

void dfs(vector<vector<int>> &adjL, vector<int> &cntB, vector<int> &cntW, vector<int> &dp, string &color, int node) {

    // update the color of this node 
    (color[node-1] == 'W') ? cntW[node]++ : cntB[node]++;

    for(int nbg: adjL[node]) {
        dfs(adjL, cntB, cntW, dp, color, nbg);

        // update the cnts of white and black 
        cntB[node] += cntB[nbg];
        cntW[node] += cntW[nbg];

        // update the dp count
        dp[node] += dp[nbg];
    }

    // if subtree rooted at node is valid 
    if(cntB[node] == cntW[node]) {
        dp[node]++;
    }
}

void solve(int n) {
    // apply dfs and reaching the end store the number of black and and white vertices in it 
    // while backtracking use dp vector to add up the number of subgraphs and then return dp[1]

    vector<vector<int>> adjL(n+1);

    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        // p-> i  (p is parent of i)
        adjL[p].push_back(i);
    }

    string color;
    cin >> color;

    vector<int> dp(n+1, 0), cntW(n+1, 0), cntB(n+1, 0);
    // dp[i] = no of balanced subtrees for the tree below the one rooted at i

    dfs(adjL, cntB, cntW, dp, color, 1);
    
    cout << dp[1] << endl;
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