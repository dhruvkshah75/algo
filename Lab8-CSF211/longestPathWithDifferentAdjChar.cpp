#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/

// classic question to calculate the diameter of the tree with some modifications 


// A path through a node looks like: left_arm → node → right_arm
class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        // 0 is the root node 
        int n = parent.size();

        vector<vector<int>> adjL(n);

        for(int i = 1; i < n; i++) {
            int node = i;
            // parent[node] is the top node and node is it child
            adjL[parent[node]].push_back(node);
        }

        dfs(0, adjL, s);
        return ans;
    }
private:
    int ans = 1;

    // classic diameter of a tree calculation 
    // the best 2 paths must be connected via the root => if not then we only the best path 
    int dfs(int node, vector<vector<int>>& adjL, string &s) {
        // the best two paths 
        int best1 = 0, best2 = 0; 

        for(int child: adjL[node]) {
            int arm = dfs(child, adjL, s);
            // can't use this arm as both node and child have the same char 
            if(s[node] == s[child]) arm = 0; 

            // update 2 best longest paths from the root and both of them are connected
            if(arm >= best1) { 
                best2 = best1; 
                best1 = arm; 
            }
            else if(arm > best2) { 
                best2 = arm; 
            }
        }

        // longest path through this node
        ans = max(ans, best1 + best2 + 1);

        return best1 + 1; // return best arm upward (as we use it to update the vaue later )
    }
};