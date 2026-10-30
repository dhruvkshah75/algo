
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)

template <typename T>
void printVec(const vector<T>& v) {
    for(const auto &x: v) cout << x << " ";
    cout << endl;
}

template <typename T> 
void print(const T& x) { cerr << x; }

template <typename A, typename B>
void print(const pair<A, B> &p) {
    cerr << "{"; print(p.first); cerr << " ";
    print(p.second); cerr << "}";

}

template <typename T>
void print(const vector<T> &v) {
    cerr << "[";
    for(const auto &x: v) {
        print(x); cerr << " ";
    }
    cerr << "]" << endl;
}

/**
 * let one character be a and the other character be b
 * then we want a sequence of the type [aa...a][bb....b][aa....a]
 * since it is a subsequence we can use prefix and suffix arrays to get the count
 * 
 * prefix[i][c] = count of c in prefix[0....i]
 * suffix[i][c] = count of c in suffix[i....n-1] 
 * we can use prefix and suffix to obtain the first and the third segment
 * and for the middle segment we can get the count using prefix itself
 * 
 * start the ans with the case when left and right segment doesnt exist 
 * only middle exists
 **/

void solve(void) {
	int n; cin >> n;

	vector<int> A(n);
	for(int &a: A) cin >> a;

	vector<vector<int>> pref(n+1, vector<int>(27, 0)), suf(n+2, vector<int>(27, 0));
	// pref[i][c] = count of c in prefix[0...i]

	for(int i = 0; i < n; i++) {
		pref[i+1] = pref[i];
		pref[i+1][A[i]]++;
	}

	for(int i = n-1; i >= 0; i--) {
		suf[i] = suf[i+1];
		suf[i][A[i]]++;
	}

	int ans = *max_element(pref[n-1].begin(), pref[n-1].end());

	// try out all segments of [l..r] which is the middle segment
	for(int l = 0; l <= n; l++) {
		for(int r = l; r <= n; r++) {

			int outer = 0, mid = 0;
			for(int c = 1; c <= 26; c++) {
				outer = max(outer, min(pref[l][c], suf[r][c]));
				mid = max(mid, pref[r][c] - pref[l][c]);
			}

			ans = max(ans, 2*outer + mid);
		}
	}
	
	cout << ans << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}