#include<bits/stdc++.h>
using namespace std;

// Simple TWO POINTER APPROACH, Time Complexity: O(n);

// question link: https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void printArr(vector<int>&nums) {
        cout << "Printing the vector: " << endl;
        for(int i=0; i<nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    void moveZeroes(vector<int>& nums) {
        // we need to maintain the relative order of the other elements 
        // pick up all the non zero elements and start placing them in the oder they appear 
        int k = 0; // ptr for non zero elements 
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) nums[k++] = nums[i];  
        }   
        // now we place the 0s at the end after k non-zero elements are placed in front of them 
        while(k < nums.size()) {
            nums[k++] = 0;
        }
    }

};


int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution s = Solution();

    s.moveZeroes(nums);
    s.printArr(nums);
}