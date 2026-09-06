#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-the-town-judge/description

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // [a, b] => a trusts b => make a directed arrow from a to b 
        // Town Judge is the one with 0 outdegree and n - 1 indgree => all trust him 
        int k = trust.size();

        vector<int> outdegree(n+1, 0), indegree(n+1, 0); // 1 based nodes 

        for(int i = 0; i < k; i++) {
            // a has outdegree and b has indegree 
            outdegree[trust[i][0]]++;
            indegree[trust[i][1]]++; 
        }

        // now find the town judge => from 1 to n 
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == n - 1 && outdegree[i] == 0)
                return i; 
        }

        return -1;
    }
};