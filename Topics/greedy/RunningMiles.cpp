// ============================================= prefix and suffix arrays ===========================================

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

// question link: https://codeforces.com/problemset/problem/1826/D

/*
 * Very Important question based on prefix and suffix arrays 
 * what to maximiise in the question 
 * arr[i] + arr[k] + arr[j] - (r-l)
 * so we take 3 max elements and then subtract the segment length in which they lie 
 * logically to mximise this the segment that we take should be such that 
 * we take the two endpoints of the segment 
 * 
 * arr[i] + arr[k] + arr[j] - (j - i);
 * this maximises the sum => (arr[i] + i) + arr[k] + (arr[j] - j)
 * for each middle element k we choose two elements on the left and right that are the mx
 * 
 * so use prefix arr to maximise the arr[i] + i and use suffix array to maximize arr[j] - j
 */

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n+1);
	for(int i = 1; i <= n; i++) cin >> arr[i];

	vector<int> prefix(n+1), suffix(n+1);
	// prefix = max(arr[i] + i) and suffix = max(arr[j] - j)

	prefix[1] = arr[1] + 1;
	for(int i = 2; i <= n; i++) {
		prefix[i] = max(prefix[i-1], arr[i] + i);
	}

	suffix[n] = arr[n] - n;
	for(int j = n-1; j >= 1; j--) {
		suffix[j] = max(suffix[j+1], arr[j] - j);
	}

	// now consider the middle element k and choose the max on left and max on right 
	int ans = 0;
	for(int k = 2; k < n; k++) {
		int val = prefix[k-1] + suffix[k+1] + arr[k];
		ans = max(ans, val);
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