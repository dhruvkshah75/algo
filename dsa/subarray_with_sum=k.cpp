#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void printArray(vector<int> &arr){
        cout << "Arr: ";
        for(int i=0; i<arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> pf(len);
        // map to store the location of prefix sum 
        map<int,vector<int>> loc;
        pf[0] = nums[0];
        loc[pf[0]].push_back(0);
        for(int i=1; i<len; i++){
            pf[i] = pf[i-1] + nums[i];
            loc[pf[i]].push_back(i);
        }
        printArray(pf);

        int ans = 0;
        for(int i=0; i<len; i++){
            if(k == pf[i]) ans++;
            if(loc.count(pf[i] - k)){
                for(int &idx: loc[pf[i]-k]){
                    printArray(loc[pf[i]-k]);
                    if(idx < i){
                        ans++;
                    } 
                    
                }
            }
        }
        return ans;
    }
};



int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    Solution s = Solution();
    cout << s.subarraySum(nums, k) << endl;
}