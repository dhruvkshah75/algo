
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
 * we want the longest subseqeunce so that will be of the form 1,1.....1,2,2......2
 * of the form 1* 1* 2* 2* but the middle section is reversed 
 * so we want the sequence of the form 1* [2* 1*] 2* => [2* 1*] will be reversed 
 * we can calculate the max seq of 2*1* using dp
 **/

static int dp[2000][2000][2];

void solve() {
	int n; cin >> n;

	vector<int> A(n);
	for(int &a: A) cin >> a;

	vector<int> pref1(n+1, 0), pref2(n+1, 0);
	// pref1[i] = count of 1s in A[0...i-1] and pref2[i] = count of 2s in A[0...i-1]

	for(int i = 0; i < n; i++) {
		pref1[i+1] = pref1[i] + (A[i] == 1);
		pref2[i+1] = pref2[i] + (A[i] == 2);
	}

	memset(dp, -1, sizeof(dp));
	// dp[l][r][flag] => flag denotes to search for what number => 0 search for 2 and then search for 1

	auto f = [&](auto &&self, int l, int r, int flag) -> int {
		// base case: sequence to search is exhausted 
		if(l > r) return 0;

		if(dp[l][r][flag] != -1) return dp[l][r][flag];

		int count = 0;
		int to_find = (flag == 0) ? 2 : 1;

		// choice 1: flip the flag and then search for next
		if(flag == 0) count = max(count, self(self, l, r, 1));

		// choice 2: search for the required number
		count = max(count, (A[l] == to_find) + self(self, l+1, r, flag));

		return dp[l][r][flag] = count;
	};

	int ans = 0;

	for(int l = 0; l < n; l++) {
		for(int r = l; r < n; r++) {
			// get the best sequence on reversing [l...r]
			int middle = f(f, l, r, 0);
			int left = pref1[l];
			int right = pref2[n] - pref2[r+1];

			ans = max(ans, left + middle + right);
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}