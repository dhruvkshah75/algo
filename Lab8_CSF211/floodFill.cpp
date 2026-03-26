#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/flood-fill/description/

// a simple question on bfs

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size(), n = image[0].size();

    // apply bfs from the starting position and until the neighbors can be done 
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    // start from the starting node
    q.push({sr, sc});

    int curColor = image[sr][sc];
    // define the direction vector 
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // BFS
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        // update to the new color => the queue contains only those nodes which are valid
        image[i][j] = color;

        for(auto [dx, dy]: dirs) {
            int ni = i + dx;
            int nj = j + dy;
            if(ni >= 0 && nj >= 0 && ni < m && nj < n && image[ni][nj] == curColor && !visited[ni][nj]) {
                q.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
    }

    return image;
}
