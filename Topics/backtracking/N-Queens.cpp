// ===================================================== backtracking =========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/n-queens/description/

/* Explanatiion: backtracking 
   To check if we can place the queen in the cell 
   it must node clash with the col, main diagnol and anti diagnol
   for the same diagnol => r+c remains constant and r-c remains constant 

   Using arrays is better than hash maps => as they are faster 
   as the size of the arrays would be constant 
   d1 => r-c => can go negative so do a shift => r-c + n-1
   d2 => r+c => can go till 2*n-2
*/

class Solution {
private:
    int n;
    vector<vector<string>> res;

    void f(vector<string> &curr, int r, vector<bool> &col, vector<bool> &d1, vector<bool> &d2) {
        // base case: when all queens are placed 
        if(r == n) {
            res.push_back(curr);
            return;
        }

        for(int c = 0; c < n; c++) {
            // we try placing the queen at (r, c)
            if(col[c] || d1[r-c + n-1] || d2[r+c]) continue;

            curr[r][c] = 'Q';
            col[c] = d1[r-c + n-1] = d2[r+c] = true;

            f(curr, r+1, col, d1, d2);
            // backtrack => unplace the queen at this position and try at a new place 

            col[c] = d1[r-c + n-1] = d2[r+c] = false;
            curr[r][c] = '.';
        }
        
        // return the case when no queen is placed in row r 
        return;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;

        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false), d1(2*n-1, false), d2(2*n-1, false);
        
        f(board, 0, col, d1, d2);

        return res;
    }
};


// ============================================== N Queens - II ============================================================

// question link: https://leetcode.com/problems/n-queens-ii/description/

/* Explanation: backtracking 
   same as N queens => instead of returning the board configs => we return the number of valid configurations 
   the logic is same => using col, d1, d2 to check if queen can be placed in a valid way 
*/

class Solution {
private:
    int n, res;

    void f(vector<string> &curr, int r, vector<bool> &col, vector<bool> &d1, vector<bool> &d2) {
        // base case: when all queens are placed => valid config found
        if(r == n) {
            res++;
            return;
        }

        for(int c = 0; c < n; c++) {
            // we try placing the queen at (r, c)
            if(col[c] || d1[r-c + n-1] || d2[r+c]) continue;

            curr[r][c] = 'Q';
            col[c] = d1[r-c + n-1] = d2[r+c] = true;

            f(curr, r+1, col, d1, d2);
            // backtrack => unplace the queen at this position and try at a new place 

            col[c] = d1[r-c + n-1] = d2[r+c] = false;
            curr[r][c] = '.';
        }
        
        // return the case when no queen is placed in row r 
        return;
    }

public:
    int totalNQueens(int n) {
        this->res = 0;
        this->n = n;

        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false), d1(2*n-1, false), d2(2*n-1, false);

        f(board, 0, col, d1, d2);

        return res;
    }
};