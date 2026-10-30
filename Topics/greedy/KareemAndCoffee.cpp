
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

// question link: https://codeforces.com/problemset/problem/816/B

const int MAXN = 2e5+2;

void solve() {
	int n, k, q;
	cin >> n >> k >> q;

	vector<int> diff(MAXN, 0);

	for(int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		// update the range with this value
		diff[l] += 1;
		diff[r+1] -= 1;
	} 

	vector<int> prefix(MAXN, 0);
	prefix[0] = ((diff[0] >= k) ? 1 : 0);

	// take the prefix array of the diff to get the correct result 
	for(int i = 1; i < MAXN; i++) {
		diff[i] += diff[i-1];
		// consider this temp when at least k recipes are there 
		prefix[i] = ((diff[i] >= k) ? 1 : 0);
		prefix[i] += prefix[i-1];
	}

	while(q--) {
		int a, b;
		cin >> a >> b;
		cout << prefix[b] - prefix[a-1] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}