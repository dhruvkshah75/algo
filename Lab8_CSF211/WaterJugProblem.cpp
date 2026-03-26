#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/water-and-jug-problem/description/
// VERY IMPORTANT Q on BFS 

/*
    In this question we consider a 2d matrix of size x+1 * y+1. We just are suppose to check if we can reach 
    the cell [i][j] such that i + j = target. Here are starting point is [0][0] both jugs empty 
    The allowed movements are filling x, filling y, emptying x, emptying y and then transferring from one jug to the other 
    Apply bfs on this with the starting point [0][0] 

*/

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // note for simplicity keep x as the max and y as the min 
        if (x < y) swap(x, y);
        // base cases 
        if (target > x + y) return false;
        if (target == 0) return true;

        // we consider a 2d matrix => starting point as [0][0] and then reach a point [i][j] such that i + j = target 

        // we can apply bfs start from [0][0] so push in the queue 
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;

        q.push({0, 0});
        visited.insert({0, 0});

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if(i + j == target || i == target || j == target) 
                return true;

            // all possible next states => Fill X, Fill Y, Empty X, Empty Y, Pour X into Y and vice versa
            vector<pair<int,int>> next_states = {{x, j}, {i, y}, {0, j}, {i, 0},      
                // Pour X into Y and Pour Y into X
                {i - min(i, y-j), j + min(i,y-j)}, {i + min(j, x-i), j - min(j, x-i)}};

            for(auto &state : next_states) {
                if(visited.find(state) == visited.end()) {
                    visited.insert(state);  // update the visited status 
                    q.push(state);
                }
            }
        }

        return false;
    }
};