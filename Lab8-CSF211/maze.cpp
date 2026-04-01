#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/377/A
// we simply cutoff the leaf nodes in the dfs traversal 

vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(vector<vector<char>> &maze, vector<vector<bool>> &visited, int i, int j, int &k) {
    int n = maze.size(), m = maze[0].size();

    // base case 
    if(i >= n || j >= m || i < 0 || j < 0 || maze[i][j] != '.' || k <= 0 || visited[i][j])
        return;
    
    // mark the node
    visited[i][j] = true;

    // call dfs on neigbours 
    dfs(maze, visited, i-1, j, k);
    dfs(maze, visited, i+1, j, k);
    dfs(maze, visited, i, j+1, k);
    dfs(maze, visited, i, j-1, k);

    if(k <= 0) return;
    
    // we can change this node if this is the leaf node in dfs traversal 
    // => which means no further nodes that we can go from here => leaf node 

    int unvisitedNbgs = 0;
    for(auto [dx, dy]: dirs) {
        int ni = i + dx, nj = j + dy;
        if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;

        if(maze[ni][nj] == '.' && !visited[ni][nj])
            unvisitedNbgs++;
    }

    // leaf node in DFS tree = no unvisited empty neighbors = safe to remove
    if(unvisitedNbgs == 0) {
        maze[i][j] = 'X';
        k--;
    }

    return;
}


void solve(vector<vector<char>> &maze, int k) {
    int n = maze.size(), m = maze[0].size();

    // we can put a wall on the leaf nodes of dfs traversal as there are no more nodes after that
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // apply dfs from the first empty cell that we get 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == '.') {
                dfs(maze, visited, i, j, k);
                break;
            }
        }
    }

    // now print the ans 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> maze(n, vector<char>(m));

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            cin >> maze[i][j];


    solve(maze, k);

}