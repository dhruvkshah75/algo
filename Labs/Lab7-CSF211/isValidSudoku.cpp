#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/valid-sudoku/description/ 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // first we verify each of the 3x3 parts 
        unordered_set<char> set;

        // each 3x3 has j = 0 to 2 
        for(int r = 0; r < 3; r++) {
            // covers all the 3x3 in the horizontal direction 
            for(int c = 0; c < 3; c++) {
                // now for each board 
                for(int i = 3*r; i < 3*r + 3; i++) {
                    for(int j = 3*c; j < 3*c + 3; j++) {
                        char x = board[i][j];
                        if(x >= '1' && x <= '9') {
                            if(set.find(x) != set.end())
                                return false;
                            else 
                                set.insert(x);
                        }
                    }
                }
                // reset the set after each board 
                set.clear();
            }
        }
        set.clear();

        // now we check each col and row by traversing through the 9 diagnols 
        for(int i = 0; i < 9; i++) {
            // check for the column => vary the row
            for(int row = 0; row < 9; row++) {
                char x = board[row][i];
                if(x >= '1' && x <= '9') {
                    if(set.find(x) != set.end())
                        return false;
                    else 
                        set.insert(x);
                }
            }
            set.clear();
            // now check for the ith row by varying cols 
            for(int col = 0; col < 9; col++) {
                char x = board[i][col];
                if(x >= '1' && x <= '9') {
                    if(set.find(x) != set.end())
                        return false;
                    else 
                        set.insert(x);
                }
            }
            set.clear();
        }

        return true;
    }
};