// ===================================== greedy =================================================

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

// question link: https://codeforces.com/problemset/problem/845/C

/**
 * Use heap for solving this question (can be solved without it)
 * sort the intervals based on start timing and use a min heap to store the end times 
 * of the intervals 
 * priority_queue holds the number of intervals that are overlapping 
 * pq size <= 2 => then we can accomodate them using two TVs 
 * */

void solve() {
	int n;
	cin >> n;

	vector<pair<int,int>> v;
	for(int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		v.push_back({l, r});
	}

	// sort the intervals on their start time 
	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	for(auto [l, r]: v) {
		// remove all the events that ended => end_time < l
		while(!pq.empty() && pq.top() < l) {
			pq.pop();
		}

		pq.push(r);
		if(pq.size() > 2) {
			no;
			return;
		}
	}

	yes;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}