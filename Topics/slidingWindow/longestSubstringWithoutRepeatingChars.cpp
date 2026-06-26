// ======================================================= sliding window ===================================================

#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

// question link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/* Explanation: Sliding Window + hash table 
 * The window must have characters with freq of 1 in the substring 
 * use the map to store the freq of the chars in the window 
 *
 * Expand the window when char is not in the map => as map contains only characters with freq 1 
 * Then when we cannot add the char in the map => start shrinking the map from the left until the char 
 * is found that is nums[r+1]  
 */

class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int n = s.length();

        // empty string => base case
        if(n == 0) return 0;

        unordered_set<char> st;
        int l = 0, r = 0, res = 1;

        // start from a window of size 1 
        st.insert(s[0]);

        while(r+1 < n) {
            // expand if s[r+1] is a new char
            if(st.find(s[r+1]) != st.end()) {
                // shrink the window until char is equal to nums[r+1]
                while(s[l] != s[r+1]) {
                    st.erase(s[l]);
                    l++;
                }

                // remove s[l] 
                st.erase(s[l]);
                l++;
            }

            // expand to r+1
            st.insert(s[r+1]);
            r++;

            res = max(res, r-l+1);
        }

        return res;
    }
};
// Time Complexity = O(N + N), Space Complexity = O(26)



// ================================= Optimised Solution => Time Complexity = O(N) ==================================================

/* Explanation: Sliding Window + hash table 
 * The window must have characters with freq of 1 in the substring 
 * use the map to store the freq of the chars in the window 
 *
 * Expand the window when char is not in the map => as map contains only characters with freq 1 
 * Then when we cannot add the char in the map => start shrinking the map from the left until the char 
 * is found that is nums[r+1]  
 * Time Complexity = O(N + N)
 *
 * There is a better more optimised solution => keep a track of the last index of where it appeared 
 * and then when a char appears that has a last index => so we cannot expand further so simply 
 * shrink the window to the lastIndex of nums[r+1] + 1
 * Time Complexity = O(N)
 */

class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int n = s.length();

        vector<int> lastIndex(128, -1);
        // lastIndex[x] is the last index of where x was 

        int l = 0, res = 0;

        for(int r = 0; r < n; r++) {
            // cant expand the string as the lastIndex of s[r] is within the window
            if(lastIndex[s[r]] >= l) {
                l = lastIndex[s[r]] + 1;
            }

            lastIndex[s[r]] = r;

            res = max(res, r-l+1);
        }

        return res;
    } 
};