// =================================== binary search on answer ==========================================

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

// question link: https://codeforces.com/problemset/problem/1119/B

vector<int> a;

bool canPlace(int k, int h) {
	int n = a.size();

	// can we place k bottles in the fridge 
	vector<int> temp;
	for(int i = 0; i < k; i++) {
		temp.push_back(a[i]);
	}

	sort(rall(temp));

	ll maxi = 0;
	for(int i = 0; i < k; i += 2) {
		if(i+1 < k) maxi += 1LL * max(temp[i], temp[i+1]);
		else maxi += temp[i];

		if(maxi > h) return false;
	}

	return (maxi <= h);
}

void solve() {
	int n, h;
	cin >> n >> h;

	a.resize(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	// binary search on value of k => predicate returns TTTTTFFFF
	int low = 1, high = n;
	int ans = 1;

	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(canPlace(mid, h)) {
			low = mid+1;
			ans = mid;
		}
		else high = mid-1;
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}