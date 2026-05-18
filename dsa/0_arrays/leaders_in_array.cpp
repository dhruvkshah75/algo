// question link: https://takeuforward.org/plus/dsa/problems/leaders-in-an-array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans;
        ans.push_back(nums[len-1]);
        int cur_max = nums[len-1];
        for(int i=len-2; i>=0; i--){
            if(nums[i] > cur_max){
                cur_max = nums[i];
                ans.push_back(nums[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    Solution s = Solution();
    vector<int> ans = s.leaders(nums);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}