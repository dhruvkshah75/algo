#include<bits/stdc++.h>
using namespace std;

// if no of vertices are v and e edges then create a v*v matrix 
// if a[i][j] = 1 then the component i, j are connected 
// if graph is undirected then i, j = 1 then j, i is also connected 

/*
    Given input 
    N vertices M edges 
    and the following M lines are edges
    N = 6 , M = 9
    1 3
    1 5 
    3 5
    3 4
    3 6
    3 2
    2 6
    4 6
    5 6

    if edges are weighted then a[i][j] = wt 
*/

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
        // as the graph is undirected 
    }
    // space complexity - O(N^2);
    // if no of vertices are 10^6 the code fails 

}
