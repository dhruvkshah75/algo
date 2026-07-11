// ====================================== greedy =========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/mice-and-cheese/description/

/**
 * Explanation: greedy + sorting 
 * What would best way to pick the cheese for mouse 1 
 * for the best k cheese types for mouse 1 to benefit would be to give the mouse 1 those 
 * k cheese types whose reward1 - reward2 is the most => this would be more beneficial 
 * */

class Solution {
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
        int n = reward1.size();
        // n types of different cheese 

        // store the reward for both the mouses as a pair 
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) 
        	v.push_back({reward1[i], reward2[i]});

        sort(v.begin(), v.end(), [&](const pair<int,int> &a, const pair<int,int> &b) {
        	// sort in dsc order of the diff of reward1 and reward2 
        	return (a.first - a.second) > (b.first - b.second);
        });

        // pick the first k cheese types for mouse 1 and the rest for mouse 2 
        int ans = 0;
        for(int i = 0; i < n; i++) {
        	if(i < k) ans += v.first;
        	else ans += v.second;
        }

        return ans;
    }
};