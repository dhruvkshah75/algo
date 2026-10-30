// ================================== priority queue + sortings ================================

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

	vector<vector<int>> v;
	for(int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		v.push_back({l, r, i});
	}

	sort(v.begin(), v.end(), [&](const vector<int> &a, const vector<int> &b) {
		// sort the segments based on the start val 
		if(a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});

	print(v);

	// max heap to store the biggest index at the top
	// for all cases l_prev <= l_curr we just need r_prev >= r_curr => max heap to store the largest r_prev
	priority_queue<pii> pq;

	for(int i = 0; i < n; i++) {
		int l = v[i][0], r = v[i][1], ind = v[i][2];

		if(!pq.empty()) {
			auto [end, idx] = pq.top();
			// current segment is overlapping with pq.top segment
			if(r <= end) {  
				cout << ind+1 << " " << idx+1 << endl;
				return;
			}
		}
		pq.push({r, ind});
	}

	cout << -1 << " " << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}