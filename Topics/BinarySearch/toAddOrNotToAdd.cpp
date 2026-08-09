// ====================================== sliding window + two pointers =============================================

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

// question link: https://codeforces.com/problemset/problem/231/C

/**
 * first of all sort the array 
 * now try to make as many possible elements into arr[ind]
 * and we can only transform the elements smaller than arr[ind]
 * 
 * let the section that is converted to arr[ind] be [y.....ind]
 * x * arr[ind-1] - (prefix[ind] - prefix[y-1]) <= K
 * 
 * for this question we can sliding window with window size being variable 
 * we try to expand the window on the right and if the window becomes invalid then shrink 
 * when is the window invalid 
 * arr[r] * (r - l + 1) => make these many elements equal to arr[ind]
 * operations needed are arr[r] * (r - l + 1) - (prefix[r+1] - prefix[l]) 
 **/

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	// sort the array in ascending order 
	sort(arr.begin(), arr.end());

	vector<ll> prefix(n+1, 0);	
	for(int i = 0; i < n; i++) 
		prefix[i+1] = prefix[i] + 1LL * arr[i];

	// convert all previous elements into the current with k operations 

	int l = 0;
	int maxLen = 0, res = -1;

	for(int r = 0; r < n; r++) {
		// expand window on right => convert all elements in the window to arr[r] 
		// shrink when the window is invalid 
		while(arr[r] * 1LL * (r-l+1) - (prefix[r+1] - prefix[l]) > k) {
			l++;
		}

		int len = r-l+1;
		if(len > maxLen) {
			maxLen = len;
			res = arr[r];
		}
	}

	cout << maxLen << " " << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}