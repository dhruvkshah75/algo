#include<bits/stdc++.h>
using namespace std;


// question link: https://leetcode.com/problems/3sum/description/

// using 2 pointers 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l < r) {
                if(nums[l] + nums[r] + nums[i] == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int val1 = nums[l], val2 = nums[r];
                    while(l < r && nums[l] == val1) l++;
                    while(l < r && nums[r] == val2) r--;
                } 
                if(nums[l] + nums[r] + nums[i] > 0) r--;
                else if(nums[l] + nums[r] + nums[i] < 0) l++;
            } 
        }

        return ans;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    Solution s = Solution();
    vector<vector<int>> ans = s.threeSum(nums);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "    ";
    }
    cout << endl;
}


