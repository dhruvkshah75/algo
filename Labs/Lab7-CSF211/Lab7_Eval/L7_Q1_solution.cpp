#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, std::vector<std::pair<int, int>> &edges) {
    // apply brute force on all three edges 
    // n is the no of nodes and m is the no of edges 
    vector<vector<bool>> adjMat(n+1, vector<bool>(n+1, false));

    for(int i = 0; i < m; i++) {
        auto [u, v] = edges[i];
        adjMat[u][v] = adjMat[v][u] = true;
    }

    unordered_set<int> vertices;

    // now traverse through each vertex and check if vertices are forming Triangle 
    for(int i = 1; i <= n; i++) {
        // now traverse through the ith row 
        int x = i;
        for(int j = 1; j <= n; j++) {
            if(adjMat[x][j] == false) continue;
            int y = j;
            // now x and y share a edge and now find a edge 
            for(int k = j + 1; k <= n; k++) {
                if(adjMat[x][k] == false) continue;
                int z = k;
                // x -> y, z and y-> x, check for z 
                if(adjMat[y][z]) {
                    vertices.insert(x);
                    vertices.insert(y);
                    vertices.insert(z);
                }
            }
        }
    }

    return (int)vertices.size();
}