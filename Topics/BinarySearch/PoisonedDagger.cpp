// ====================================== binary search =============================================

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

// question link: https://codeforces.com/contest/287/problem/B

bool predicateF(ll k, vector<int> &a, ll h) {
	int n = a.size();

	// poison of the dagger lasts k seconds 
	ll damage = 0;

	for(int i = 0; i+1 < n; i++) {
		ll diff = a[i+1] - a[i];
		damage += min(k, diff);
	}

	damage += k;
	return damage >= h;
}

void solve() {
	int n;
	ll h;
	cin >> n >> h;

	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	// predicate function returns FFFFFTTTTT
	ll low = 1, high = h, ans = -1;
	
	while(low <= high) {
		ll mid = low + (high - low) / 2;
		if(predicateF(mid, a, h)) {
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)
		solve();
}