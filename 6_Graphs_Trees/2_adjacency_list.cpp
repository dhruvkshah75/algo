#include<bits/stdc++.h>
using namespace std;

/*
    in adjacency list u u form N lists where N denotes the no of vertices 
    and for each list u store the no of vertices its connected to 

    // space complexity is O(V + E) where V is the no of vertices and E is the no of edges 

    // weighted edges in the graphs using adjacency list then use 
    vector<pair<int,int>> graph[N];  where N is the no of vertices 
    graph[v1].push_back({v2, wt});
*/

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> graph[n]; // array of vectors 
    
    for(int i=0; i<m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    // O(n+m) is the space complexity 
    // 
}