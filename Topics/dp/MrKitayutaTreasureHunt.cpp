// =================================================== dp + optimisation ===============================================

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

// question link: https://codeforces.com/contest/505/problem/C

/**
 * The brute force dp is where we need to use 2 states that is 
 * recurrence => f(pos, prev_jump) => this is not allowed as this solution will be O(N^2)
 * look at one thing the jumps made will have a bound on both sides 
 * upper bound => d + 1, d + 2, d + 3, d + 4 .... + d + x <= 30000
 * 1 + 2 + 3 + ... + x = x*(x+1)/2 <= 30000 => this results in a value of x = 245
 * here are only 491 values of j that we have to consider, which are d-245,d-244,d-243,...,d+244 and d+245.
 * 
 * min jump = d - 246 and max jump = d + 246 
 * simply add a offset to both of them to ensure that the state remains positive
 * roughly assume the prev jump as [d-250, d+250] 
 * 
 * keep the offset of 250 to make the indices in the positive range 
 * 
 **/

const int MAXN = 3e4+10;
const int OFFSET = 250;
int MAX_ISLAND;
vector<int> gems;
vector<vector<int>> dp;

int f(int pos, int prev_jump, int d) {
	// base case: offset out of bounds or pos out of bounds
	if(prev_jump < 0 || prev_jump >= 2*OFFSET || pos > MAX_ISLAND) return 0;
	
	if(dp[pos][prev_jump] != -1) return dp[pos][prev_jump];

	int res = 0; 	
	// extract the last actual jmp with offset
	int last_jmp = prev_jump + d - OFFSET;  

	for(int dx: {-1, 0, 1}) {
		int nxt_jmp = last_jmp + dx;
		if(nxt_jmp <= 0) continue;  // Jump must be positive

		int nxt_offset = nxt_jmp - d + OFFSET;
		if(nxt_offset < 0 || nxt_offset >= 2*OFFSET) continue;  // Check bounds

		res = max(res, gems[pos] + f(pos + nxt_jmp, nxt_offset, d));
	}

	return dp[pos][prev_jump] = res;
}
// O(N * sqrt(N))

void solve() {
	int n, d;
	cin >> n >> d;

	MAX_ISLAND = 0;

	dp.resize(MAXN, vector<int>(2*OFFSET, -1));
	gems.resize(MAXN, 0);

	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		gems[x]++;
		// mark that a gem is found at the location 
		MAX_ISLAND = max(MAX_ISLAND, x);
	}

	// starting from the island d with 
	int result = f(d, OFFSET, d); 
	cout << result << endl; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}