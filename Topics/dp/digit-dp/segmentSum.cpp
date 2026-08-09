// =========================================== digit + bitmask dp =================================================

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

const int MOD = 998244353;

// question link: https://codeforces.com/contest/1073/problem/E

/**
 * here we need to form numbers with at most k different digits 
 * so simply use bitmask for considering the number of k different digits 
 * now how to deal with the part of getting the sum of all such numbers 
 * 
 * f(ind, tight, started, mask)
 * if digit x is placed at ind then the number added will be x * 10 ^ (len-ind+1) 
 * but this cannot be stored as a state so how to get the sum correclty 
 * if we know how many number of valid possible numbers are there after [ind+1...]
 * then next_count * digit * 10 ^ (len-ind+1)
 **/

struct Node {
	ll cnt;
	ll sum;
};


Node dp[19][2][2][1024];
bool vis[19][2][2][1024];

int k;
ll power10[19];

Node f(int pos, int tight, int started, int mask, string &num) {
	// base case: reached the last position 
	if(pos == num.length()) {
		// return the count and sum for the base case
		return {started, 0};
	}

	if(vis[pos][tight][started][mask]) return dp[pos][tight][started][mask];

	// mark this one visited state 
	vis[pos][tight][started][mask] = true;

	int remaining = num.length() - pos - 1;
	int limit = (tight) ? num[pos]-'0' : 9;
	ll total_sum = 0, total_cnt = 0;

	if(!started) {
		// dont start the number yet
		Node next = f(pos+1, 0, 0, 0, num);
		total_sum = (total_sum + next.sum) % MOD;
		total_cnt = (total_cnt + next.cnt) % MOD;

		// start the number placing any number [1..limit]
		for(int d = 1; d <= limit; d++) {
			int new_mask = mask | (1 << d);
			int new_tight = tight && (d == num[pos]-'0');

			Node next = f(pos+1, new_tight, 1, new_mask, num);
			total_sum = (total_sum + next.sum + (next.cnt * d % MOD) * power10[remaining] % MOD) % MOD;
			total_cnt = (total_cnt + next.cnt) % MOD;
		}
	}
	else {
		// number is already started so we must also deal with the mask 
		for(int d = 0; d <= limit; d++) {
			int new_mask = mask | (1 << d);
			int new_tight = tight && (d == num[pos]-'0');
			int new_distinct = setbits(new_mask);

			// skip the numbers with more than k distinct digits
			if(new_distinct > k) continue;

			Node next = f(pos+1, new_tight, started, new_mask, num);
			total_sum = (total_sum + next.sum + (next.cnt * d % MOD) * power10[remaining] % MOD) % MOD;
			total_cnt = (total_cnt + next.cnt) % MOD;
		} 
	}

	return dp[pos][tight][started][mask] = {total_cnt, total_sum};
}


ll calc(ll x) {
	if(x == 0) return 0;

	string num = std::to_string(x);

	memset(vis, false, sizeof(vis));

	return f(0, 1, 0, 0, num).sum;
}

void solve() {
	ll l, r;
	cin >> l >> r >> k;

	power10[0] = 1;
	for(int i = 1; i <= 18; i++) 
		power10[i] = power10[i-1]*10 % MOD;

	ll resultR = calc(r);
	ll resultL = calc(l-1);

	// the final ans will the total sum of f(r) - f(l-1)
	int ans = (resultR - resultL + MOD) % MOD;
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}