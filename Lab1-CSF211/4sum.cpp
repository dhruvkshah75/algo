#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/4sum/description/

// O(N^3) and use two pointers after sorting the array

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n-1; j++) {
                int val = nums[j];
                int l = j+1, r = n-1;
                while(l < r) {
                    if(nums[i]*1LL + nums[j]*1LL + nums[l]*1LL + nums[r]*1LL == (long long)target){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        int val1 = nums[l], val2 = nums[r];
                        while(l < r && nums[l] == val1) l++;
                        while(l < r && nums[r] == val2) r--;
                    }
                    if(nums[i]*1LL + nums[j]*1LL + nums[l]*1LL + nums[r]*1LL > (long long)target) r--;
                    else if(nums[i]*1LL + nums[j]*1LL + nums[l]*1LL + nums[r]*1LL < (long long)target) l++;
                }
                while(j < n && nums[j] == val) j++;
                j--;
            }
        }

        return ans;
    }
};

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    Solution s = Solution();
    vector<vector<int>> ans = s.fourSum(nums, target);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] <<  "    ";
    }
    cout << endl;
}
