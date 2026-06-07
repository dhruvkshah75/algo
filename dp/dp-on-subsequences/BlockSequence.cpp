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

// question link: https://codeforces.com/problemset/problem/1881/E

/* This is a variant of 0/1 knapsack
   option1: delete the element and move to i+1 
   option2: select the current subset if valid (i + len < n) */

/* 
int f(int i, int n, vector<int> &a, vector<int> &dp) {
    // base case: if index goes out of bounds 
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    // option 1: delete the ith element 
    int del = 1 + f(i+1, n, a, dp);

    // option 2: take the subset of len a[i]
    int take = 1e8;
    if(i + a[i] < n) take = f(i + a[i] + 1, n, a, dp);

    return dp[i] = min(del, take);
} */

void solve(int n, vector<int> &a) {
    
    int dp[n+1];
    // dp[i] = min deletions needed to make the suffix a[i..n-1] beautiful

    // base case: i == n => dp = 0
    dp[n] = 0;

    // i = n-1 -> 0
    for(int i = n-1; i >= 0; i--) {
        int del = 1 + dp[i+1];

        int take = 1e8;
        if(i + a[i] < n) take = dp[i + a[i] + 1];

        dp[i] = min(del, take);
    }

    int res = dp[0];

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        solve(n, a);
    }
}