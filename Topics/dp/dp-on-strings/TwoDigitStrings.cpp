// ======================================= dp on strings ===========================================

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

// question link: https://codeforces.com/contest/2242/problem/D

/**
 * we have to merge the digits such that d1 + d2 mod 10 remains 
 * so first of all store the prefix sum of the arrays which stores the prefix sum % 10
 * now we merge sections until sum matches 
 * 
 * eg: a = 5147 and b = 44441 
 * prefixA = [5, 6, 0, 7]
 * prefixB = [4, 8, 2, 6, 7]
 * we merge segments [5, 6] and [4, 8, 6] into a single digit with value 6 
 * as it matches we can now search for the next segments => [0, 7] and [7] 
 * with digit value = 7 
 * 
 * this is exactly the same as getting the LCS => longest common subsequence of prefixA 
 * and prefixB => hidden LCS variant
 **/

int n1, n2;
vector<int> prefixA, prefixB;
vector<vector<int>> dp;

int lcs(int i, int j) {
	// base case: either of the string is finished 
	if(i == n1 || j == n2) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int res = 0;
	if(prefixA[i] == prefixB[j]) {
		// characters matched so add 1 and move to nxt for both
		res = 1 + lcs(i+1, j+1);
	}
	else {
		// current chars dont match => either skip i or skip j
		res = max(lcs(i, j+1), lcs(i+1, j));
	}

	return dp[i][j] = res;
}


void solve() {
	string a, b;
	cin >> a >> b;

	n1 = a.length();
	n2 = b.length();

	prefixA.assign(n1, 0);
	prefixA[0] = a[0]-'0';
	for(int i = 1; i < n1; i++) 
		prefixA[i] = (prefixA[i-1] + a[i] - '0') % 10;

	prefixB.assign(n2, 0);
	prefixB[0] = b[0]-'0';
	for(int j = 1; j < n2; j++) 
		prefixB[j] = (prefixB[j-1] + b[j] - '0') % 10;

	// base case: when both strings have no matching characters => invalic case 
	// total sum of string a = total sum of string b => we are just adding the numbers 
	if(prefixA[n1-1] != prefixB[n2-1]) {
		cout << -1 << endl;
		return;
	}

	dp.assign(n1, vector<int>(n2, -1));

	// len of the lcs is 0 means no common sequence 
	int longest = lcs(0, 0);
	cout << longest << endl;
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