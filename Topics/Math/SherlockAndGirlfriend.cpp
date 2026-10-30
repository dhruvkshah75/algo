// ================================= sieve algorithm ==========================================

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

// question link: https://codeforces.com/problemset/problem/776/B

/*
 * this is equivalent to identifying prime numbers and composite numbers 
 * each prime number can be coloured with 1 and composite number can 
 * be coloured with color 2 => so simple sieve algorithm to mark prime 
 */

const int MAXN = 1e6+10;
vector<bool> isPrime;

void sieve() {
	isPrime.assign(MAXN, true);

	for(int i = 2; i * i < MAXN; i++) {
		if(isPrime[i]) {
			// mark false for all multiples of i = prime 
			for(int j = i * i; j < MAXN; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve();

	int n;
	cin >> n;

	if(n <= 2) {
		// only two primes 2, 3
		cout << 1 << endl;
	}
	else {
		cout << 2 << endl;
	}

	for(int i = 2; i <= n+1; i++) {
		if(isPrime[i]) cout << 1 << " ";
		else cout << 2 << " ";
	}
	cout << endl;
}