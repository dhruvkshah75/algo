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

// question link: https://cses.fi/problemset/task/3403

/* The same as lcs logic => we must build the lcs sequence using the dp table in tabulation */

/*
int f(int i, int j, vector<int> &a, vector<int> &b) {
    // base case: either of the arr is processed 
    if(i < 0 || j < 0) return 0;

    // case1: when both numbers match 
    if(a[i] == b[j]) 
        return 1 + f(i-1, j-1, a, b);

    // case 2: when numbers dont match
    return max(f(i-1, j, a, b), f(i, j-1, a, b));
} */

void solve(int n, int m, vector<int> &a, vector<int> &b) {
     
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // dp[i][j] = length of the lcs of a[0...i] and b[0...j]
    // dp => 1 based indexing 

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // when nums match 
            if(a[i-1] == b[j-1]) 
                dp[i][j] = 1 + dp[i-1][j-1];
            // when nums dont match 
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << endl;

    vector<int> res;
    // Using the dp table generated in tabulation generate the lcs 
    int i = n, j = m;

    while(i > 0 && j > 0) {
        if(a[i-1] == b[j-1]) {
            // dp[i][j] = 1 + dp[i-1][j-1]
            res.push_back(a[i-1]);
            i--;
            j--; 
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
    }

    reverse(all(res));

    for(int x: res) 
        cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    for(int j = 0; j < m; j++) 
        cin >> b[j];

    solve(n, m, a, b);
}