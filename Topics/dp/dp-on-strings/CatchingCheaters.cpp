// =========================== dp on strings ====================================

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

// question link: https://codeforces.com/problemset/problem/1446/B

/**
 * very important dp on strings questions 
 * this involves simple character matching on strings in dp 
 * recurrence f(i, j) = max value of S(C, D) ending at index i and j 
 * for each recurrence step we have 4 possible options 
 * 
 * if ith and jth char match of the two strings then LCS new_len = old_len + 1
 * but the substring len also increases by 1 so overall a +2 in this case 
 * or either increase the ith or jth pointer and do a -1 for this case as the substring 
 * length increases or stop at this point and start a new substring completely
 */

int n, m;

int f(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
	// base case: either of string ended => nothing to compare 
	if(i == n || j == m) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	// start new substrings from the next case
	int res = 0;

	// update the either of the string ptrs
	res = max({res, -1 + f(i+1, j, a, b, dp), -1 + f(i, j+1, a, b, dp)});

	// if chars match then update the lcs val 
	if(a[i] == b[j]) {
		res = max(res, 2 + f(i+1, j+1, a, b, dp));
	}

	return dp[i][j] = res;
}

void solve() {
	cin >> n >> m;

	string a, b;
	cin >> a >> b;

	vector<vector<int>> dp(n, vector<int>(m, -1));

	int result = 0;
	// consider all cases where we start the string at all possible (i, j)
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			result = max(result, f(i, j, a, b, dp));
		}
	}

	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}