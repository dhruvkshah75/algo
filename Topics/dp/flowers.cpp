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

// question link: https://codeforces.com/problemset/problem/474/D

/*
    start by placing flowers at ith position => when placing white must be placed in grps of k (i.e. placing k white flowers togethor)
    This only involves 1 parameter the index where flowers are placed 
    In recursion we explore all possible options for placing flowers 

    // ============================================== Memoization dp ===========================================================
    wont work as this 

    int f(int x, int k, vector<int> &dp) {
        // base case => white flowers cannot be placed (x < k)
        if(x < k) return 1;

        // base case => white flowers can be placed (exactly k) and red 
        if(x == k) return 2;

        if(dp[x] != -1) 
            return dp[x];

        ll red = f(x - 1, k, dp);
        ll white = f(x - k, k, dp);

        return dp[x] = (white + red) % mod;
    }
*/

const int N = 1e5 + 1;

void solve(int t, int k, vector<int> &dp) {

    // starting from the base cases 
    for(int i = 0; i <= k; i++) {
        if(i == k) dp[i] = 2;
        else dp[i] = 1;
    }

    for(int i = k + 1; i <= N; i++) {
        ll red = dp[i - 1];
        ll white = dp[i - k];

        dp[i] = (red + white) % mod;
    }

    // result = sum of dp[a] + dp[a + 1] + ... + dp[b]
    // must take the prefix sum of dp array to for each query to be O(1)

    vector<int> pf(N, 0);
    pf[0] = dp[0];

    for(int i = 1; i < N; i++) 
        pf[i] = (pf[i - 1] * 1LL + dp[i]) % mod;


    while(t--) {
        int a, b;
        cin >> a >> b;

        // handle negatives in modulus 
        cout << (pf[b] - pf[a - 1] + mod) % mod << endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t >> k;

    vector<int> dp(N, 0);

    solve(t, k, dp);
}