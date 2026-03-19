#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/continuous-subarray-sum/description/

/*
    prefix[j] - prefix[i] = x * k  (some multiple of k) 
    (prefix[i] - prefix[j]) % k = (x * k) % k 
        => prefix[i] = prefix[j] but j - i >= 2 at least 2 elements in the subarray 
    and anathor case where the prefix is directly zero that means it is also the subarray 
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // make the nums array as prefix sum to prevent extra space 
        // Question: prefix[j] - prefix[i] = x * k for any x and j - i >= 2
        // so take mod k both sides => we simply search for prefix[j] = prefix[i]

        unordered_map<int,int> mp;    // store the prev prefix and only add new entries 
        // {prefix, index}
        int prefix = 0;

        for(int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % k;
            // the current element forms the subarray 
            if(prefix == 0 && i != 0)
                return true;

            // contain at least 2 elements & add the entry to the map only if it does not exist
            if(mp.find(prefix) != mp.end()) {
                int j = mp[prefix];
                if(i - j >= 2) return true;
            }
            else {
                mp[prefix] = i;
            }
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    Solution s = Solution();

    cout << s.checkSubarraySum(nums, k) << endl;
}