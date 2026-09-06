#include<bits/stdc++.h>
using namespace std;

// question link: 

/* 
    we can apply bfs to get the minimum number of moves to reach the desired output
    Note:
    1. Insert when we have match in colour from the hand
    2. Insert when the colour from the hand if two consecutive colors appear (RR, BB)
*/
class Solution {
public:
    int findMinStep(string board, string hand) {
        // since minimum number of balls to insert is mentioned => apply bfs guarantees shortest path
        int n = board.length(), m = hand.length();

        // BFS on strings => to cover all valid possiblities 

    }
};