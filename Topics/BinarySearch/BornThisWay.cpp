
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

// question link: https://codeforces.com/problemset/problem/1148/B

/*
 * consider trying all flights starting from i = 0 
 * note that when i = 3 is considered => we must cancel i = 0, 1, 2
 * so we cancel i flights and then only the i th flight can be considered 
 * 
 * now if arkady takes the ith flight then he reaches B at a[i] + ta
 * so he can board the flight at time b[j] >= a[i] + ta
 * so try to cancel most flights starting from j till the cancels that we are left with 
 * and the flight that he is allowed to take will be say x then time at which 
 * he reaches C is b[x] + tb
 */

void solve() {
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;

	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	vector<int> b(m);
	for(int j = 0; j < m; j++) cin >> b[j];

	// if we can cancel all n or all m flights 
	if(k >= n || k >= m) {
		cout << -1 << endl;
		return;
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		// we must cancel the prev i flights to reach here 
		int cancels_left = k - i;
		if(cancels_left < 0) break;

		int timeB = a[i] + ta;
		auto it = lower_bound(b.begin(), b.end(), timeB);
		int idx = distance(b.begin(), it);

		// cancel the flights with the cancels that we have left with 
		int nxt = idx + cancels_left;
		if(nxt >= m) {  // no flight left 
			ans = -1;
			break;
		}  

		int timeC = b[nxt] + tb;
		ans = max(ans, timeC);
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}