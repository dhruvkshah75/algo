// ================================================ math + number theory ==================================================

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

// question link: https://codeforces.com/problemset/problem/1881/D

/**
 * The most important trick that seems here is 
 * assume that all the number are converted into y
 * so a1 * a2 * a3 * .... * an = y ^ n
 * so the product of all the numbers must be divisible by n 
 * 
 * To check this get the multiplicities of all the prime factors 
 * for all ai 
 * 
 * precompute the spf (smallest prime factor) in O(N*LogLogN)
 **/

const int MAXN = 1e6+1;

vector<int> spf;

void sieve() {
	spf.resize(MAXN);
	iota(spf.begin(), spf.end(), 0);
	
	for(int i = 2; i * i < MAXN; i++) {
		if(spf[i] == i) {
			// mark out all the multiples of i where i is prime 
			for(int j = i * i; j < MAXN; j += i) {
				if(spf[j] == j) spf[j] = i;
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	unordered_map<int,int> mp;
	// store the multiplicity of all the primes in the map 

	for(int i = 0; i < n; i++) {
		int num = arr[i];

		while(num > 1) {
			int p = spf[num];
			mp[p]++;
			num /= p;
		}
	} 

	for(auto [prime, cnt]: mp) {
		if(cnt % n != 0) {
			no;
			return;
		}
	}

	// print yes when all the multiplicities of all prime factors are multiple of n
	// i.e. a1 * a2 * a3 * ...... * an = y ^ n 
	yes;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// precompute all the spf
	sieve();

	int t;
	cin >> t;
	while(t--) 
		solve();
}