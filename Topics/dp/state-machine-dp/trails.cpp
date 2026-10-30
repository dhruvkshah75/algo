
#include<bits/stdc++.h>
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

const int MOD = 1e9+7;

void solve() {
	int n, m;
	cin >> m >> n;

	vector<int> s(m), l(m);
	for(int &x: s) cin >> x;
	for(int &x: l) cin >> x;

	vector<vector<int>> dp(n, vector<int>(m, -1));
	// dp[day][curr_cabin]
	
	auto f = [&](auto &&self, int day, int curr_cabin) -> int {
		// base case: all days exhausted
		if(day == n) return 1;

		if(dp[day][curr_cabin] != -1) return dp[day][curr_cabin];

		int64_t res = 0;
		int i = curr_cabin;

		for(int j = 0; j < m; j++) {
			int64_t ways = s[i]*s[j] + s[i]*l[j] + l[i]*s[j];
			res = (res + ways * self(self, day+1, j)) % MOD;
		}

		return dp[day][curr_cabin] = res % MOD;
	};

	// start from the cabin 1 i.e. 0th indexed cabin 
	int ans = f(f, 0, 0);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}