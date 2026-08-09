// ======================================= two pointers + greedy ==============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/get-the-maximum-score/description/

/**
 * Explanation: dp / Two pointers + greedy
 * Dp can be used to get the reslult easily by exploring all posssible paths 
 * states would be (pos, arr) => space complexity = O(2 * N + N + N) => extra space for value to idx maps will also be needed 
 * Using two pointers to run till the bridge and then choosing the best path to reach the bridge works perfectly fine 
 * here the space complexity = O(1) as we only need two values to keep a track of the sum that we form 
 * 
 * Two pointers only works because the arrays are strictly increasing so we can predict on how to reach the bridge
 * */

typedef long long ll;

class Solution {
private:
	const int MOD = 1e9+7;

public:
    int maxSum(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        int i = 0, j = 0;
        ll res = 0, sum1 = 0, sum2 = 0;
        // i => nums1 and j => num2

        while(i < n1 && j < n2) {
        	// try reaching the next gap or bridge (nums1[i] == nums2[j])
        	if(nums1[i] < nums2[j]) {
        		sum1 += nums1[i];
        		i++;
        	}
        	else if(nums1[i] > nums2[j]) {
        		sum2 += nums2[j];
        		j++;
        	}
        	else {
        		// nums1[i] == nums2[j] => bridge reached now select which path was better
        		res += nums1[i] + max(sum1, sum2);
        		sum1 = sum2 = 0;
        		i++; 
        		j++;
        	}
        }

        // now consider the left out path (one of the arrays finishes early)
        while(i < n1) sum1 += nums1[i++];

        while(j < n2) sum2 += nums2[j++];
        
        res += max(sum1, sum2);

        return res;
    }
};
