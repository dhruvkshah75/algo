// ========================= precomputation + sliding window =======================================

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

// question link: https://codeforces.com/problemset/problem/814/C

/**
 * we are supposed to answer 2e6 queries at max => we must precompute all the queries 
 * so for each character c => [0...25] try out for all chars 
 * and all possible values of m <= n 
 * precomputation takes O(26 * N * N)
 * and then answer all the queries in O(1) 
 * 
 * now for a given character and given value of m we can calculate the result 
 * using a sliding window where we expand the window by allowing m changes right 
 * that and then get the max length of the window that we can get 
 */

int dp[26][1501];

void solve() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	for(int m = 1; m <= n; m++) {
		// allowed operations are m 
		for(int c = 0; c < 26; c++) {
			int ans = 0;
			int ops_used = 0;

			int l = 0;
			for(int r = 0; r < n; r++) {
				// expand the window on the right 
				int curr = str[r] - 'a';
				if(curr != c) ops_used++;

				// shrink the window when invalid
				while(ops_used > m) {
					int del = str[l] - 'a';
					if(del != c) ops_used--;
					l++;
				}

				ans = max(ans, r-l+1);
			}

			// update the dp value 
			dp[c][m] = ans;
		}
	}

	// answer the queries in O(1) time from all the precomputed values 
	int q;
	cin >> q;
	while(q--) {
		int m;
		char c;
		cin >> m >> c;

		cout << dp[c-'a'][m] << endl;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}