#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-islands/description/

// Solution using DFS 

void dfs(vector<vector<char>> &grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    // base case: when the node is not valid and it is equal to 1 
    if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] != '1')
        return;
    
    // now mark the current valid node as visited 
    grid[i][j] = 'V';

    // now call dfs for all its children 
    dfs(grid, i-1, j);
    dfs(grid, i, j-1);
    dfs(grid, i+1, j);
    dfs(grid, i, j+1);

    return;
}

int numIslands(vector<vector<char>>& grid) {
    // apply dfs on 1s and then count the no of times the dfs function is called 
    int m = grid.size(), n = grid[0].size();

    // instead of visited array => make the visited node as 'V' character 
    int count = 0;   // denotes the number of islands 

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}