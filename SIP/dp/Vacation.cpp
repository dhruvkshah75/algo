#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

const int mod = 1e9+7;
const int inf = 1e9;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define CHECK

// question link: https://codeforces.com/problemset/problem/698/A

void solve(int n, vector<int> &a) {

    /* a = 0 => gym closed and no contest, a = 1 => gym closed contest carried out 
       a = 2 => gym open and no contest, a = 3 => gym open and contest carried out 
       cannot play sports or write contest on two consecutive days 
       Use 2d dp where dp[i][j] = min rest days till ith day doing the jth activity => 0 = rest, 1 = contest, 2 = gym */

    vector<vector<int>> dp(n+1, vector<int>(3, inf));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    
    for(int i = 0; i < n; i++) {
        // choice 0 => take rest today 
        dp[i+1][0] = 1 + min({dp[i][0], dp[i][1], dp[i][2]});

        // choice 1 => attempt the contest on ith day  
        if(a[i] == 1 || a[i] == 3) {
            dp[i+1][1] = min(dp[i][0], dp[i][2]);
        }

        // choice 2 => going to the gym on ith day 
        if(a[i] == 2 || a[i] == 3) {
            dp[i+1][2] = min(dp[i][0], dp[i][1]);
        }
    }

    // the minimum numbers of rest days will be min of dp[n] of all the activities 
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef CHECK
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    solve(n, a);
}