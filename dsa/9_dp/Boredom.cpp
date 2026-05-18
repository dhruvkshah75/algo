#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/455/A
// dp on 1d grid

const int MAXV = 1e5 + 10;

void solve(int n, vector<int> &arr) {
    // base case 
    if(n == 1) {
        cout << arr[0] << endl;
        return;
    }

    vector<int> freq(MAXV, 0);

    for(int i = 0; i < n; i++)  
        freq[arr[i]]++;

    // for every value i => 2 choices we pick i or we do not pick i 
    // 1. dp[i] = dp[i-1] ==> we did not pick i  2. dp[i] = dp[i-2] + i * count[i]  => if i is picked then we cant pick i-1

    vector<ll> dp(MAXV, 0);
    // dp[i] = max points considering numbers with value from 0 to i
    dp[0] = 0;
    dp[1] = 1 * freq[1];

    // recurrence relations => dp[i] = max(dp[i-1], dp[i-2] + i * count[i])
    // we calculate for values rather than elements in array => a[i] <= 1e5

    for(ll i = 2; i <= MAXV; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + i * freq[i]);
    }

    // maximum points earned from picking 0 to 1e5
    cout << dp[1e5] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    solve(n, arr);
}