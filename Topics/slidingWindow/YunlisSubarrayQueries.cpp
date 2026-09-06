// ============================================== data structures + sliding window ====================================

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

// question link: https://codeforces.com/contest/2009/problem/G1

/*
 * Very Important question based on sliding window
 * note: each query = [l, r] with r = l+k-1
 * so each query is of the form [l, l+k-1] so only precompute for all l values 
 * this is like a sliding window of fixed size k 
 * 
 * now how to determine or get the min number of operations to make the 
 * window consecutive subarray => not possible to check in O(1) 
 * so consider the changed array of differences => arr[i] - i
 * consider a window [1, 2, 3, 6, 5] = [0, 0, 0, 2, 0]
 * this essentially becomes => min operations = k(window size) - max_freq of some number  
 * use multiset or map to get the max freq in O(LogK) time 
 */

void solve() {
	int n, k, q;
	cin >> n >> k >> q;

	vector<int> arr(n);
	// directly store the difference x - i
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i] = x - i;
	}

	unordered_map<int,int> freq;
	multiset<int> ms;

	vector<int> res(n);
	// precompute all the queries for all l

	int l = 0;
	for(int r = 0; r < n; r++) {
		// expand the window on right 
		if(!freq.count(arr[r])) {
			freq[arr[r]]++;
			ms.insert(freq[arr[r]]);
		} 
		else {
			int curr_freq = freq[arr[r]];
			auto it = ms.find(curr_freq);
			if(it != ms.end()) ms.erase(it);
			freq[arr[r]]++;
			ms.insert(freq[arr[r]]);
		}

		// shrink the window if the size becomes k+1
		if(r-l+1 > k) {
			int ele = arr[l];
			int del_freq = freq[ele];
			auto it = ms.find(del_freq);
			if(it != ms.end()) ms.erase(it);
			freq[ele]--;

			if(freq[ele] == 0) {
				freq.erase(ele);
			}
			else {
				ms.insert(freq[ele]);
			}
			l++;
		}

		// if window is of size k then update the ans for that value of l
		if(r-l+1 == k) {
			int max_freq = *ms.rbegin();
			res[l] = k - max_freq;
		}
	}

	// answer the queries in O(1) time 
	while(q--) {
		int l, r;
		cin >> l >> r;

		cout << res[l-1] << endl;
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