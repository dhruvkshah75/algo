
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

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> A(n);
	for(int &a: A) cin >> a;

	sort(A.begin(), A.end());
	// sort the array so that we can get the median

	auto isPossible = [&](int median) -> bool {
		// return true if we can achiece this median

		int64_t ops = 0;
		for(int i = n/2; i < n; i++) {
			if(median > A[i]) ops += median - A[i];

			if(ops > k) return false;
		}

		return true;
	};

	int curr_median = A[n/2];
	int low = curr_median, high = curr_median + k;
	int ans = curr_median;

	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(isPossible(mid)) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}