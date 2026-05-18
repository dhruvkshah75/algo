#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/longest-common-prefix/description/
// EASY Leetcode Question

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        int n = strs.size();
        int i = 0;
        while(true) {
            if(strs[0].size() == i) return str;  // if the first string runs out of characters 
            bool check = true;
            for(int j=1; j<n; j++) {
                if(strs[j].size() == i) return str;  // if any string other than the 1st one runs out of chars
                if(strs[j][i] != strs[0][i]) check = false;
            }
            if(!check) return str;
            else str += strs[0][i];
            i++;
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);

    for(int i=0; i<n; i++) {
        cin >> strs[i];
    }

    Solution s = Solution();
    cout << s.longestCommonPrefix(strs) << endl;
}