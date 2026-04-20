#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x), x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/329/B/

vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(int r, int c, vector<string> &grid) {
    // VERY IMPORTANT BFS Question => apply bfs starting from the Exit 
    // any breeder who can reach the exit faster than me will fight me 

    vector<vector<int>> dist(r, vector<int>(c, INT_MAX));

    pair<int,int> start;

    for(int i = 0; i < r; i++) 
        for(int j = 0; j < c; j++) 
            if(grid[i][j] == 'E') { start = {i, j}; break; }

    queue<pair<int,int>> q;

    int distance = 0;

    q.push(start);
    dist[start.first][start.second] = 0;

    pair<int,int> myPos;

    while(!q.empty()) {
        distance++;
        int qSize = q.size();

        while(qSize--) {
            auto [i, j] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni < 0 || nj < 0 || ni >= r || nj >= c || grid[ni][nj] == 'T') continue;

                if(distance < dist[ni][nj]) {
                    dist[ni][nj] = distance;
                    q.push({ni, nj});
                }

                if(grid[ni][nj] == 'S') 
                    myPos = {ni, nj};
            }
        }
    }

    // now with my current Pos compare it with other breeders 
    int battles = 0;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] >= '0' && grid[i][j] <= '9') {
                if(dist[i][j] <= dist[myPos.first][myPos.second]) 
                    battles += (int)(grid[i][j] - '0');
            }
        }
    }

    cout << battles << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<string> grid(r);

    for(string &s: grid) 
        cin >> s;

    solve(r, c, grid);
}