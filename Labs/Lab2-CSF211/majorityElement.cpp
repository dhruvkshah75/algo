#include<bits/stdc++.h>
using namespace std;

// question link: 
// Find majority element with occurences more than n/2 times --> then this method works 

// Very Important: Moore's Voting algorithm 
/*
    1. Initialize candidate and count.
    2. Traverse array:
        If count == 0, set candidate = num.
        If num == candidate, increment count, else decrement count.
    3. Return candidate as majority element.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, curr = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(cnt == 0) curr = nums[i];
            if(nums[i] == curr) cnt++;
            else cnt--;
        }
        return curr;
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
    cout << s.majorityElement(nums) << endl;
}