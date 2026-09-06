
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

// question link: https://codeforces.com/problemset/problem/2149/E

/*
 * use sliding window concept to calculate all such intervals 
 * calculate intervals <= k distinct ele - <= k-1 distinct ele 
 * for each value of right of the window 
 * 
 * if current valid window size is x and we want to count number 
 * of intervals whose size lies between l and r 
 * if window_size >= r => add r-l to the ans 
 * if window size >= l and < r => add window_size - l + 1
 * and the other case when the window size < l then dont add anything
 */

ll helper(vector<int> &arr, int k, int left, int right) {
	// use sliding window counting method to get subarrays with <= k distinct elements 
	if(k < 0) return 0;

	int n = arr.size();
	map<int,int> mp;
	ll ans = 0;

	int l = 0;
	for(int r = 0; r < n; r++) {
		// expand the window on right 
		mp[arr[r]]++;

		// shrink the window when the window is invalid 
		while(mp.size() > k) {
			int del = arr[l];
			mp[del]--;
			if(mp[del] == 0) {
				mp.erase(del);
			}
			l++;
		}

		int window_size = r-l+1;
		if(window_size >= right) {
			ans += 1LL * (right - left + 1);
		}
		else if(window_size >= left) {
			ans += 1LL * (window_size - left + 1);
		}
	}

	return ans;
}

void solve() {
	int n, k, l, r;
	cin >> n >> k >> l >> r;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	ll result = helper(arr, k, l, r) - helper(arr, k-1, l, r);
	cout << result << endl;
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