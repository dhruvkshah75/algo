
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

/*
 * in each operation we can convert the nbg of the current element eqaul
 * this essentially is equal to converting equal blocks into the same element 
 * so with x moves we can convert x+1 elements into the minimum element 
 * 
 * subtle point = if there are x+1 elements converted to say some value = mn
 * and then if there are multiple elements with A[index] = mn
 * we dont have to handle this case as the recursion handles this case easily 
 * as we create multiple possiblities which gets the min value
 * 
 * time complexity = O(N * K * K)
 */

int n;
vector<int64_t> A;
vector<vector<int64_t>> dp;

int64_t f(int ind, int left) {
	// entire array processed
	if(ind == n) return 0;

	if(dp[ind][left] != -1) return dp[ind][left];

	int64_t ans = LLONG_MAX, mn = LLONG_MAX;

	// consider we do x operations so we can change x+1 block of elements 
	for(int x = 0; x <= left && x + ind < n; x++) {
		mn = min(mn, A[ind+x]);

		int64_t curr_block = mn * (x+1);
		int64_t rem = f(ind + x + 1, left - x);

		ans = min(ans, curr_block + rem);
	}

	return dp[ind][left] = ans;
}

void solve() {
	int k;
	cin >> n >> k;

	A.assign(n, 0);
	for(int i = 0; i < n; i++) cin >> A[i];

	dp.assign(n, vector<int64_t>(k+1, -1));

	int64_t result = f(0, k);
	cout << result << endl;
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