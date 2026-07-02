// ===================================================== dfs + backtracking =============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/word-search/description/

/* Explanation: dfs + backtracking 
   here we use dfs to start exploring the matrix and use search pruning (stop exploring when we know we cant get a valid answer)
   basically match the character by index and when no character adjacent to it is found then dont further explore 

   dfs(i, j, ind) => match the current char word[ind] and then only move to the next character and explore all paths 
   
   Backtracking logic:

   vis[i][j] = true;
   // explore
   vis[i][j] = false;
*/

class Solution {
private: 
    int m, n, len;

    bool dfs(int i, int j, int ind, vector<vector<char>> &board, string &word, vector<vector<bool>> &vis) {
        // base case: word found => all characters of word matched 
        if(ind == len) return true;

        // base case: invalid cell or char not matching 
        if(i >= m || i < 0 || j >= n || j < 0 || word[ind] != board[i][j]) return false;

        if(vis[i][j]) return false;

        vis[i][j] = true;

        // explore all possible paths 
        bool res = dfs(i+1, j, ind+1, board, word, vis) ||
                   dfs(i-1, j, ind+1, board, word, vis) || 
                   dfs(i, j+1, ind+1, board, word, vis) || 
                   dfs(i, j-1, ind+1, board, word, vis);

        // backtrack => unmark the node as the node can be used for some other path 
        vis[i][j] = false;

        return res;
    }

public:
    bool exist(vector<vector<char>> &board, string &word) {
        m = board.size();
        n = board[0].size();
        len = word.length();

        // start dfs from the firstChar 

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && dfs(i, j, 0, board, word, vis)) {
                    return true;
                }
            }
        }
        
        // did not find the word 
        return false;
    }
};