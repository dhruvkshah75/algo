#include<bits/stdc++.h>
using namespace std;

// Simple BFS 
int min_knight_moves(const string& start_str, const string& end_str) {
    // define map for defining the 2d grid 
    // (1, 1) to (8, 8)

    unordered_map<char,int> mp;
    
    for(char c = 'a'; c <= 'h'; c++) {
        mp[c] = (int)(c - 'a' + 1);
    }

    int k = 1;
    for(char c = '8'; c >= '1'; c--) {
        mp[c] = k;
        k++;
    }

    // define the allowed movements of the knight from current position [i][j]
    vector<pair<int,int>> dirs = {
            {2, 1}, {2, -1},       // top movements
            {-2, 1}, {-2, -1},     // bottom movements
            {1, 2}, {-1, 2},       // right movements 
            {1, -2}, {-1, -2}      // left movements
    };

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(9, vector<bool>(9, false));

    q.push({mp[start_str[0]], mp[start_str[1]]});
    vis[mp[start_str[0]]][mp[start_str[1]]] = true;

    int moves = 0;

    while(!q.empty()) {
        int qSize = q.size();
        moves++;
        while(qSize--) {
            auto [i, j] = q.front();
            q.pop();

            if(mp[end_str[0]] == i && mp[end_str[1]] == j) return moves - 1; 

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni > 8 || nj > 8 || ni < 1 || nj < 1 || vis[ni][nj]) continue;

                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }

    return -1;
}
