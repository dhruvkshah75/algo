#include<bits/stdc++.h>
using namespace std;


// question link: https://leetcode.com/problems/k-diff-pairs-in-an-array/description/


/*
    Time Complexity: O(n*Log(n)), Algorithm:
        We traverse through each element, keeping the curr_element = nums[i]
        and then we search for the element from i+1 and n-1
        We need to apply binary search two times as we find index j such that 
        nums[j] = nums[i] + k and nums[j] = nums[i] - k 
        We make sure that we put in distinct values of i and j 
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // a simple binary search of O(n*Log(n)) will work out 
        sort(nums.begin(), nums.end());

        // nums[i] = nums[j] + k or nums[i] = nums[j] - k
        int n = nums.size();
        int ans = 0;
        for(int i=0; i+1<n; i++) {
            // binary search 1: we find nums[j] = nums[i] - k
            int l = i+1, r = n-1;
            int index1 = -1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(nums[mid] <= nums[i] - k) {
                    index1 = mid;
                    l = mid + 1;
                } 
                else r = mid - 1;
            }
            if(index1 != - 1 && abs(nums[i]-nums[index1]) == k) 
                ans++;

            l = i+1; r = n-1;
            int index2 = -1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(nums[mid] <= nums[i] + k) {
                    index2 = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if(index2 != -1 && index2 != index1 && abs(nums[i]-nums[index2]) == k)
                ans++;

            // skip the same elements 
            while(i + 1 < n && nums[i] == nums[i+1]) i++;
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

    cout << s.findPairs(nums, k) << endl;
}