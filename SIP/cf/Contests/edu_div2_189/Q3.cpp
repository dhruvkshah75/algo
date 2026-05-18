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

// question link: https://codeforces.com/contest/2225/problem/C

void solve(int n, vector<string> &table) {

    // vertical pairing => 2x1 consideration and horizontal pairing => 2x2 consideration 
    // must use dp as it depends on what we did on previous cells 
    
    vector<int> dp(n+1, 1e9);

    /* dp[i] = min repaints needed till the ith column 
       vertical pairing => dp[i] = dp[i-1] + cost
       horizontal pairing => dp[i] = dp[i-2] + top_cost + bottom cost  

       keep 0 as the buffer column 
    */
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        // vertical pairing 
        int cost_v = (table[0][i-1] != table[1][i-1]);
        dp[i] = min(dp[i], dp[i-1] + cost_v);
        
        // horizontal pairing 
        if(i >= 2) {
            int cost_h = (table[0][i-1] != table[0][i-2]) + (table[1][i-1] != table[1][i-2]);
            dp[i] = min(dp[i], dp[i-2] + cost_h);
        }
    }

    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<string> table(2);

        cin >> table[0];
        cin >> table[1];

        solve(n, table);
    }
}