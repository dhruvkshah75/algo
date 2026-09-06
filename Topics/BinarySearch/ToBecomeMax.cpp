// ================================== binary search on answer ===========================================

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

// question link: https://codeforces.com/problemset/problem/1856/C

/*
 * Simple binary search on answer will work here 
 * let the max element that we can try to covert into be x 
 * so in the predicate function try to convert each value into max x 
 * 
 * for each index i try converting arr[i] to x 
 * so convert arr[i+1] to x-1 and ... arr[i+k] to x-k 
 * total ops = (x - arr[i]) + (x-1-arr[i+1]) + ... + (x-k-arr[i+k])
 * stop this when x-k <= arr[i+k] or arr[i+k] < x-k and i+k == n-1
 */

bool isPossible(int x, vector<int> &arr, int k) {
	int n = arr.size();
	ll ops = 1e18;

	for(int i = 0; i < n-1; i++) {
		// try to convert arr[i] to x
		ll cnt = 0;
		bool flag = false;

		for(int idx = i; idx < n; idx++) {
			int k = idx-i, target = x-k;

			if(arr[idx] < target && idx == n-1) {
				flag = true;
				break;
			} 

			if(arr[idx] >= target) break;
			cnt += target - arr[idx];
		}

		if(!flag) ops = min(ops, cnt);
	}

	return ops <= k;
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	int low = *max_element(arr.begin(), arr.end());
	int high = low + k;
	int ans = low;

	// predicate returns ... TTTTTTFFFF...
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(isPossible(mid, arr, k)) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid-1;
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