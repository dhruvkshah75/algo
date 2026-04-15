#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int MOD = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/431/C
// IMPORTANT QUESTION 

void solve(int n, int k, int d) {
    // at least one weight w >= d in the path 

    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    // dp[i][j]
    // i: current total sum (0 to n)
    // j: 0 if no edge >= d has been used, 1 if at least one edge >= d has been used

    dp[0][0] = 1;  

    // for each sum i add a new edge weight to reach next state 

    for(int i = 0; i < n; i++) {
        for(int w = 1; w <= k; w++) {
            // the next sum i + w is bigger than target then skip 
            if(i + w > n) break;

            if(w >= d) {
                // if wieght d encountered switch from 0 to 1 (regardless )
                dp[i + w][1] = (dp[i + w][1] + dp[i][0]) % MOD;
                dp[i + w][1] = (dp[i + w][1] + dp[i][1]) % MOD;
            }
            else {
                // w < d; => no transition from j = 0 to 1 
                dp[i + w][0] = (dp[i + w][0] + dp[i][0]) % MOD;
                dp[i + w][1] = (dp[i + w][1] + dp[i][1]) % MOD;
            }
        }
    }

    // print the ways to reach sum of n with at least one edge in the path with edge w >= d 
    cout << dp[n][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, d;
    cin >> n >> k >> d;

    solve(n, k, d);
}