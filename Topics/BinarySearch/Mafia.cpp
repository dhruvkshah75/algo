
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
 * every player wants to play ai rounds as a player, but every round must have a supervisor in the game
 * suppose X total rounds are played => for each person X >= ai + si (si = rounds the player acts as the supervisor)
 * we want to minimise this value of X
 * simply for each case calculate how many rounds a person can supervise i.e. cnt = X - ai
 * if the sum of this >= X then we can conduct X rounds correctly 
 */

void solve() {
	int n;
	cin >> n;

	vector<int> A(n);
	int mx = 0;

	for(int i = 0; i < n; i++) {
		cin >> A[i];
		mx = max(mx, A[i]);
	}

	auto isPossible = [&](int64_t X) -> bool {
		// return true when X rounds can be validly conducted 
		int64_t sum = 0;
		for(int i = 0; i < n; i++) {
			sum += X - A[i];
		}

		return sum >= X;
	};

	int64_t low = mx, high = 2LL * mx, res = -1;

	while(low <= high) {
		int64_t mid = low + (high - low) / 2;

		if(isPossible(mid)) {
			res = mid;
			high = mid-1;
		}
		else low = mid+1;
	}

	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}