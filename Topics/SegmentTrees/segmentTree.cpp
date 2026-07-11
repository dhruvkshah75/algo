// ========================================= segment tree ==================================

#include<bits/stdc++.h>
using namespace std;

/* =============================== Range Based Queries Data Structure ======================
 * 
 * Question: Given 2 arrays answer the following queries 
 * 2 types of Queries 
 * => type 1: [1, l1, r1, l2, r2] => return the min of the range for the both the arrays => ans = min((l1, r1), (l2, r2))
 * => type 2: [2, 1, ind, val] => make point updates in the array 1 => arr[ind] = val
 * 
 * For these range based questions use Segment Trees
 */

class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;

    void build(int ind, int low, int high) {
        // base case: single element 
        if(low == high) {
            tree[ind] = arr[low];
            return; 
        } 

        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid+1, high);

        // current value will be made using the left, right child 
        tree[ind] = min(tree[2 * ind + 1], tree[2 * ind + 2]);
    }

public: 
    SegmentTree(vector<int> &arr) {
        this->arr = arr;
        int n = arr.size();
        tree.resize(4*n);
        build(0, 0, n-1);
    }

    int query(int ind, int low, int high, int l, int r) {
        // [l..r] is the range query and (ind, [low,..,high]) are the indexes for the segment tree

        if(high < l || r < low) {
            // no overlap => [low...high]..[l..r] or [l..r]..[low..high] => current segment of the tree [low..high] => no contribution 
            return INT_MAX;
        }
        else if(l <= low && high <= r) { 
            // complete overlap => [l...low...high...r]
            return tree[ind];
        }
        else {
            // partial overlapp of query range with segment => so explore in both directions 
            int mid = (low + high) / 2;
            int left = query(2*ind+1, low, mid, l, r);
            int right = query(2*ind+2, mid+1, high, l, r);

            return min(left, right);
        }
    }

    // Point update => arr[i] = val
    void update(int ind, int low, int high, int i, int val) {

        // base case: low == high == i (place where the change was to be made)
        if(low == high) {
            tree[ind] = val;
            return;
        }

        int mid = (low + high) / 2;
        // try to reach to the segement node with l,r = i,i
        if(i <= mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);

        tree[ind] = min(tree[2*ind+1], tree[2*ind+2]);
    }
};

void solve() {
    int n1;
    cin >> n1;

    vector<int> arr1(1);
    for(int i = 0; i < n1; i++) cin >> arr1[i];

    SegmentTree seg1(arr1);

    int n2;
    cin >> n2;

    vector<int> arr2(n2);
    for(int i = 0; i < n2; i++) cin >> arr2[i];

    SegmentTree seg2(arr2);

    int q;
    cin >> q;

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;

            int mn1 = seg1.query(0, 0, n1-1, l1, r1);
            int mn2 = seg2.query(0, 0, n2-1, l2, r2);
            // O(Log(N)) time complexity

            cout << min(mn1, mn2) << endl;
        }
        else {
            int k, index, value;
            cin >> k >> index >> value;

            if(k == 1) {
                seg1.update(0, 0, n1-1, index, value);
                arr1[index] = value;
            }
            else {
                seg2.update(0, 0, n2-1, index, value);
                arr1[index] = value;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}