#include<bits/stdc++.h>
using namespace std;

// quuestion link: https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();

        // the hash table for key must exist and for string it does 
        unordered_map<string,vector<string>> mp;
        // the map stores the key as lexicographically sorted string with all those 

        for(string &s: strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }

        vector<vector<string>> result;

        for(auto &[key, strings]: mp) {
            result.push_back(strings);
        }

        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> strs(n);

    for(int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution s = Solution();

    vector<vector<string>> result = s.groupAnagrams(strs);

    for(vector<string> &strings: result) {
        for(string &s: strings) {
            cout << s << " ";
        }
        cout << endl;
    }
    cout << endl;
}