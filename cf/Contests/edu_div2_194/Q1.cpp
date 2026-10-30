
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(x) cerr << " " << x << " ";
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)

void solve() {
	int n;
	cin >> n;

	int easy = 0;
	vector<int> arr(n);

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if(arr[i] == 0) easy++;
	}

	if(easy < 2) {
		cout << -1 << endl;
		return;
	}

	bool first = (arr[0] == 0);
	bool last = (arr[n-1] == 0);

	if(first && last) {
		cout << 0 << endl;
	}
	else if(first || last) {
		cout << 1 << endl;
	}
	else {
		cout << 2 << endl;
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