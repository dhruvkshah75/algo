
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define pb push_back
#define all(a) (a).begin(), (a).end()
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
const int M = 1e9+7;

// Solution begins here: 

const int N = 1e5+10;
vector<int> h(N);
int dp[N];

int func(int i, int k){
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    int cost = INT_MAX;
    for(int j=1; j<=k; j++){
        if(i-j >= 0) cost = min(cost, func(i-j, k) + abs(h[i]-h[i-j]));
    }
    return dp[i] = cost;
}
// O(k*n) 

void solve(){
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    fx(i, n, 0){
        cin >> h[i];
    }

    cout << func(n-1, k) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}