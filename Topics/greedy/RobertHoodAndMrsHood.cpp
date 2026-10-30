
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

// question link: https://codeforces.com/problemset/problem/2014/D

void solve() {
	int n, d, k;
	cin >> n >> d >> k;

	vector<int> diff(n+1, 0);

	for(int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		diff[l] += 1;
		diff[r+1] -= 1;
	}

	// take the prefix sum of the diff array to get how many jobs overlap a day
	for(int i = 1; i <= n; i++) {
		diff[i] += diff[i-1];
	}

	multiset<int> ms;
	// store the elements of the window of size d in the set 

	int l = 1;
	int mn = 1e8, mn_day = -1;  // for mother 
	int mx = -1, mx_day = -1;   // for brother

	for(int r = 1; r <= n; r++) {
		// expand the window on the right
		ms.insert(diff[r]);

		// shrink the window if it becomes d+1
		if(r-l+1 > d) {
			auto it = ms.find(diff[l]);
			ms.erase(it);
			l++;
		}

		if(r-l+1 == d) {
			// window is valid then we must check min and max 
			int min_val = *ms.begin(), max_val = *ms.rbegin();

			if(max_val > mx) {
				mx = max_val;
				mx_day = l;
			}

			if(min_val < mn) {
				mn = min_val;
				mn_day = l;
			}
		}
	}

	// mx_day = brother, mn_day = mother 
	cout << mx_day << " " << mn_day << endl;
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