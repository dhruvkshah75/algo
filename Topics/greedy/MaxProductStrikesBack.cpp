// ================================== greedy + two pointers ============================================

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

// question link: https://codeforces.com/problemset/problem/1660/D

/**
 * max product of some window occurs when there are max number of 2s 
 * as all |ai| <= 2 => the window must have max number of 2s in it 
 * and should have even number of negatives in it for the product to be max 
 * window should not have any zeros in it 
 * we always expand the window and shrink it when 0 encountered or when end is reached 
 * and update the ans when the window is valid (even negatives and max number of 2s)
 */

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	int cnt2 = 0, x = 0, y = n;
	int max_cnt2 = 0, negs = 0;
	int l = 0, r = 0;

	while(r < n) {
		// expand the window on right as the value is non zero 
		if(arr[r] != 0) {
			if(arr[r] < 0) negs++;
			if(abs(arr[r]) == 2) cnt2++;

			// update the ans if this window is valid 
			if(negs % 2 == 0 && cnt2 > max_cnt2) {
				max_cnt2 = cnt2;
				x = l;
				y = n-1-r;
				// window currently is [l...r]
			}
			r++;
		}
		
		// cannot expand as end reached or zero encountered 
		if(r == n || arr[r] == 0) {
			// shrink the window to get a valid one 
			while(l < r && negs % 2 != 0) {
				if(abs(arr[l]) == 2) cnt2--;
				if(arr[l] < 0) negs--;
				l++;
			}

			// update the ans for this new valid window 
			if(negs % 2 == 0 && cnt2 > max_cnt2) {
				max_cnt2 = cnt2;
				x = l;
				y = n-r; 
			}

			// skip all the zeros and move l and r there => reset the window parameters 
			while(r < n && arr[r] == 0) r++;
			l = r;
			cnt2 = 0;
			negs = 0;
		}
	}

	// x = number of elements deleted from the left and y = number of elements deleted on the right 
	cout << x << " " << y << endl;

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