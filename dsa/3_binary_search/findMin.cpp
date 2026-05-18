#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(r-l>1){
            int mid = (l+r)/2;
            if(nums[mid] > nums[l]) l = mid;
            else r = mid;
        }
        // we do this if the array is completely sorted
        return min(nums[0], nums[r]); 
        // The ans is nums[0] when the array is sorted otherwise the binary search works fine 
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
    cout << s.findMin(nums) << endl;
}



