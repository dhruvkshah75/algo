#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/surrounded-regions/description/

/*
    The only catch was to recognize that we must start with all the Os located on the edges 
    and see which Os could be traversed through these Os if bfs was applied on all the starting nodes 
*/

// =============================================================================
//                     Solution using BFS 
// ============================================================================= 

// we can avoid the use of visited array by marking all the visited O nodes as S 
void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();

    queue<pair<int,int>> q;

    // we push all the edge Os as the starting point => the Os not accessed by them can be converted 
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'O' && (i == 0 || j == 0 || i == m-1 || j == n-1)) {
                q.push({i, j});
                board[i][j] = 'S'; // mark the node as S
            }      
        }
    }
    // queue contains the Os at the edge and then apply bfs on all of them and stop if X is encountered 
    // the Os which were never visited can be converted into X
    vector<pair<int,int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // BFS 
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        // visit the neigbours of the current node and push only if it is O
        for(auto [dx, dy]: dirs) {
            int ni = i + dx;
            int nj = j + dy;
            if(ni >= 0 && nj >= 0 && ni < m && nj < n) {
                if(board[ni][nj] == 'O') {
                    q.push({ni, nj});
                    board[ni][nj] = 'S';
                }
            }
        }
    }

    // now convert all the O nodes which are not visited => these would be in the surrounded regions 
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'O') board[i][j] = 'X';
            else if(board[i][j] == 'S') board[i][j] = 'O';
            // convert back those Os which were marked as Os
        }
    }

}



// ======================================================================================
//                              Solution using DFS 
// ======================================================================================

void surroundedRegions(vector<vector<char>> &board) {
    
}