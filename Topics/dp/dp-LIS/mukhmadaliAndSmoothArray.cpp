// ===================================== LIS variant dp ================================================

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

// question link: https://codeforces.com/contest/2167/problem/G

/*
 * this question can essentially be transformed into 
 * total_cost = sum(cost) - sum(cost of all kept elements)
 * the elements that are kept must be a part increasing sequence 
 * 
 * here the sequence taken is based to maximise the cost of taken elements 
 * dp[i] = max cost sum of increasing sequence that ends in index i
 */

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n), cost(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	for(int i = 0; i < n; i++) cin >> cost[i];

	vector<ll> dp(n, 0);
	// dp[i] = max cosr of the non decreasing sequence ending at index i

	for(int i = 0; i < n; i++) {
		ll maxi = cost[i];

		for(int j = 0; j < i; j++) {
			if(arr[j] <= arr[i]) {
				maxi = max(maxi, cost[i] + dp[j]);
			}
		}

		dp[i] = maxi;
	}

	ll result = accumulate(cost.begin(), cost.end(), 0LL) - *max_element(dp.begin(), dp.end());
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