// ==================================== partition dp ===================================

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

// question link: https://codeforces.com/contest/1132/problem/F

/*
 * This question is based on partition
 * so let i, j be used to denote the block of the string under consideration 
 * and we create partition when s[i] == s[k]
 * 
 * choice 1: delete the current element in 1 => 1 + f(i+1, j)
 * choice 2: now delete all the middle elements to make s[i] and s[k]
 * adjacent to each other and s[i] == s[k]
 * so the recursive calls made are f(i+1, k-1) + f(k, j) 
 */

const int MAXN = 5e2+10;
int dp[MAXN][MAXN];

int f(int i, int j, string &s) {
	// base case: invalid interval no characters to delete 
	if(i > j) return 0;

	// base case: single element so delete it 
	if(i == j) return 1;

	if(dp[i][j] != -1) return dp[i][j];

	// choice 1: delete the single character at s[i]
	int res = 1 + f(i+1, j, s);

	// choice 2: try all partitions such that s[i] == s[k]
	for(int k = i+1; k <= j; k++) {
		if(s[i] == s[k]) {
			res = min(res, f(i+1, k-1, s) + f(k, j, s));
		}
	}

	return dp[i][j] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string str;
	cin >> str;

	memset(dp, -1, sizeof(dp));

	int ans = f(0, n-1, str);
	cout << ans << endl;
}