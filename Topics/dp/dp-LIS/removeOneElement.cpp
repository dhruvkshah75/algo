// ======================================= dp =====================================

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

// question link: https://codeforces.com/contest/1272/problem/D

/*
 * A simple dp solution will work out as we are dealing with only consecutive subarrays 
 * we have the choice of deleting the ith element 
 * so we need to get two values for each element 
 * longest increasing seq ending at the index i-1 (including the element arr[i-1])
 * and longst increasing seq starting at index i+1 
 * The deletion is only valid when arr[i-1] < arr[i+1] => after deletion this joins 
 * or the other case remains where we dont delete so take the max of dp1 itself
 */

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n+2);
	arr[0] = 0;
	arr[n+1] = INT_MAX;

	for(int i = 1; i <= n; i++) 
		cin >> arr[i];

	vector<int> dp1(n+1);
	// dp1[i] = longest increasing seq ending at index i 
	dp1[0] = 0;

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		// i extends the seq ending at i-1 
		if(arr[i] > arr[i-1]) dp1[i] = dp1[i-1] + 1;
		else dp1[i] = 1; 

		// get the max => case when we dont delete any element
		ans = max(ans, dp1[i]);
	}

	vector<int> dp2(n+2);
	// dp2[i] = longest seq starting at i
	dp2[n+1] = 0;

	for(int i = n; i >= 1; i--) {
		// i extends the seq at i+1
		if(arr[i] < arr[i+1]) dp2[i] = dp2[i+1] + 1;
		else dp2[i] = 1;

		ans = max(ans, dp2[i]);
	}

	// now try deleting all the elements 
	for(int i = 1; i <= n; i++) {
		// deleting only makes sense if the subarray formed later is increasing
		if(arr[i-1] < arr[i+1]) 
			ans = max(ans, dp1[i-1] + dp2[i+1]);
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}