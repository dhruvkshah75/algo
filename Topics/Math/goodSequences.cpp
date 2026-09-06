// ================================= dp + number theory + sieve ====================================

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

// question link: https://codeforces.com/problemset/problem/264/B

/*
 * very important dp question with a very important trick to solve the question 
 * use dp with lis style 
 * dp[i] = length of the longest sequence ending at the ith index 
 * dp[i] = 1 + max(valid dp[j])
 * we want the prev element to have gcd > 1 => so consider prime factors of the current num
 * and maintain a best array to store the best length with a number having this prime factor
 * best[p] = length of longets sequence ending in a number with prime factor p
 * so simply just run through all distinct prime factors of the number 
 * O(N * Log(N))
 */

const int MAXN = 1e5+1;
vector<int> spf;

void sieve() {
	spf.resize(MAXN);
	iota(spf.begin(), spf.end(), 0);
	// spf[i] = i

	for(int i = 2; i * i < MAXN; i++) {
		if(spf[i] == i) {
			// i is a prime number so mark all its mul with spf 
			for(int j = i * i; j < MAXN; j += i) {
				if(spf[j] == j) spf[j] = i;
			}
		}
	}
}

vector<int> prime_factors(int n) {
	vector<int> res;

	while(n > 1) {
		int p = spf[n];
		res.push_back(p);

		while(n % p == 0) n /= p;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	vector<int> dp(n, 1);
	// dp[i] = length of longest good sequence ending in arr[i]
	vector<int> best(MAXN, 0);
	// best[p] = length of longest good sequence ending in a number with prime factor p

	int result = 1;

	for(int i = 0; i < n; i++) {
		// calculate the val of dp[i]
		int num = arr[i];
		vector<int> pf = prime_factors(num);

		for(int p: pf) dp[i] = max(dp[i], 1 + best[p]);
		
		// update the value of best for all prime factors 
		for(int p: pf) best[p] = max(best[p], dp[i]);
		
		result = max(result, dp[i]);
	}

	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve();

	solve();
}