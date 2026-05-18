#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/description/

/*
    This is the modified version of Eval Lab7 
    In this question we must find the minDegree of trio which is the minimum degree of the nodes of the trio 
    apart from the other two nodes of the trio 
    minDegree of a trio would be degree[x] + degree[y] + degree[z] - 6 => the -6 factor is for removing the trio 
    edges shared among them 
*/


int minTrioDegree(int n, vector<vector<int>>& edges) {
    int m = edges.size();
    // apply brute force on all three edges 
    // n is the no of nodes and m is the no of edges 
    vector<vector<bool>> adjMat(n+1, vector<bool>(n+1, false));

    vector<int> degree(n+1, 0);

    for(int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1];
        adjMat[u][v] = adjMat[v][u] = true;
        degree[u]++;
        degree[v]++;
    }

    // degree of trio is min degree of trio (apart from trio elements)
    int minDegree = INT_MAX;
    bool found = false;
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
                    // x y z forms a triangle 
                    found = true;
                    int temp = degree[x] + degree[y] + degree[z] - 6;
                    // -6 to get rid of degrees of inter connected degrees
                    minDegree = min(minDegree, temp);
                }
            }
        }
    }
    return (found) ? minDegree : -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m; 
    // n nodes and m edges

    vector<vector<int>> edges;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    int result = minTrioDegree(n, edges);

    cout << result << endl;
}