// ============================================== interval dp ====================================================

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

// question link: https://codeforces.com/problemset/problem/607/B

/**
 * This is obviously a prtition dp question 
 * how exactly do we make the partition 
 * 
 * Approach 
 * consider the block (i, j) as the part that we are dealing with 
 * a[i] can be deleted as a single element or combined with some element a[k]
 * 1. a[i] == a[k] so i and k th elements are deleted togethor iff all the elements 
 *    in the middle are also removed 
 * 2. a[i] is simply deleted as a single element so the next partition will (i+1, j)
 * */

vector<int> arr;
vector<vector<int>> dp;

int f(int i, int j) {
	// base case of empty partition 
	if(i > j) return 0;

	// base case: partition with single element 
	if(i == j) return 1;

	if(dp[i][j] != -1) return dp[i][j];

	// try out all the valid partitions 
	// remove arr[i] alone 
	int ans = 1 + f(i+1, j);

	// remove arr[i] and arr[i+1] togethor => one partition removed altogethor
	if(arr[i] == arr[i+1]) 
		ans = min(ans, 1 + f(i+2, j));
	
	// match arr[i] with arr[k] for other cases 
	for(int k = i+2; k <= j; k++) {
		if(arr[i] == arr[k]) {
			ans = min(ans, f(i+1, k-1) + f(k+1, j));
		}
	}

	return dp[i][j] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	arr.resize(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	dp.assign(n, vector<int>(n, -1));

	cout << f(0, n-1) << endl;
}
