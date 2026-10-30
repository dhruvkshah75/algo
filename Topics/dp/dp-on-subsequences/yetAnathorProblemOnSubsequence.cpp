
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

/**
 * n <= 1e3 
 * we want to count the number of subsequences => at each step consider the 
 * first element as the length of the subsequence if A[ind] is positive
 * 
 * we have multiple choices at each step 
 * skip the current element and move to the next element 
 * also skip the cur element if it is negative
 * also have a choice to stop the sequence at this index if it contains at least 1 element
 * 
 * Subarray must contain len+1 elements including len = A[ind] 
 * end and start elements are fixed => len-1 elements to be selected among j-ind-2 choices 
 * nCk where n = j-ind-2 and k = len-1
 **/

const int MOD = 998244353;

void solve() {
	int n; cin >> n;

	vector<int> A(n);
	for(int &a: A) cin >> a;

	vector<vector<int64_t>> C(n+1, vector<int64_t>(n+1, 0));
	C[0][0] = 1;
	// nCk
	
	for(int i = 1; i <= n; i++) {
		C[i][0] = 1;
		for(int k = 1; k <= n; k++) {
			C[i][k] = (C[i-1][k-1] + C[i-1][k]) % MOD;
		}
	}
	
	vector<vector<int>> dp(n, vector<int>(2, -1));
	// dp[i][flag] = cound of such good subsequences [i+1...n-1] 

	auto f = [&](auto &&self, int ind, int flag) -> int {
		// exhausted the array nothing to consider 
		if(ind == n) return flag;

		if(dp[ind][flag] != -1) return dp[ind][flag];

		int64_t res = 0;
		// choice 1: skip the current element 
		res = (res + self(self, ind+1, flag)) % MOD;

		// choice 2: take the current element as the len 
		int len = A[ind];

		if(len > 0 && ind+len < n) {
			// try out all possible ends and choose len elements in it 
			for(int j = ind+len+1; j <= n; j++) {
				int64_t ways = C[j - ind - 2][len - 1];
				res = (res + ways * self(self, j, 1)) % MOD;
			}
		}

		return dp[ind][flag] = res % MOD;
	};

	int result = f(f, 0, 0);
	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}