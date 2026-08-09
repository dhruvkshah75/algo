// =========================================== bitmasks ===========================================

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

// question link: https://codeforces.com/problemset/problem/912/B

void solve() {
	ll n, k;
	cin >> n >> k;

	if(k == 1) {	
		// directly take n
		cout << n << endl;
		return;
	}

	// when k >= 2 then we can use any 2 numbers to get all the bits of the number set 
	// get the msb set bit of x 
	int x = 0;
	while(n > 0) {
		x++;
		n = (n >> 1);
	}
	x--; 

	// set all the bits x, x-1, x-2, .... 0
	ll res = 0;
	while(x >= 0) {
		res = res | (1LL << x);
		x--;
	}

	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}