// ========================= precomputation dp ===================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

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
    cerr << "[ ";
    for(const auto &x: v) {
        print(x); cerr << " ";
    }
    cerr << " ]" << endl;
}


string str;
vector<vector<int>> dp;

bool f(int l, int r) {
	// if segment becomes invalid 
	if(l > r) return 1;
	if(l == r) return dp[l][r] = 1;

	if(dp[l][r] != -1) return dp[l][r];

	// dp is 1 based indexing while str is 0 based 
	if(str[l-1] == str[r-1]) {
		return dp[l][r] = f(l+1, r-1);
	}
	else {
		return dp[l][r] = 0;
	}
}

void solve() {
	cin >> str;
	int n = str.length();

	dp.assign(n+1, vector<int>(n+1, -1));

	for(int l = 1; l <= n; l++) {
		for(int r = l; r <= n; r++) {
			f(l, r);
		}
	}

	// make a prefix sum for the dp array to get the number of palindromes in [l..r]
	vector<vector<int>> prefix(n+1, vector<int>(n+1, 0));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			// prevent adding up -1 in the sum
			int add = (dp[i][j] == -1) ? 0 : dp[i][j];
			prefix[i][j] = add + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
		}
	}

	int q;
	cin >> q;

	while(q--) {
		int l, r;
		cin >> l >> r;

		// get the prefix sum of the box l..r
		int res = prefix[r][r] - prefix[r][l-1] - prefix[l-1][r] + prefix[l-1][l-1];
		cout << res << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}