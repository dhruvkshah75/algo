#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/35/C

vector<pair<int,int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve(int n, int m, vector<pair<int,int>> &start) {
    // apply multi source bfs on all the trees and update the mat with level of each tree 
    int k = start.size();

    // array is 1 based 
    vector<vector<int>> dist(n+1, vector<int>(m+1, -1));   // this array holds the levels 
    queue<pair<int,int>> q;

    pair<int,int> lastBurn;
    // now push the starting points 
    for(auto [x, y]: start) {
        q.push({x, y});
        dist[x][y] = 0;
        lastBurn = {x, y};
    }

    int level = 1;
    int maxLevel = 0;

    // multi source BFS 
    while(!q.empty()) {
        int qSize = q.size();
        while(qSize--) {
            auto [i, j] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni < 1 || nj < 1 || ni >= n+1 || nj >= m+1 || dist[ni][nj] != -1) continue;

                q.push({ni, nj});
                dist[ni][nj] = level;

                if(level > maxLevel) {
                    maxLevel = level;
                    lastBurn = {ni, nj};
                }
            }
        }
        level++;
    }

    cout << lastBurn.first << " " << lastBurn.second << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    
    // these are our starting points 
    int k;
    cin >> k;

    vector<pair<int,int>> start(k);

    for(auto &[x, y]: start) 
        cin >> x >> y;

    solve(n, m, start);
}