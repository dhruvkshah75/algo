
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
	int n, m; 
	cin >> n >> m;

	vector<pii> A(n);
	// A[i] = {ai, original index}

	for(int i = 0; i < n; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.begin(), A.end());

	int curr_sum = 0, wins = 0;
	vector<int> score(n+1, 0);

	for(int i = 0; i < n; i++) {
		curr_sum += A[i].first;

		if(curr_sum <= m) {
			// i beat this player and this player beats i others 
			score[i] = A[i].second;
			wins++;
		}
		else {
			// this player beats me 
			score[i] = A[i].second + 1; 
		}
	}

	score[n] = wins;

	// sort the scores based on the descending order 
	sort(score.rbegin(), score.rend());

	int pos = 0, ind = 0;
	while(score[ind] > wins) {
		pos++;
		ind++;
	}

	cout << pos + 1 << endl;
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