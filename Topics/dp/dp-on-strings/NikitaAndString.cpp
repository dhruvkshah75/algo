// ================================= dp on strings + multi state ======================================

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

// question link: https://codeforces.com/contest/877/problem/B

/**
 * translate the question to minimum deletions to get the final string 
 * we must split the string into 3 parts 
 * so we must use one state for denoting currently in which part of the string 
 * .....|.......|......
 *    0     1       2 
 * we must match characters to a in when state = 0 or either start with segment 1 
 * and then match with character b and so on => each segment can be empty also 
 * */

const int MAXN = 5e3+10;
int dp[MAXN][3];

int f(int ind, int state, string &str) {
	// base case: exhausted the entire string 
	if(ind == str.length()) return 0;

	if(dp[ind][state] != -1) return dp[ind][state];

	int res = 1e8;
	if(state == 0) {
		// match the characters with a or start the new segment 
		res = min(res, f(ind, 1, str));

		int cost = (str[ind] == 'b') ? 1 : 0;
		res = min(res, cost + f(ind+1, state, str));
	}
	else if(state == 1) {
		// match the chars with b or start the nxt segment 
		res = min(res, f(ind, 2, str));

		int cost = (str[ind] == 'a') ? 1 : 0;
		res = min(res, cost + f(ind+1, state, str));
	}
	else {
		// match the chars with a => last segment so cannot start anything new 
		int cost = (str[ind] == 'b') ? 1 : 0;
		res = min(res, cost + f(ind+1, state, str));
	}

	return dp[ind][state] = res;
}

void solve() {
	string str;
	cin >> str;

	int n = str.length();

	memset(dp, -1, sizeof(dp));

	int min_ops = f(0, 0, str);
	cout << n - min_ops << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}