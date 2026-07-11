#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/1891/C

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());
	// sort the array for applying two pointers 

	int l = 0, r = n-1, ans = 0;

	while(l <= r) {
		int sum = 0;
		int j = l;
		while(j < r && sum + arr[j] <= arr[r]) {
			sum += arr[j];
			j++;
		}	

		ans += sum;
		r--;
		l = j;

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