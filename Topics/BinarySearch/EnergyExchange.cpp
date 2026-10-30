// ========================= binary search on answer ==================================

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

/**
 * apply simple binary search on the answer i.e the maximum achievable same energy of each 
 * accumulator 
 * so for the predicate function we sent mid which is what all accumulators must have at the end 
 * so simply in one iteration calculate the surplus (if ai > mid => ai - mid) 
 * otherwise deficit = mid - ai 
 * at the end surplus >= defict * 100 / 100 - k => if this is true then only 
 * we can achieve the same value 
 * */
	
void solve() {
	int n, k;
	cin >> n >> k;

	int mx = -1;

	vector<int> A(n);
	for(int i = 0; i < n; i++) {
		cin >> A[i];
		mx = max(mx, A[i]);
	}

	auto possible = [&](double mid) -> bool {
		// surplus when the acummulator can give extra energy
		double surplus = 0.0, deficit = 0.0;

		for(int a: A) {
			if(a > mid) surplus += a - mid;
			else deficit += mid - a;
		}

		bool res = (surplus >= deficit * (100.0/(100.0 - k)));
		return res;
	};
	// predicate returns TTTTFFF

	double low = 0.0, high = static_cast<double>(mx);

	for(int i = 0; i < 100; i++) {
		double mid = (low + high) / 2.0;

		if(possible(mid)) low = mid;
		else high = mid;
	}

	// after 100 iterations of bs low / high stores the final result 
	cout << fixed << setprecision(10) << low << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}