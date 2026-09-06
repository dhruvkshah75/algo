// ================================== two pointers + map data structure =================================

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

// question link: 

/**
 * calculate the final ans = total - bad or invalid subarrays 
 * so use prefix sum with map to get the subarray with sum = 0
 * prefix[r] = prefix[x] => sum([x+1...r]) = 0
 * 
 * now to count such invalid subarrays we must extend this by keeping one of the
 * endpoint is constant so keep r as constant and for each value of r 
 * figure out how many subarrays are invalid in it 
 * 
 * total number of subarrays are 1(ending in r = 1) + 2 + 3 + ....+ n = n * (n+1) / 2
 * always consider the subarray with max value of L in [L..R] as this prevents overcounting
 * when extending on the left
 **/

void solve() {
	int n;
	cin >> n;

	ll total = n * 1LL * (n + 1) / 2;

	vector<int> arr(n);
	vector<ll> prefix(n+1, 0);

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		prefix[i+1] = prefix[i] + arr[i];
	}

	ll bad = 0;
	int boundary = 0;
	unordered_map<ll,int> latest;
	latest[0] = 0;
	// latest stores the latest occurrence of the key (prefix)
	// boundary is used to calculate => biggest L value for that particular r

	for(int r = 1; r <= n; r++) {
		// calculate the number of invalid subarrays ending in r (fixed endpoint)
		ll val = prefix[r];

		if(latest.find(val) != latest.end()) {
			int x = latest[val];
			// sum([x+1...r]) = 0
			boundary = max(boundary, x+1); 
		}

		bad += boundary;
		latest[prefix[r]] = r;
	}

	cout << total - bad << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}