// ============================= greedy + priority queues + binary search ===================================

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

// question link: https://codeforces.com/problemset/problem/1462/F

/*
 * consider each segment as the one that intersects with all segments in the set 
 * now we must count the numbers of segments that must be deleted from all these 
 * 	
 * sort all the segments based on the start values and break ties on smaller r's 
 * now to get how many to delete on right => use upper bound on end value of the current 
 * segment all the segments starting from the upper bound needs to be deleted 
 * 
 * use priority queue min heap to track all the active segments on the left and 
 * the ones popped needs to be deleted for the segment 
 */

void solve() {
	int n;
	cin >> n;

	vector<pii> segs;
	for(int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		segs.push_back({l, r});
	}

	sort(all(segs));
	// sort on l values 

	priority_queue<int,vector<int>,greater<int>> pq;
	// min heap to store the end values of valid intervals 

	int popped = 0;
	int ans = 1e9;

	for(int i = 0; i < n; i++) {
		auto [l, r] = segs[i];

		// remove all expired intervals 
		while(!pq.empty() && pq.top() < l) {
			pq.pop();
			popped++;
		}

		// binary search to calculate the upper bound of r 
		int low = i+1, high = n-1;
		int idx = n;

		while(low <= high) {
			int mid = low + (high - low) / 2;
			if(segs[mid].first > r) {
				idx = mid;
				high = mid-1;
			}
			else low = mid+1;
		}

		// push the current segments end value in the min heap 
		pq.push(r);

		int del = n - idx;

		// segments to delete on right are del and on left are popped 
		ans = min(ans, popped + del);
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