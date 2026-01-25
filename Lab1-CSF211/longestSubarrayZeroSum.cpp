#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();
        vector<ll> prefix(n+1);
        prefix[0] = 0; // base to not miss out cases
        for(int i=1; i<=n; i++) {
            prefix[i] = prefix[i-1] + nums[i-1]*1LL;
        }

        int ans = 0;  // the length of the longest subaaray 
        unordered_map<ll,int> mp; // store the prefix sum values for instant search 
        // now we traverse through the prefix sum array
        mp[0] = 0;
        for(int i=1; i<=n; i++) {
            if(!mp.count(prefix[i])) {
                mp[prefix[i]] = i;   
            }
            if(mp.count(prefix[i] - k)) {
                int idx = mp[prefix[i] - k];
                ans = max(ans, i-idx);
            }
        }
        return ans;
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++) 
        cin >> nums[i];

    Solution s = Solution();
    cout << s.longestSubarray(nums, k) << endl;   
}
