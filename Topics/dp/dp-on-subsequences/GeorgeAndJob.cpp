// ======================================== dp =======================================

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

// question link: https://codeforces.com/problemset/problem/467/C

/*
 * maximum sum of k segments => each segment has a fixed length of m
 * each segment is non overlapping so this is easy to compute 
 * to maximise sum(prefix[r] - prefix[l-1]) for k segments 
 * so the dp recurrence => f(ind, segs_left) 
 */

const ll INF = -1e18;
	
int n, m, k;
vector<ll> prefix;
vector<vector<ll>> dp;

ll f(int ind, int segs_left) {
	// when all segments are considered 
	if(segs_left == 0) return 0;

	// no more elements left but segments are left
	if(ind == n+1) return INF;

	if(dp[ind][segs_left] != -1) return dp[ind][segs_left];

	ll res = INF;
	// skip this current element consider a new segment later 
	res = max(res, f(ind+1, segs_left));

	// pick this segment starting from ind
	int r = ind + m - 1, l = ind;
	if(r <= n) {
		ll val = prefix[r] - prefix[l-1];
		res = max(res, val + f(r+1, segs_left - 1));
	}

	return dp[ind][segs_left] = res;
}

void solve() {
	cin >> n >> m >> k;
	// m is the segment length and k 

	prefix.assign(n+1, 0);
	prefix[0] = 0;

	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		prefix[i] = prefix[i-1] + x;
	}

	if(m * k == n) {
		// all elements must be taken 
		cout << prefix[n] << endl;
		return;
	}

	dp.assign(n+1, vector<ll>(k+1, -1));
	ll result = f(1, k);

	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}