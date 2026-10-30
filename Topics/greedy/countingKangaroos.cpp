
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
	int n;
	cin >> n;

	vector<int> A(n);
	for(int &a: A) cin >> a;

	sort(A.begin(), A.end());

	// at max first n/2 elements can be paired
	// i is the matched pairs 
	int i = 0;

	for(int j = n/2; j < n && i < n/2; j++) {
		if(A[j] >= 2 * A[i]) i++;
	}

	cout << n - i << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}