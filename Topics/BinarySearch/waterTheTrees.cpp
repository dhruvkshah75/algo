
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
 * simple intuition is apply binary search on answer i.e. number of days 
 * y number of days then if y is even then y/2 +1s and y/2 +2s
 * if y is odd => y/2+1 +1s and y/2 +2s that are allowed 
 * 
 * M = max(h[1], h[2], h[3], .... h[n])
 * the max height achievable is either M or M+1
 * 
 * so target = T => try to increase the height of each one to this val
 * d = T - h => number of 2s = d / 2 and needed 1s = d % 2
 * */


void solve() {
	int n; cin >> n;

	vector<int> h(n);
	for(int &x: h) cin >> x;

	int M = *max_element(h.begin(), h.end());

	auto check = [&](int64_t d, int T) -> bool {
		// return true if all trees can achieve T
		int64_t ones = (d + 1) / 2, twos = d / 2;

		int64_t mand_ones = 0, req_twos = 0;
		for(int x: h) {
			mand_ones += (T - x) % 2;
			req_twos += (T - x) / 2;
		}

		// if there are less ones than required 
		if(mand_ones > ones) return false;

		int64_t eff_twos = twos + (ones - mand_ones) / 2;

		return eff_twos >= req_twos;
	};

	int64_t low = 0, high = 2e14;
	int64_t ans = high;

	while(low <= high) {
		int64_t mid = low + (high - low) / 2;

		if(check(mid, M) || check(mid, M+1)) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}

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