#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/616/C
/* 
    similar to making a large island => using similar logic 
    instead of going through all the '*' and making them as empty cell and calculating the no of empty cells connected 
    we apply bfs on the existing empty cells and mark each connected section of empty cells with a label and store the number
    of connected empty cells for each section and then after visiting each '*' we caculate the required value 
    by looking at the neigbours
*/


vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
unordered_map<int,int> mark;

void bfs(vector<string> &grid, const pair<int,int> &node, int label, vector<vector<int>> &visited) {
    int n = grid.size(), m = grid[0].length();

    queue<pair<int,int>> q;
    q.push(node);
    // mark the node with the label 
    visited[node.first][node.second] = label;

    // we have to store the count of empty cell that are connected to this current node 
    int cnt = 1;  

    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for(auto [dx, dy]: dirs) {
            int ni = i + dx, nj = j + dy;
            if(ni >= n || nj >= m || ni < 0 || nj < 0) continue;
            
            if(grid[ni][nj] == '.' && visited[ni][nj] == 0) {
                cnt++;
                q.push({ni, nj});
                visited[ni][nj] = label;   // mark the cell(visited) with the current label 
            }
        }
    }

    mark[label] = cnt;
}


void solve(vector<string> &grid, int n, int m) {
    // apply bfs on the empty cells and calculate the extend of each connected component 
    int label = 1;

    vector<vector<int>> visited(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == 0 && grid[i][j] == '.') {
                bfs(grid,{i, j}, label, visited);
                label++;
            }
        }
    }

    // now we calculate the values for each '*'
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != '*') continue;

            // now we get the all the '.' (empty cell) neigbours from the visited and calculate the value
            int temp = 1;
            unordered_set<int> seenNbg;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= n || nj >= m || ni < 0 || nj < 0) continue;

                int currlabel = visited[ni][nj];
                if(visited[ni][nj] != 0 && seenNbg.find(currlabel) == seenNbg.end()) {
                    temp += mark[currlabel];
                    seenNbg.insert(currlabel);
                }
            }

            temp %= 10;
            cerr << temp << endl;
            grid[i][j] = (char)(temp + '0');
        }
    }

    // now print the result;
    for(int i = 0; i < n; i++) {
        cout << grid[i] << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    solve(grid, n, m);

}