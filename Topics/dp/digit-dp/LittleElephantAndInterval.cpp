// ================================== digit dp =============================================

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

// question link: https://codeforces.com/problemset/problem/204/A

ll dp[19][2][2][10];
// dp[pos][tight][started][first_digit]

ll f(int ind, int tight, int started, int first_digit, string &num) {
	// base case: all indices of the number placed
	if(ind == num.length()) return started;

	if(dp[ind][tight][started][first_digit] != -1) return dp[ind][tight][started][first_digit];

	ll res = 0;
	int limit = (tight) ? num[ind]-'0' : 9;
	if(!started) {
		// dont start the number yet 
		res += f(ind+1, 0, 0, 0, num);

		// start the number 
		for(int d = 1; d <= limit; d++) {
			int new_tight = tight && (d == num[ind]-'0');

			// if this is the last pos then number is 1 digit 
			if(ind == num.length()-1) res += 1;
			else res += f(ind+1, new_tight, 1, d, num);
		}
	}
	else {
		// the number generation has already started 
		for(int d = 0; d <= limit; d++) {
			// deal with the last digit
			if(ind == num.length()-1 && d != first_digit) continue;

			int new_tight = tight && (d == num[ind]-'0');
			res += f(ind+1, new_tight, started, first_digit, num);
		}
	}

	return dp[ind][tight][started][first_digit] = res;
}

void solve() {
	ll l, r;
	cin >> l >> r;
	l--;
	// ans = f(r) - f(l--)

	string num_l = std::to_string(l);
	string num_r = std::to_string(r);

	memset(dp, -1, sizeof(dp));
	ll res = f(0, 1, 0, 0, num_r);

	memset(dp, -1, sizeof(dp));
	res -= f(0, 1, 0, 0, num_l);

	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// number of integers between l and r such that first and last digit is the same 
	solve();
}