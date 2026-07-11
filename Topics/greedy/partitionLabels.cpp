// ============================================= greedy ======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/partition-labels/description/

/** 
 * Explanation: greedy 
 * we can extend the same paritition until the max(last_occurence(char)) = end index of the window 
 * We must store the last ocurrence of characters by processing the string in reverse direction 
 * then the question becomes pretty obvious
 * */

class Solution {
public:
    vector<int> partitionLabels(string &s) {
        int n = s.length();

        vector<int> last_occ(26, -1);

        for(int i = n-1; i >= 0; i--) {
        	int idx = s[i]-'a';
        	if(last_occ[idx] == -1) last_occ[idx] = i;
        }

        // curr holds all chars that appear in the partition 
        vector<int> curr(26, 0), res;
        int len = 0, maxi = 0;

        for(int i = 0; i < n; i++) {
        	int idx = s[i]-'a';
        	curr[idx]++;
        	len++;
        	maxi = max(maxi, last_occ[idx]);

        	// partition is valid when max(last_occ(all chars in curr)) = index
        	if(maxi == i) {
        		curr.assign(26, 0);
        		res.push_back(len);
        		maxi = len = 0;
        	}
        }		
        // O(N)

        return res;
    }
};