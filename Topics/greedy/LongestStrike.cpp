
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
 * use simple two pointers to get the valid window 
 * and when we cannot expand further on the right then move the left pointer 
 * out of the window to begin a new window 
 * */

void solve() {
	int n, k;
	cin >> n >> k;

	map<int,int> freq;
	vector<int> A;
	// A stores the non duplicate sorted elements in the array

	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		freq[x]++;
	}

	for(auto [x, cnt]: freq) A.push_back(x);
	
	int sz = A.size();
	
	pii ans = {-1, -1};
	int l = 0, mx = -1, prev = -1;
	// prev = -1 indicates that the segment has not started

	for(int r = 0; r < sz; r++) {
		// if freq < k then A[r] cannot be included in the seg
		if(freq[A[r]] < k) {
			l = r+1;
			prev = -1;
			continue;
		}

		// if the consecutive seq breaks then start a new segment from r as its freq >= k
		if(prev != -1 && A[r] != prev+1) l = r;
		
		prev = A[r];

		if(r-l > mx) {
			mx = r-l;
			ans = {A[l], A[r]};
		}
	}
	
	if(ans.first == -1) cout << -1 << endl;
	else cout << ans.first << " " << ans.second << endl;
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