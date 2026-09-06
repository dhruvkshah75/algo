#include<bits/stdc++.h>
using namespace std;

// question: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

// Question based on directed graph on indegree and outdegree 

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // we have n nodes numbered from 0 to n - 1
        int k = edges.size(); 
        // the vertices that are needed are the ones whose indegree is 0 
        // that is no edges enter into that node so we need to include into the ans 
        vector<int> result; 
        vector<int> outdegree(n, 0);  // 1 based indexing 

        for(int i = 0; i < k; i++) {
            int to = edges[i][1];
            // the edges enter into to 
            outdegree[to]++;
        }

        for(int i = 0; i < n; i++) {
            if(outdegree[i] == 0)
                result.push_back(i);
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    // n is the number of nodes and k is the no of edges 

    vector<vector<int>> edges(k, vector<int>(2));

    for(int i = 0; i < k; i++)
        cin >> edges[i][0] >> edges[i][1];

    Solution s = Solution();

    vector<int> result = s.findSmallestSetOfVertices(n, edges);

    for(int &ans: result) 
        cout << ans << " ";
    cout << endl;
}