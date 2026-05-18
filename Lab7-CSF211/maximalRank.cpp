#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximal-network-rank/description/

/*
    We are supposed to get all the non overlapping roads between two vertices 
    the only case of overlapping is when a and b are adjacent to each other 
    we calculate the degree of each vertex and boolean matrix for checking 
    if edge between a and b exists in O(1) operation => and we check out all possible pairs for maximalRank 
*/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // firstly we make a adjacency list 
        vector<int> degree(n, 0);   // => store the degree of each vertex 

        // and a matrix for checking if a edge exists between a and b 
        vector<vector<bool>> mat(n, vector<bool>(n, false));

        int k = roads.size(); 

        for(int i = 0; i < k; i++) {
            // we add edges in for both road
            auto [a, b] = pair{roads[i][0], roads[i][1]};
            mat[a][b] = true;
            mat[b][a] = true;
            // now update the degree of a and b 
            degree[a]++; 
            degree[b]++;
        }

        int maximalRank = 0;

        // now we search for all the pairs and then get the max of it 
        for(int i = 0; i + 1 < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // i and j are the nodes 
                int rank = degree[i] + degree[j];
                if(mat[i][j])   
                    rank -= 1;

                maximalRank = max(maximalRank, rank);
            }
        }
        return maximalRank;
    }
};