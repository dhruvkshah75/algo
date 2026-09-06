// ====================================== prefix xor and maps =========================================

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

// question link: https://codeforces.com/problemset/problem/1109/A

/*
 * we want a segment [l..r] with even length such that 
 * a[l] ^ a[l+1] ^ ... ^ a[mid] = a[mid+1] ^ .... ^ a[r]
 * this is the equivalent to a[l] ^ a[l+1] ^ ..... ^ a[r] = 0
 * the xor of the entire segment is equal to 0 
 * so use prefixXOR array to calculate the xor 
 * so we need to get => prefixXOR[l-1] = prefixXOR[r]
 * 
 * Note we need the segment length to be even so we use two different maps 
 * one which stores the xors at even and odd indices 
 */

void solve() {
	int n;
	cin >> n;

	vector<int> prefix(n+1, 0);
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		prefix[i] = prefix[i-1] ^ x; 
	}

	ll ans = 0;
	map<int,int> odd_ind, even_ind;
	even_ind[0] = 1;
	// store the prefix[0] in the even map 

	for(int r = 1; r <= n; r++) {
		int curr = prefix[r];

		if(r & 1) {
			// odd map as r, l must be same parity but prefix of l-1 is stored in map
			if(odd_ind.find(curr) != odd_ind.end())
				ans += 1LL * odd_ind[curr];

			odd_ind[curr]++;
		}
		else {
			// search for curr in the even map as l-1 is stored in the map not l 
			if(even_ind.find(curr) != even_ind.end()) 
				ans += 1LL * even_ind[curr];

			even_ind[curr]++;
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}