// ======================================= prefix sum + maps =========================================

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

// question link: https://codeforces.com/problemset/problem/1398/C

/*
 * The condition of a good subarray is sum(a[l...r]) = r-l+1
 * this can be formulated as prefix[r] - prefix[l-1] = r - l + 1
 * 
 * prefix[r] - prefix[l-1] = r - (l - 1)
 * prefix[r] - r = prefix[l-1] - (l - 1)
 * this formula is essentially equal to prefix[idx] - idx
 * 
 * so we store the prefix[idx] - idx into the map so we can check this in O(1) 
 * calculate the prefix array and use map to check prefix[r] - r in the map
 */

void solve() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	vector<int> prefix(n+1);
	prefix[0] = 0;

	for(int i = 1; i <= n; i++) {
		int num = str[i-1] - '0';
		prefix[i] = prefix[i-1] + num;
	}

	unordered_map<int,int> mp;
	mp[prefix[0] - 0]++;
	ll ans = 0;

	for(int r = 1; r <= n; r++) {
		int val = prefix[r] - r;

		if(mp.find(val) != mp.end()) {
			ans += 1LL * mp[val];
		}

		mp[val]++;
	}

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