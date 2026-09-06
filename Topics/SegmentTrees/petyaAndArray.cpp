// ================================ segment trees =============================================

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

// question link: https://codeforces.com/problemset/problem/1042/D

/*
 * simple sliding window maximum with subarray counting wont work 
 * as the array contains positive and negative elements in the array
 */

void solve() {
	int n;
	ll t;
	cin >> n >> t;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}