// ================================================ bitmasking ===============================================

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

// question link: https://codeforces.com/problemset/problem/1646/C

/**
 * Every number can be represented as a sum of powers of 2 
 * and there are 15 factorials <= 1e12 so try out all the subsets of factorials 
 * as a precomputation
 * and number of integers that are powers of 2 are setbits(number)
 **/

const ll MAXN = 1e12+10;
vector<ll> fact;
vector<ll> subsets;

void precompute() {
	fact.push_back(1);
	// fact[0] = 1;

	int n = 2;
	while(n * 1LL * fact.back() < MAXN) {
		ll prev = fact.back();
		fact.push_back(n * 1LL * prev);
		n++;
	}

	int sz = fact.size();
	// calculate all the subsets sums of factorials 
	for(int mask = 0; mask < (1 << sz); mask++) {

		ll curr_sum = 0;
		for(int i = 0; i < sz; i++) {
			// check if the ith bit of mask is set or not 
			int bit = mask & (1 << i);
			if(bit) curr_sum += fact[i];
		}
		subsets.push_back(curr_sum);
	}
}

void solve() {
	ll n;
	cin >> n;

	int ans = setbitsll(n);
	// try out all the subset sums that were precomputed 
	for(int i = 0; i < subsets.size(); i++) {
		// skip subset sums > n
		if(subsets[i] > n) continue;

		int fact_used = setbits(i);
		int powers_used = setbitsll(n - subsets[i]);

		ans = min(ans, fact_used + powers_used);
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	precompute();

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}