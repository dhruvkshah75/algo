#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
// LEETCODE HARD QUESTION 


/*
    IMPORTANT QUESTION
    ALGORITHM: 
    We apply binary search on distance.
    We check if there are more or equal pairs greater than k, if yes then the predicate function returns true
    Otherwise false 
    We use two pointer approach for checking how many pairs exists with abs distance is less or equal to x
    where we vary x from 0 to max_distance using binary search 
*/

class Solution {
public:
    // returns FFFFFTTTTTT 
    // this function uses 2 pointer approach 
    bool predicate(vector<int>&nums, int k, int x) {
        int n = nums.size();
        int ctr = 0;
        int l = 0, r = 1;
        while(l < n && r < n) {
            while(r < n && nums[r] - nums[l] <= x) r++;
            ctr += r - l - 1;
            l++;
            if(r == l) r++;   // if r doesnt preoceed beacuse of the inner loop then we should make r = l + 1;
        }
        ctr += ((r-l)*(r-l-1))/2;
        if(ctr >= k) return true;
        else return false;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 

        // apply binary search on the ans i.e. the distance between the elements 
        // we need to find the no of pairs that have a distance less than x
        int l = 0, r = nums[n-1] - nums[0];
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(predicate(nums, k, mid)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Solution s = Solution();
    cout << s.smallestDistancePair(nums, k) << endl;
}