#include<bits/stdc++.h>
using namespace std; 

// question link: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/description
// A simple greedy approach on Subarray with sum = k 

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        // store the prefix in the map and once we get a subarray 
        // then empty the map and start from prefix = 0 => forget that array had previous elements 
        // This is the greedy approach 
        int n = nums.size();

        int prefix = 0, result = 0;
        unordered_map<int,int> mp;
        mp[0] = 0;

        for(int i = 0; i < n; i++) {
            prefix += nums[i]; 
            if(mp.find(prefix - target) != mp.end()) {
                // found a subarray 
                result++;
                prefix = 0;    // reset from here 
                mp.clear();    // => clear out the map
                mp[0] = 0;
            }
            else          // only fill the map if not found
                mp[prefix] = i;
        }

        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target; 

    vector<int> nums(n);

    for(int i = 0; i < n; i++) 
        cin >> nums[i];

    cout << Solution().maxNonOverlapping(nums, target) << endl;
}