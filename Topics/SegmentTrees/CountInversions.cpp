// ============================================== Segment Trees ==========================================

#include<bits/stdc++.h>
using namespace std;

/* Explanation in the notes
  
   This question can easily be solved using merge sort -> in a much cleaner version of code 

   Use the segment tree to answer the range sum queries on the freq array of the given array 
   the segment tree must be dynamic to allow point updates and queries => in time complexity = O(LogN)

   VERY IMPORTANT CONCEPT => RangeSum of frequencies to get the number of some pairs (inversions here)
   so when we want some count of pairs => we can use range sum on frequencies 
*/

typedef long long ll;

class SegmentTree {
private:
	vector<ll> tree;
	vector<int> arr;

	void build(int ind, int low, int high) {
		if(low == high) {
			tree[ind] = arr[low];
			return;
		}

		int mid = (low + high) / 2;

		build(2*ind+1, low, mid);
		build(2*ind+2, mid+1, high);
		// range sum calculation
		tree[ind] = tree[2*ind+1] +  tree[2*ind+2];
	}

public:
	SegmentTree(vector<int> &freq) {
		arr = freq;
		int n = arr.size();

		tree.resize(4 * n);
		build(0, 0, n-1);
	}

	void update(int ind, int low, int high, int index, int value) {
		// reached the node where => low = high = index 
		if(low == high) {
			tree[ind] = value;
			return;
		}

		int mid = (low + high) / 2;
		if(index <= mid) update(2*ind+1, low, mid, index, value);
		else update(2*ind+2, mid+1, high, index, value);
		// update current ind with newer range sum
		tree[ind] = tree[2*ind+1] + tree[2*ind+2];
	}

	ll query(int ind, int low, int high, int l, int r) {
		// return 0 if invalid query 
		if(l > r) return 0;

		if(high < l || r < low) { // no overlap then return 0 => no contribution to this query
			// low..high...l..r or l..r...low...high
			return 0;
		}
		else if(l <= low && high <= r) { // complete overlap => [l...low...high...r]
			return tree[ind];
		}
		else { // partial overlapp call the left and right nodes
			int mid = (low + high) / 2; 
			ll left = query(2*ind+1, low, mid, l, r);
			ll right = query(2*ind+2, mid+1, high, l, r);

			return left + right;
		}
	}
};

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	/* bottleneck => we apply a range sum segment tree on the freq array 
       so all values <= 1e5 or 1e6
       To solve this issue => mapping of unique elements to number 1, 2, 3, .... is to be done 
       this solves this issue => but creates a lot of memory overhead 
       But Segment tree becomes necessary when dynamic queries are asked => make updates to the vector */

	int mx = *max_element(arr.begin(), arr.end());
	
	vector<int> freq(mx+1, 0);
	for(int num: arr) freq[num]++;

	SegmentTree seg(freq);

	ll cnt = 0;

	for(int i = 0; i < n; i++) {
		// reduce the freq of this element arr[i] by 1 in segment tree
		int curr_freq = freq[arr[i]];
		seg.update(0, 0, mx, arr[i], curr_freq-1);
		freq[arr[i]]--;

		// make the range sum query from 1 to arr[i]-1 => [1, arr[i])
		cnt += seg.query(0, 0, mx, 0, arr[i]-1);
	}

	// cnt = number of inversions in the array 
	cout << cnt << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}