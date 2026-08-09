// ======================================= grid dp ======================================

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

// question link: https://codeforces.com/problemset/problem/1829/G

const int MAXN = 2025;
const int MAX_VAL = 1e6+10;

ll dp[MAXN][MAXN];

ll f(int r, int c) {
	// base case: invalid cell reached 
	if(r <= 0 || c <= 0 || c > r) return 0;

	if(dp[r][c] != -1) return dp[r][c];

	// before the rth row there r-1 rows so 1+2+3+....+r-1 numbers 
	ll n = r*(r-1)/2 + c;
	ll value = n * n;

	// use inclusion and exclusion (subtract the common ancestors)
	return dp[r][c] = value + f(r-1, c-1) + f(r-1, c) - f(r-2, c-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	// run the recurrence for all the elements in the last row 
	int lastRow = 1;
	while(1LL * lastRow * (lastRow + 1) / 2 < MAX_VAL) lastRow++;
	
	// call the recurrence for last row elements 
	for(int col = 1; col <= lastRow; col++) {
		ll temp = f(lastRow, col);
	}

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		// find out which row is this number n a part of 
		int row = 1;
		while(1LL * row * (row + 1) / 2 < n) row++;

		// now get the column of this number 
		// formula = n = r(r-1)/2 + c
		int col = n - row * (row - 1) / 2;

		cout << dp[row][col] << endl;
	}
}