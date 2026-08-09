// ========================================== math ==========================================================

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

// question link: https://codeforces.com/problemset/problem/1374/D

void solve() {
	int n, k;
	cin >> n >> k;

	// store the num % k in the map with its freq
	unordered_map<int,int> freq;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x %= k;
		freq[x]++;
	}

	// all numbers are already divisible by k
	if(freq[0] == n) {
		cout << 0 << endl;
		return;
	}

	// for each num ops needed will be freq[num]*k - num
	ll maxi = 0;
	for(auto [num, cnt]: freq) {
		// skip num = 0 as already divisible
		if(num == 0) continue;
		maxi = max(maxi, cnt * 1LL * k - num);
	}
	
	// 1 op is needed for x -> x+1
	cout << maxi + 1 << endl;
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