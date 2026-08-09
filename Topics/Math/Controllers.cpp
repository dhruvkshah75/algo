// =============================================== math ===========================================

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

// question link: https://codeforces.com/problemset/problem/1776/L

/**
 * we dont care in what order do the plus and minus appear
 * so store the freq of plus and minus 
 * 
 * p = number of plus in s
 * m = number of minus in s
 * 
 * let x = number of plus taken with a
 * y = number of minus taken with b
 * note: 0 <= x <= p and 0 <= y <= m
 * 
 * The formula turns out to be 
 * (x-y)a + ((p-x) - (m-y))b = 0
 * (x-y)(a-b) = -(p-m)b
 * let k = x-y for simplicity
 * k = -(p-m)b / a-b => condition 1 is that this division must be exact 
 * 
 * 2nd condition is -m <= x-y <= p
 * so k mist lie in this segment [-m, p]
 * Each query can be answered in O(1)
 **/

void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int p = 0, m = 0;
	for(char c: s) {
		if(c == '+') p++;
		else m++;
	}

	// answer the queries in O(1)
	int q;
	cin >> q;

	while(q--) {
		ll a, b;
		cin >> a >> b;

		// if p == m => no matter the value of a,b we could always get 0 
		if(p == m) {
			yes; continue;
		}

		// if both buttons are the same => special case but here p != m then no 
		if(a == b) {
			no; continue;
		}

		// k = x-y and k*(a-b) = -(p-m)*b
		ll numer = -(p-m)*b;
		ll denom = (a-b);

		if(numer % denom != 0) {
			no; continue;
		}

		// check the 2nd condition 
		ll k = numer / denom;
		if(k >= -m && k <= p) {
			yes;
		}
		else {
			no;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}