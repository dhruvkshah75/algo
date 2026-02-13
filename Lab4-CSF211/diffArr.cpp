#include<bits/stdc++.h>
using namespace std;

// VERY IMPORTANT TRICK => Difference Array => SLIDING WINDOW VARIATION 

/*
    Problem: 
        Given an array of N elements perform Q queries on it and print the final array 
        N <= 1e5 and Q <= 1e5
        Q: Li, Ri, Xi ==> This means we have to add Xi to to the subarray from Li to Ri Inclusive 
*/

class Solution {
public:
    void diffArrayImplementation(vector<int>&nums, vector<vector<int>>&queries) {
        int n = nums.size();
        int q = queries.size();
        /*
            Use the logic of Difference array 
            A[L] += X, A[R+1] -= X
            And then when we take the prefix sum of this array we get the original array 
        */
    }
};