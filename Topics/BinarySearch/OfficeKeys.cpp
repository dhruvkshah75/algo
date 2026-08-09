// ========================================= binary search + 2 pointers ==========================================

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

// question link: https://codeforces.com/problemset/problem/831/D

/*
 * Simply apply binary search on answer the time taken for all employees to reach office 
 * so the predicate function returns FFFFFTTTTT => return first occ of True 
 * 
 * how to check if all peoples can reach the office with some nearest key to the office 
 * sort all locations of employees and keys and then using two pointers check which key 
 * can be alloted to whom
 * 
 * invariance => if emp[i] uses key[j] then it can be said that emp[i+1] will not use any key 
 * in the range [0...j]
 */

bool canReach(ll T, vector<int> &emp, vector<int> &keys, int p) {
	int n = emp.size(), k = keys.size();

	// if all employees can use some key and reach office 
	int i = 0, j = 0;

	while(i < n && j < k) { 
		ll time_to_reach = abs(emp[i] - keys[j]) + abs(keys[j] - p);

		if(time_to_reach <= T) {
			// emp[i] used this key j to reach
			i++;
			j++;
		}
		else {
			// this key cannot be used => too far 
			j++;
		}
	}

	return (i == n);
}

void solve() {
	int n, k, p;
	cin >> n >> k >> p;

	vector<int> emp(n);
	for(int i = 0; i < n; i++) cin >> emp[i];

	vector<int> keys(k);
	for(int j = 0; j < k; j++) cin >> keys[j];

	// sort all locations of employees 
	sort(all(emp));

	// sort all keys also on based on locations
	sort(all(keys));

	ll low = 0, high = 1e14;
	ll ans = -1;

	while(low <= high) {
		ll mid = low + (high - low) / 2;
		if(canReach(mid, emp, keys, p)) {
			high = mid - 1;
			ans = mid;
		}
		else low = mid + 1;
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}