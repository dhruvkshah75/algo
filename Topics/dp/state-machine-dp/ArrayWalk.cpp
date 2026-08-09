// ================================== multi state dp ======================================

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

// question link: https://codeforces.com/problemset/problem/1389/B

// formula of position = moves_made - 2 * total_left_moves_made + 1

int n, k, z;
vector<int> arr;

int f(int moves, int total_left, int curr_left, vector<vector<vector<int>>> &dp) {
	// base case: all k moves made 
	if(moves == k) return 0;

	if(dp[moves][total_left][curr_left] != -1) return dp[moves][total_left][curr_left];

	int res = 0;
	// try making a left move => pos to pos-1
	if(curr_left == 0 && total_left+1 <= z && moves - 2 * total_left >= 1) {
		res = max(res, arr[moves - 2 * total_left + 1 - 1] + f(moves+1, total_left+1, curr_left+1, dp));
	}

	// make the move from pos to pos+1
	res = max(res, arr[moves - 2 * total_left + 1 + 1] + f(moves+1, total_left, 0, dp));

	return dp[moves][total_left][curr_left] = res;
}

void solve() {
	cin >> n >> k >> z;

	arr.assign(n+1, 0);
	for(int i = 1; i <= n; i++) cin >> arr[i];

	vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(z+1, vector<int>(2, -1)));
	
	// add the element 1 of the array as we start from there 
	int max_value = arr[1] + f(0, 0, 0, dp);
	cout << max_value << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)
		solve();
}