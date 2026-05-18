#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/battleships-in-a-board/description/

// Also solve the follow up where we use O(1) space without modifying the board vector that is given to us 

void dfs(vector<vector<char>> &board, int i, int j) {
    // base case: when the [i][j] is invalid or is not to be visited 
    int m = board.size(), n = board[0].size();
    if(i >= m || j >= n || i < 0 || j < 0 || board[i][j] != 'X')
        return;

    // mark the current node as visisted change from X to V 
    board[i][j] = 'V';

    dfs(board, i-1, j);
    dfs(board, i+1, j);
    dfs(board, i, j+1);
    dfs(board, i, j-1);

    return;
}


int countBattleships(vector<vector<char>>& board) {
    // same question as number of islands 
    int m = board.size(), n = board[0].size();

    // instead of using a visited array update the board with 'V'
    int count = 0;

    // apply dfs on non visited X's
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'X') {
                count++;
                dfs(board, i, j);
            }
        }
    }

    return count;
}
