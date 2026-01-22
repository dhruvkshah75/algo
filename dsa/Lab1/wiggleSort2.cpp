#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/wiggle-sort-ii/description/

/*
    Algorithm:
        We copy the array first and then we sort the temp array 
        and then we use 2 ptrs r = len-1 and l = mid and then as we traverse in the array we do l-- and r--
        The right half of the array contains the bigger elements than the left half 
        So we place the elements pointed by r on odd indices and elements pointed by l on even indices 
        eg. 1 3 2 2 3 1
          1.temp = 1 1 2 2 3 3
                       l     r -> pointers 
            nums = 2 3 

          2.temp = 1 1 2 2 3 3
                     l     r  
            nums = 2 3 1 3 

          3.temp = 1 1 2 2 3 3 
                   l     r
            nums = 2 3 1 3 1 2
*/


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int r = len-1;
        int mid = r/2;
        int l = mid; 
        for(int i=0; i<len; i++) {
            if(i & 1) nums[i] = temp[r--];
            else nums[i] = temp[l--];
        }
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
    s.wiggleSort(nums);

    cout << "Printing the array" << endl;
    for(int i=0; i<n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}                    
