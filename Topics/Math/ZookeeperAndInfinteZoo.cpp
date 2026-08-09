// ============================ constructive algo + bitmasks ======================================

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

// question link: https://codeforces.com/problemset/problem/1491/D

/*
 * Very Important Logic for this question 
 * how is the conversion from u to v happening we move the bits from right to left (towards MSB)
 * from u to v => number of set bits can never increase 
 * condition 1: setbits(u) >= setbits(v)
 * 
 * and since we do u + v so we can never go from bigger value vertex to smaller one 
 * condition 2: v >= u 
 *
 * this is not enough for saying that we can reach from u to v 
 * the other point is when we cnt the set bits from lsb to msb 
 * at no point the cnt_of_setbits_V > cnt_of_setbits_U => cant go from u to v
 */

void solve() {
	int u, v;
	cin >> u >> v;

	if(u > v || setbits(u) < setbits(v)) {
		no;
		return;
	}	

	int cntU = 0, cntV = 0;
	for(int i = 0; i < 30; i++) {
		// check the ith bit is set or not 
		int bit_u = u & (1 << i);
		int bit_v = v & (1 << i);

		if(bit_u) cntU++;
		if(bit_v) cntV++;

		if(cntV > cntU) {
			no; return;
		}
	}

	yes;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;
	while(q--) {
		solve();
	}
}