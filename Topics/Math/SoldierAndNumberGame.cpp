
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/546/D

/**
 * the number of rounds for x is the number of prime factors of n with multiplicity
 * omega(i) = number of prime factos of i with its multiplicity
 * Now we are given that the number is n = a!/b!
 * Cannot compute the factorials so number of prime factos with multiplicity is 
 * the sum of dp[i] = omega[i] + omega[i-1] + omega[i-2] + ..... => prefix sum of the omega table (dp table)
 * and the n is a!/b! the result would dp[a] - dp[b] 
 **/

const int MAXN = 5e6+1;
vector<int> spf(MAXN), omega(MAXN);
vector<ll> dp(MAXN);

void sieve() {
	// use sieve of eratosthenes to get the smallest prime factorization
	iota(spf.begin(), spf.end(), 0);

	spf[0] = 0;
	spf[1] = 1;

	for(int i = 2; i * i < MAXN; i++) {
		if(spf[i] == i) {
			// i is prime if spf[i] = i
			for(int j = i * i; j < MAXN; j += i) 
				if(spf[j] == j) spf[j] = i;
		}
	}
}
// O(N * Log(LogN))

void solve() {
	// precompute the omega = number of prime factors of all numbers with multiplicty 
	// recurrence = omega[i] = omega[i / spf[i]] + 1 
	omega[1] = 0;

	for(int i = 2; i < MAXN; i++) {
		omega[i] = omega[i / spf[i]] + 1;
	}
	// O(N)

	// precompute the number of prime factors with multiciplity of n!
	// recurrence => dp[i] = omega[i] + omega[i-1] + ..... => prefix sum
	dp[1] = omega[1];
 
	for(int i = 2; i < MAXN; i++) {
		dp[i] = dp[i-1] + omega[i];
	}

	int q;
	cin >> q;

	while(q--) {
		int a, b;
		cin >> a >> b;

		cout << dp[a] - dp[b] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// precompute the smallest prime factors of all the numbers 
	sieve();

	solve();
} 