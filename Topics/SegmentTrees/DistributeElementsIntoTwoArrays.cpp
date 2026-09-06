// ================= segment trees + frequency counting + coordinate compression ========================

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

// question link: https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/ 

/*
 * in this question we must implement the function greaterCount(arr, val)
 * this returns the number of elements in the arr with val > arr
 * can be solved by using frequency map and when we want to get the 
 * cnt of strictly greater elements that is eq to range sum in the freq array 
 * and each addition to either array is eq to point updates in the segment tree 
 * 
 * we aree given all the elements of the nums array so create a coordinate compression 
 * of them so that we can get the frequency mapping in sorted order i.e.
 * if index i points at 1e6 then i+1 must point at a number > 1e6
 *
 * How to get the coordinate compression 
 * first get all the sorted unique values and then mark them with starting index i = 0
 * and move on to index++
 */

class SegmentTree {
private:
	vector<int> tree;

	void build(int ind, int low, int high, vector<int> &freq) {
		// base case: single element segment reached 
		if(low == high) {
			tree[ind] = freq[low];
			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid, freq);
		build(2*ind+2, mid+1, high, freq);

		tree[ind] = tree[2*ind+1] + tree[2*ind+2];
	}

public:
	SegmentTree(int n, vector<int> &freq) {
		tree.assign(4 * n, 0);
		build(0, 0, n-1, freq);
	}

	void update(int ind, int low, int high, int idx) {
		// point updates is equivalent to making freq[idx]++;
		if(low == high) {
			tree[ind]++;
			return;
		}

		int mid = low + (high - low) / 2;

		if(idx <= mid) update(2*ind+1, low, mid, idx);
		else update(2*ind+2, mid+1, high, idx);

		tree[ind] = tree[2*ind+1] + tree[2*ind+2];
	}

	int query(int ind, int low, int high, int l, int r) {
		// return range sum [l...r]
		if(high < l || r < low) {
			// no overlap so no contribution 
			return 0;
		}
		else if(l <= low && high <= r) {
			// complete overlap so return the tree val
			return tree[ind]; 
		}
		else {
			// partial overlap so naviagte to left and right
			int mid = low + (high - low) / 2;
			return query(2*ind+1, low, mid, l, r) + query(2*ind+2, mid+1, high, l, r);
		}
	}
};

class Solution {
public:
    vector<int> resultArray(vector<int> &nums) {
        int n = nums.size();

        // get all the unique values in the sorted arr
        set<int> unique_vals(nums.begin(), nums.end());

        int index = 0;
        unordered_map<int,int> compressed;
        for(int val: unique_vals) {
        	compressed[val] = index;
        	index++;
        }	 	

        // size of the freq array will be index 
        int sz = index;
        vector<int> freq1(sz, 0), freq2(sz, 0);

        // place the nums[0] in arr1 and num[1] in arr2
        vector<int> arr1, arr2;

        arr1.push_back(nums[0]);
        freq1[compressed[nums[0]]]++;
        arr2.push_back(nums[1]);
        freq2[compressed[nums[1]]]++;

        SegmentTree segs1(sz, freq1), segs2(sz, freq2);

        for(int i = 2; i < n; i++) {
        	int l = compressed[nums[i]]+1, r = sz-1;
        	// get the greater_cnt for arr1
        	
        	int greater_cnt1 = segs1.query(0, 0, sz-1, l, r);
        	int greater_cnt2 = segs2.query(0, 0, sz-1, l, r);

        	if(greater_cnt1 > greater_cnt2) {
        		arr1.push_back(nums[i]);
        		// must make a point update as freq changed 
        		int idx = compressed[nums[i]];
        		segs1.update(0, 0, sz-1, idx);
        	}
        	else if(greater_cnt1 < greater_cnt2) {
        		arr2.push_back(nums[i]);
        		int idx = compressed[nums[i]];
        		segs2.update(0, 0, sz-1, idx);
        	}
        	else {
        		// add the element to array with less elements 
        		if(arr1.size() <= arr2.size()) {
        			arr1.push_back(nums[i]);
        			int idx = compressed[nums[i]];
        			segs1.update(0, 0, sz-1, idx);
        		}
        		else {
               		arr2.push_back(nums[i]);
        			int idx = compressed[nums[i]];
        			segs2.update(0, 0, sz-1, idx);
        		}
        	}
        }

        vector<int> result;
        for(int i = 0; i < arr1.size(); i++)
        	result.push_back(arr1[i]);

        for(int j = 0; j < arr2.size(); j++) 
        	result.push_back(arr2[j]);

        return result;
    }
};