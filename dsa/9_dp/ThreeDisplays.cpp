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

// question link: https://codeforces.com/problemset/problem/987/C

void solve(int n, vector<int> &font, vector<int> &cost) {
    
    /* The question is based on LIS (longest inreasing subsequence) => here it is based on cost 
       Here we limit the sequence to a size of 3 and pick the one with the min cost
       dp[i][k] = min cost of increasing subsequence of length k ending at index i
       We cannot greedily get the min cost as it would be forcing it to take the lis 
    */
    const ll INF = 1e15;

    vector<vector<ll>> dp(n, vector<ll>(4, INF));
    // dp[i][1], dp[i][2], dp[i][3]

    for(int i = 0; i < n; i++) {
        dp[i][1] = cost[i];
        // if ith element is the start then min cost would be cost[i]

        for(int j = 0; j < i; j++) {
            // font[i] < font[j] < font[k] => i < j < k
            if(font[i] > font[j]) {
                // going onto 2 from seq length = 1 and onto 3 from seq length = 2
               dp[i][2] = min(dp[i][2], dp[j][1] + cost[i]);

               dp[i][3] = min(dp[i][3], dp[j][2] + cost[i]);
            }
        }
    }

    // now get the min cost total for only those elements whose dp[i].first = 3 (length of LIS is 3)
    ll total_min_cost = INF;

    for(int i = 0; i < n; i++) {
        total_min_cost = min(total_min_cost, dp[i][3]);
    }

    if(total_min_cost == INF) 
        cout << -1 << endl;
    else 
        cout << total_min_cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> font(n), cost(n);

    for(int i = 0; i < n; i++) 
        cin >> font[i];

    for(int i = 0; i < n; i++) 
        cin >> cost[i];

    solve(n, font, cost);
}