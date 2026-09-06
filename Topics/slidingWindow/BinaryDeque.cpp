// ==================================== sliding window =============================================

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

// question link: https://codeforces.com/problemset/problem/1692/E

/*
 * picking elements from the front and the end is equivalent to getting
 * a window in the middle (inverse window) => window sum that we need is s 
 * to calculate this we can use maximum size sliding window 
 */

void solve() {
	int n, s;
	cin >> n >> s;

	vector<int> arr(n);
	int total_sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		total_sum += arr[i];
	}

	int target = s;

	int l = 0, curr_sum = 0;
	int ans = -1;

	for(int r = 0; r < n; r++) {
		// expand the window on the right 
		curr_sum += arr[r];

		// shrink the window if window is invalid
		while(curr_sum > target) {
			curr_sum -= arr[l];
			l++;
		}

		if(curr_sum == target) {
			ans = max(ans, r-l+1);
			// this is a valid window so update the ans 
		}
	}

	if(ans == -1) cout << -1 << endl;
	else cout << n - ans << endl;
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