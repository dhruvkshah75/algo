// =========================================== greedy + bitmasks =====================================================

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

// question link: https://codeforces.com/problemset/problem/1362/C

/**
 * unfairness is the sum of diff of bits in consective integers from 1 to n
 * 
 * for any number n
 * 0th bit flips for n times => alternates every 1 step 
 * 1th bit flisp for n / 2 times => alternatives every 2 steps  
 * and so on 
 * 
 * the final result = total unfairness is sum(n / 2 ^ i) for all i 
 * n <= 1e18 => so number of max bits for consideration will 60
 **/
	
void solve() {
	ll n;
	cin >> n;

	ull res = 0;
	for(int i = 0; i <= 60; i++) {
		// stop if the number becomes 0 
		ll div = (1LL << i);
		if(n / div == 0) break;
		res += n / div;
	}
	// O(60) for each test case 

	cout << res << endl;
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