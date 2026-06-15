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

// question link: https://codeforces.com/problemset/problem/1195/C

// this is simple dp question bnased on take/not_take case 

static constexpr int N = 1e5;
ll dp[2][N];

ll f(int i, int j, vector<vector<int>> &h, int n) {
    // base case: when all the 2n students are explored
    if(j == n) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    // case 1: dont take the curr student at [i][j] 
    ll not_take = max(f(0, j+1, h, n), f(1, j+1, h, n));

    // case 2: take the curr student and move to the diagonally opposite student 
    int nxt = (i == 1) ? 0 : 1;
    ll take = h[i][j] + f(nxt, j+1, h, n);

    return dp[i][j] = max(take, not_take);
}


void solve(int n, vector<vector<int>> &h) {
    
    memset(dp, -1, sizeof(dp));

    // we could have taken the student at i = 0 or i = 1 => so the max of them is the final answer 
    ll res = max(f(0, 0, h, n), f(1, 0, h, n));

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> h(2, vector<int>(n));

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            cin >> h[i][j];

    solve(n, h);
}