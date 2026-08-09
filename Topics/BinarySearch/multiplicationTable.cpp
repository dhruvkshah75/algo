// ======================================== binary search ================================================

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

// question link: https://codeforces.com/problemset/problem/448/D

/* use binary search on answer i.e. kth largest number 
 * apply a predicate function like => how many elements are there less than or equal to 
 * our guessed value x ? => x is the correct guess if there count(x) < k => x is too small 
 * count(x) >= k => x could be the answer but can also be large 
 * return true if there at least k elements <= x ==> keep this statement as fixed 
 * here predicate returns ...FFFFFTTTT.. => get the first True occurrence 
 */

bool predicateF(int r, int c, ll k, ll x) {
	// return true if there are >= k elements that are <= x
	if(c > r) swap(r, c);

	ll cnt = 0;
	for(int i = 1; i <= c; i++) {
		if(i > x) break;
		// row i has 2*i, 3*i, 4*i, ..., i*c
		// number of elements <= x in the row are floor(x/i) 
		cnt += min((ll)r, x/i);
	} 

	// return true when there are least k elements <= x
	return cnt >= k;
}

void solve() {
	int n, m;
	ll k;
	cin >> n >> m >> k;

	// binary search on answer 
	ll low = 1, high = n * 1LL * m;
	ll ans = -1;
	while(low <= high) {
		ll mid = low + (high - low) / 2;
		if(predicateF(n, m, k, mid)) {
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}