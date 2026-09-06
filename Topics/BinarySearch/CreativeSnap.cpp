// ============================ divide and conquer + binary search ==========================================

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

// question link: https://codeforces.com/problemset/problem/1111/C

/*
 * simply apply divide and conquer and then check using bounds if there 
 * are any avengers in that segment or not 
 * if there then further breakdown otherwise simply add up A 
 * let cnt of avengers in the segment [l..r] be cnt
 * cnt = 0 => return A
 * cnt != 0 and len = 1 => return B * cnt * len
 * otherwise return min(B * cnt * len, solve(l, mid) + solve(mid+1, r))
 * 
 * now we must count the number of avengers in the same segment 
 * that can be easily counted using lower bound and upper bound over sorted positions 
 * of the avengers 
 */

int n, k, A, B;
vector<int> arr;

int numCount(int l, int r) {
	// using bounds get the number of avengers in [l..r]
	auto it1 = lower_bound(arr.begin(), arr.end(), l);
	int idx1 = distance(arr.begin(), it1);

	auto it2 = upper_bound(arr.begin(), arr.end(), r);
	int idx2 = distance(arr.begin(), it2);

	// the number of avengers will be diff of idx2 - idx1
	return idx2 - idx1;
}

ll divNconq(int l, int r) {
	int cnt = numCount(l, r);

	// no avnegers in this split so dont go further 
	if(cnt == 0) return A;

	int len = r-l+1;
	ll cost = 1LL * B * len * cnt;

	// if len == 1 then return the cost 
	if(len == 1) return cost;

	int mid = l + (r - l) / 2;
	return min(cost, divNconq(l, mid) + divNconq(mid+1, r));
}

void solve() {
	cin >> n >> k >> A >> B;

	arr.resize(k);
	for(int i = 0; i < k; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());
	// sort them so that we can use lower bound on it 
	
	// range is 1....(1 << n)
	ll result = divNconq(1, 1 << n);
	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}