// ============================ sliding window ====================================

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

// question link: https://codeforces.com/problemset/problem/1692/G

/**
 * we can use the concept of sliding window where the transition is different 
 * we try to expand on the right if the condition x < 2y is true 
 * as 2^j * x < 2^j+1 * y => this is equivalent to x < 2y 
 * 
 * and update the counter when the window size becomes k+1 and then shrink the window 
 * from the left to l+1 so we can expand to right in the next iteration 
 * 
 * now the case when we cant expand on the right say x >= 2*y => then x and y 
 * togethor cannot be a part of the same window so update the left pointer to r 
 * */

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0;
	int l = 0;
	for(int r = 1; r < n; r++) { 
		if(arr[r-1] < 2 * arr[r]) { 
			// expand only if the condition is true
		}
		else {
			// update the left pointer 
			l = r;
		}

		// if the window size becomes bigger then shrink 
		if(r-l+1 > k+1) l++;
		
		if(r-l+1 == k+1) ans++;
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