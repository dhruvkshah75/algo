// =========================== constructive algo + math ===============================

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

// question link: https://codeforces.com/problemset/problem/1352/B

void solve() {
	int n, k;
	cin >> n >> k;

	// not possible case 
	if(k > n) {
		no;
		return;
	}

	// handle all cases of odd and even of n and k 
	if(n & 1) {
		if(k & 1) {
			// n = odd and k = odd so print 1s k-1 times and one other number 
			yes;

			cout << n-k+1 << " ";
			for(int i = 0; i < k-1; i++) 
				cout << 1 << " ";
			cout << endl;
		}
		else {
			// n = odd and k = even => not possible cannot express 
			no;
			return;
		}
	}
	else {
		if(k & 1) {
			// n = even and k = odd => sum(all ai) = even when all ai are even 
			if(2 * k > n) {
				no;
				return;
			}

			yes;
			cout << n - 2 * (k - 1) << " ";
			for(int i = 0; i < k-1; i++)
				cout << 2 << " ";
			cout << endl;
		}
		else {
			// n = even and k = even => print 1s k-1 times 
			yes;
			cout << n-k+1 << " ";
			for(int i = 0; i < k-1; i++)
			    cout << 1 << " ";
		}
	}
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