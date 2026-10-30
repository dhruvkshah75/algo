
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
 * every painter must paint some plank => first we can make a check of it all needed paints 
 * are provided by the painters or not 
 * then for the painting to be valid the last painter must paint the ai to bi correctly 
 * 
 * needy plank are those => A[i] != B[i] so store them need[color] store all the plank indices
 * */

void solve() {
	int n, m; cin >> n >> m;
	// n = number of planks, m = number of painters 

	vector<int> A(n), B(n), C(m);

	for(int &x: A) cin >> x;
	for(int &x: B) cin >> x;
	for(int &x: C) cin >> x;

	// need[color] = store the needy planks marked by their color
	// anyB[color] = any one plank that needs to be painted to color
	vector<vector<int>> need(n+1);
	vector<int> anyB(n+1, -1);

	for(int i = 0; i < n; i++) {
		anyB[B[i]] = i;
		if(A[i] != B[i]) need[B[i]].push_back(i);
	}

	// first try to paint the last painter
	int L;
	if(!need[C[m-1]].empty()) {
		// assign any one plank to the last painter
		L = need[C[m-1]].back();
		need[C[m-1]].pop_back();
	}
	else if(anyB[C[m-1]] != -1) {
		L = anyB[C[m-1]];
	}
	else {
		no;
		return;
	}

	// no assign some fence to painters 0 to m-2
	vector<int> res(m);
	res[m-1] = L;

	for(int j = 0; j < m-1; j++) {
		int color = C[j];

		if(!need[color].empty()) {
			// color one needy plank
			res[j] = need[color].back();
			need[color].pop_back();
		}
		else {
			// color does not have any needy plank => then color L which will be overwritten
			res[j] = L;
		}
	}

	bool ok = true;
	for(int color = 1; color <= n; color++) {
		if(!need[color].empty()) { ok = false; break; }
	}

	if(ok) {
		yes;
		for(int j = 0; j < m; j++) cout << res[j]+1 << " ";
		cout << endl;
	}
	else {
		no;
	}
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