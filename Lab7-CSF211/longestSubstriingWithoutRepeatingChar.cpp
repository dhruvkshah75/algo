#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/*
    using sliding window technique where we update the left if we find s[right] is found in the current window 
    left and right 
*/

class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int n = s.length();

        unordered_map<char,int> mp; // stores the location of each unqiue character so we know where to cut off
        // we must use a sliding window approach using l and r 
        int l = 0, r = 0, result = 0;

        // if we increase r then we cut off the sequence from 
        // initially update the sliding window
        while(r < n && mp.find(s[r]) == mp.end()) {
            mp[s[r]] = r;
            r++;
        }
        result = max(result, r - l);

        // sliding window keeps the unique substring 
        while(r < n) {
            if(mp.find(s[r]) == mp.end()) {
                mp[s[r]] = r;
                r++;
                result = max(result, r - l);
            }
            else {
                // character found in the window 
                // update the left of the window => left should always increment or stay there 
                l = max(l, mp[s[r]] + 1);   
                mp[s[r]] = r;
                r++;
                result = max(result, r - l);
            }
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    Solution s = Solution();

    int result = s.lengthOfLongestSubstring(str);

    cout << result << endl;
}