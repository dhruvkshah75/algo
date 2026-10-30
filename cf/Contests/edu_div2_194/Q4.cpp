
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

// question link: https://codeforces.com/contest/2260/problem/C

/*
 * we get the max xor when the x = 0 and y = y + x 
 * so the xor is essentially y + x
 * now this takes x ops to get => but there might be a case when we get the xor 
 * as y + x with less number of ops right 
 * so the logic is break z = y + x => into two number a and b 
 * such that a <= x and b >= y ==> only satisfying a <= x the other one follows
 * 
 * we need to maximise a how to do that => take the number z and split the number a
 * such that a <= x and this is the max case => so at each step if the ith bit is set 
 * in z then try to set that bit in the number we choose and then if <= x then update 
 * the a => in this way in O(30) we get the max XOR in min OPs  
 */

void solve() {
	int x, y;
	cin >> x >> y;

	// the best xor case would be when y becomes y + x and xor => (y + x) ^ 0 = y+x
	cout << x + y << " ";

	// there can be cases when the xor actually becomes x+y with less ops  
	int z = x + y;
	int a = 0;

	for(int bit = 29; bit >= 0; bit--) {
		if((z >> bit) & 1) {
			int candidate = a | (1 << bit);

			if(candidate <= x) {
				a = candidate;
			}
		}
	}

	int mn_ops = x - a;
	cout << mn_ops << endl;
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