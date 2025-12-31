// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(x) cerr << #x << " = " << x << endl;

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

// this implements sliding window 
ll countAtMostK(const vector<int>& a, int K, int L) {
    if (K < 0 || L <= 0) return 0;
    unordered_map<int,int> freq;
    int n = a.size();
    int l = 0, distinct = 0;
    ll res = 0;

    for(int r = 0; r < n; r++){
        if (++freq[a[r]] == 1) distinct++;
        while (distinct > K) {  // If window has too many distinct elements, shrink it from the left.
            if(--freq[a[l]] == 0) distinct--;  // When an element’s count drops to 0, we lost a distinct number → decrement distinct.
            l++;
        }
        int validLeft = max(l, r - L + 1);
        res += (r - validLeft + 1);
    }
    return res;
}

void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = (countAtMostK(a, k, r) - countAtMostK(a, k, l-1)) - (countAtMostK(a, k-1, r) - countAtMostK(a, k-1, l-1));

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}