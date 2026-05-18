#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/first-missing-positive/description/

/*
    the range of the missing positive number will be 1 to n as n is the size of the array 
    replace all numbers <= 0 or > n with n+1 (out of range, we don't care about them)   
    We treat the array as a hash table 
    1. Firstly bring down all the numbers in the range if num <= 0 and num > n make it n + 1 
    2. now traverse through each element and assume the indexes of the array as keys and then
       now while visiting each element nums[i] => go mark the nums[nums[i]-1] as negative meaning that i exists 
       SIMPLE INTUITION is that all the indexes are sorted and that helps 
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // since we want the first smallest positive missing num => make the current array as hash map itself
        int n = nums.size(); 
        nums.push_back(n+1);  // increase the length of array to accomodate n + 1

        for(int i = 0; i < n; i++) {
            // update all the out of range numbers 
            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = n+1;
        }

        // now while visiting each element nums[i] => go mark the nums[nums[i]-1] as negative 
        // this is like treating the array itself as hash map 
        for(int i = 0; i < n; i++) {
            int val = nums[abs(nums[i]) - 1];
            if(val > 0)     
                nums[abs(nums[i]) - 1] = -val;
            // marking the number as negative if it was positive 
        } 

        // The ans is the index whose element is non negative 
        for(int i = 0; i <= n; i++) {
            if(nums[i] > 0)
                return i + 1;
        }
        // the above loop will always return the answer 
        return -1;
    }
};