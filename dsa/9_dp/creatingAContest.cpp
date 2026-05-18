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

// question link: https://codeforces.com/problemset/problem/1029/B

void solve(int n, vector<int> &a) {

    // can easily be done without dp by using space optimization 
    
    // dp[i] = The maximum length of a valid contest ending exactly at the i-th problem.
    vector<int> dp(n);
    dp[0] = 1;

    for(int i = 1; i < n; i++) {
        if(2 * a[i-1] >= a[i]) {
            dp[i] = dp[i-1] + 1;
        }
        else {
            // start fresh 
            dp[i] = 1;
        }
    }

    cout << *max_element(all(dp)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    solve(n, a);
}