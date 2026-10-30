
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(x) cerr << " " << x << " ";
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)

void solve() {
	ll x, y, k;
	cin >> x >> y >> k;

	if(x == y) {
		// no work assigned to monocarp ever
		cout << 0 << endl;
		return;
	}

	ll diff = y - x;
    ll ans = 0;
    ll month = 0;

    // Until employees become greater than diff
    while(month < k && x + month <= diff) {
        ans += diff % (x + month);
        month++;
    }

    // Once x + month > diff, remainder is always diff
    ans += (k - month) * diff;

    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}