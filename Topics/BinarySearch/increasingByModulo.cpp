// =========================================== binary search on answer =================================================

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

// question link: https://codeforces.com/problemset/problem/1169/C

/*
 * each operation involves selecting k elements aand incrementing them 
 * this operation per element can be thought of as 
 * max(number of increments per element) for all elements 
 * 
 * now use binary search on min number of operations 
 * let the value be k => each element can be incremented at most k times   
 * Now for the predicate function do a reverse traversal to get the answer 
 * keep a track of max element that we formed as mx
 * and try to convert each number into max possible value <= mx
 */

int n, m;
vector<int> arr;

bool isPossible(int x) {
	// each element can be incremented at most x times 
	int mx = m-1;

	for(int ind = n-1; ind >= 0; ind--) {
		// try to make the current element as close as mx using given x operations 
		if(arr[ind] <= mx) {
			int max_ele = min(arr[ind] + x, mx);
			mx = min(mx, max_ele);
		}
		else {
			// arr[ind] needs to wrap around => use some ops to bring arr[ind] = 0
			int ops_left = x - (m - arr[ind]);
			if(ops_left < 0) return false; 

			mx = min(0 + ops_left, mx);
		}
	}

	return true;
}

void solve() {
	cin >> n >> m;

	arr.assign(n, 0);
	for(int i = 0; i < n; i++) cin >> arr[i];

	// predicate function returns ..FFFFFTTTTT..
	int low = 0, high = m-1;
	int ans = 0;

	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(isPossible(mid)) {
			ans = mid;
			high = mid-1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}