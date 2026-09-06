// ================================== bitmasks + greedy ====================================

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

// question link: https://codeforces.com/problemset/problem/1498/B

/**
 * store all the w[i] in array in a different way => since all w[i] are powers of 2 
 * it only has 1 setbit in it so make cnt[i] array 
 * cnt[i] = count of all numbers whose ith bit is set => cnt[3] = 1 means w[i] = 8 
 * is there in the array 
 * 
 * to put all the boxes in the bigger box we can use the concept of bitmasking 
 * start with the maxBit of W and try placing all boxes untill every box is placed 
 * 
 * remaining = W
 * then place the max width box and then update remaining and try the next fittable box in it 
 */

void solve() {
	int n, W;
	cin >> n >> W;

	// w[i] <= 1e6 so max set bit will be 19
	vector<int> cnt(20);

	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;

		int highest_bit = 31 - __builtin_clz(x);
		cnt[highest_bit]++;
	}

	// try fitting all the boxes until no box remains 
	int remaining_boxes = n;
	int height = 0;
	int max_bit = min(19, 31 - __builtin_clz(W));

	while(remaining_boxes > 0) {
		height++;

		int left = W;
		
		for(int i = max_bit; i >= 0; i--) {
			int width = 1 << i;

			// we can take multiple boxes of the same size if allowed 
			int take = min(cnt[i], left / width);

			cnt[i] -= take;
			remaining_boxes -= take;
			left -= width * take;
		}
	}

	cout << height << endl;
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