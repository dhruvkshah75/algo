#include <bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/split-array-largest-sum/description/

// very similar to capacityToShipPackages.cpp


class Solution {
public:
    // a predicate function which will return FFFFTTTT find the first T occurence 
    bool possibleVal(vector<int>&nums, int k, int mid) {
        int ctr = 1;
        int curr_sum = 0;
        for(int i=0; i<nums.size(); i++) {
            curr_sum += nums[i];
            
            if(curr_sum > mid) {
                curr_sum = nums[i]; 
                ctr++;
            }

            if(ctr > k) return false;
        }
        if(ctr > k) return false;
        else return true; 
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        while(r-l>1) {
            int mid = l + (r-l)/2;
            cerr << "mid: " << mid << endl;
            if(possibleVal(nums, k, mid)) r = mid;
            else l = mid;
        }
        // we first check l as its lower 
        if(possibleVal(nums, k, l)) return l;
        else return r;
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Solution s = Solution();
    cout << s.splitArray(nums, k) << endl;
}