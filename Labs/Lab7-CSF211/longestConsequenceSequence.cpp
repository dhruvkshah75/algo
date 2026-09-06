#include<bits/stdc++.h>
using namespace std;

// question link: 

/*
    100 4 200 1 3 2 
    first we populate the set by adding all the elements in the set and we dont care about
    duplicates 
    now we traverse through the set using unordered_set<int>::iterator it = s.begin()
    then we check if *it-1 exists or not it it exists then we skip the element 
    4 gets skipped, 3 and 2 also get skipped 
    when we reach 1 we run a loop where we keep checking for val++ that is for 2, then 3 
    then 4 and so on we get till 4 so the len will be counter we increased
*/

class Solution {
public:
    // Very important problem 
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();

        if(len == 0) 
            return 0;

        unordered_set<int> s;
        for(int num: nums) {
            s.insert(num);
        }

        // we simply use the set to check if element of set - 1 exists in the set or not 
        unordered_set<int>::iterator it = s.begin();
        int longest = 1; // the ans
        // this is only O(N)
        while(it != s.end()) {
            if(s.find(*it - 1) == s.end()){
                int val = *it;
                int ctr = val;

                while(s.find(val) != s.end()) val++;
                
                longest = max(longest, val-ctr); 
                // val-ctr is the length of the consecutive elements that exist
            }
            it++;
        }
        return longest;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    Solution s = Solution();

    int result = s.longestConsecutive(nums);

    cout << result << endl;
}