// ========================================== binary search + sliding window ==================================================

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

// question link: https://codeforces.com/problemset/problem/1777/C

/**
 * topics are 1,2,3,.....,m
 * simple sliding window of min size will work in this case 
 * expand the window on right => mark the factors in window array 
 * and keep a cnt of factors covered so if it is m then window is valid 
 * we keep shrinking the window until it reamins valid 
 * 
 * valid window => cnt = m (covered all m topics)
 * 
 **/

const int N = 1e5+10;
vector<vector<int>> divisors(N);
// divisors[i] = all factors of number <= 1e5

void precompute() {
	// compute all divisors in O(N * sqrt(N))
	for(int i = 1; i < N; i++) {
		int num = i;
		for(int j = 1; j * j <= num; j++) {
			if(num % j != 0) continue;

			if(num == j * j) {
				divisors[num].push_back(j);
				continue;
			}
			divisors[num].push_back(num / j);
			divisors[num].push_back(j);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	int l = 0, ans = 1e9;
	vector<int> window(m+1, 0); 
	int cnt = 0;

	// use sliding window of minimum size => shrink until window reamins valid 
	for(int r = 0; r < n; r++) {
		// expand the window on right
		for(int div: divisors[arr[r]]) {
			if(div > m) continue;

			if(window[div] == 0) cnt++;
			window[div]++;
		}

		// shrink until window remains valid 
		while(cnt == m) {
			ans = min(ans, arr[r] - arr[l]);

			// remove the element arr[l] 
			for(int div: divisors[arr[l]]) {
				if(div > m) continue;

				if(window[div] == 1) cnt--;
				window[div]--;
			}

			l++;
		}
	}

	if(ans == 1e9) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// precompute all the divisors
	precompute();

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}