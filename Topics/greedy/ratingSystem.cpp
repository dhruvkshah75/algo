
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
 * this questions logic is pretty amazing => based on Kadanes algorithm
 * we want to set a lower bound k below which the result wont fall 
 * so we essentially are trying to find a segment with the most negative sum value 
 * drop the sum when it becomes positive => start a new segment 
 **/

void solve() {
	int n; cin >> n;

	vector<int64_t> A(n);
	for(auto &a: A) cin >> a;

	int64_t curr = 0, best = 0;
	int temp = 0, start_ind = 0;

	for(int i = 0; i < n; i++) {
		// start a new segment if sum becomes pos
		if(curr > 0) {
			curr = 0;
			temp = i;
		}

		curr += A[i];

		// found a better segment so store the start_index
		if(curr < best) {
			best = curr;
			start_ind = temp;
		}
	}

	int64_t ans = 0;
	for(int i = 0; i < start_ind; i++) ans += A[i];

	cout << ans << endl;
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