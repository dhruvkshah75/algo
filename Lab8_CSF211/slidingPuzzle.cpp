#include<bits/stdc++.h>
using namespace std;

// question link: 

/*
    Algorithm:
    VERY IMPORTANT QUESTION 
        In this we convert the 2x3 board into a flattended string and then we make a adjL not like the normal one 
        but where it stores the indexes of neighbours of each index in the string 
        the indexes of the string in 2x3 board 
        0 1 2
        3 4 5
        for index 0 => {1, 3}, 1 => {0, 2, 4}, 2 => {1, 5}, 3 => ..
        storing indexes helps us as we would be swapping the positions with 0 

        Here we start with the current config start string and then after swapping and push the newState in the queue
*/

// BFS guarantees that the first time you reach the target state, it's via the minimum number of swaps 
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // board is 2x3 matrix 
        // nodes are the boards, edges are adjacent boards 

        // neighbors of each position in flattened 2x3 board => these are the indexes in 2x3 matrix
        vector<vector<int>> adjL = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        // convert the current board to string as it will be easy to match 
        string target = "123450";
        string start = "";

        for(int i = 0; i < 2; i++) 
            for(int j = 0; j < 3; j++) 
                start += to_string(board[i][j]);
            
        // if no changes are required 
        if(start == target) return 0;

        queue<pair<string,int>> q;   // {state, moves} => states the current string state 
        unordered_set<string> visited;  

        // push the starting front and mark as visited
        q.push({start, 0});
        visited.insert(start);

        // BFS 
        while(!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            int zeroPos = curr.find('0');  // get the index of 0 so we can swap it with its neighbours 

            // now try switching all the allowed positions 
            for(int nbg: adjL[zeroPos]) {
                string newState = curr;
                swap(newState[zeroPos], newState[nbg]);
                // we swap the position of 0 with the this nbg
                if(newState == target) return moves + 1;

                if(visited.find(newState) == visited.end()) {
                    q.push({newState, moves + 1});
                    visited.insert(newState);
                }

            }
        }

        return -1;
    }
};