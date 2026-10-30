// ============================ dp + two pointers ============================

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

/*
 * the logic is very similar is dp to check palindromic substrings in O(N^2)
 * dp[l][r] here indicates the difference of value that u get when the subaray is reversed
 * of array a
 * so basicaaly we must get the ans for S + max dp[l][r] for all l and r 
 * where S is total value sum(ai * bi) 
 */

vector<int> A, B;
vector<vector<int64_t>> dp;

int64_t f(int l, int r) {
	// base case: when single element 
	if(l >= r) return 0;

	if(dp[l][r] != -1) return dp[l][r];

	int64_t factor = A[l]*1LL*B[r] + A[r]*1LL*B[l] - A[l]*1LL*B[l] - A[r]*1LL*B[r];
	return dp[l][r] = f(l+1, r-1) + factor;
}

void solve() {
	int n;
	cin >> n;

	A.resize(n); B.resize(n);
	int64_t S = 0;

	for(int i = 0; i < n; i++) cin >> A[i];

	for(int j = 0; j < n; j++) {
		cin >> B[j];
		S += A[j] * 1LL * B[j];
	}

	dp.resize(n, vector<int64_t>(n, -1));	

	int64_t maxi = S;
	for(int l = 0; l < n; l++) {
		for(int r = l+1; r < n; r++) {
			maxi = max(maxi, S + f(l, r));
		}
	}

	cout << maxi << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}