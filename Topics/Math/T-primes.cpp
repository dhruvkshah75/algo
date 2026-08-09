
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/230/B

const int MAXN = 1e6+10;
vector<bool> isPrime;

void sieve() {
	isPrime[1] = false;
	isPrime[0] = false;

	for(int i = 2; i * i < MAXN; i++) {
		if(isPrime[i]) {
			// mark all the multiples of i as false
			for(int j = i * i; j < MAXN; j += i) 
				isPrime[j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// precompute all the primes 
	isPrime.resize(MAXN, true);
	sieve();

	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		ll x;
		cin >> x;

		ll y = (ll)sqrt(x);
		if(y * y == x && isPrime[y]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}