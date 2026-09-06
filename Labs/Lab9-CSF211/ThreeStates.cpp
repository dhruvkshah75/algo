#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

const int mod = 1e9+7;
const int inf = 1e8;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x), x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/590/C

vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// 0 - 1 BFS 
vector<vector<int>> bfs(int n, int m, vector<string> &grid, int currState) {

    deque<pair<int,int>> dq;
    // dq = {i, j} => use a deque so we can push the state cells in the front 

    vector<vector<int>> dist(n, vector<int>(m, inf));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == (char)(currState + '0')) {
                dq.push_back({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while(!dq.empty()) {
        auto [i, j] = dq.front();
        dq.pop_front();

        for(auto [dx, dy]: dirs) {
            int ni = i + dx, nj = j + dy;
            if(ni >= n || nj >= m || ni < 0 || nj < 0 || grid[ni][nj] == '#') continue;

            int cost = (grid[ni][nj] == '.') ? 1 : 0;

            if(dist[i][j] + cost < dist[ni][nj]) {
                // update the dist[ni][nj] with the newer cost
                dist[ni][nj] = dist[i][j] + cost;
                // if the next cell is not '.' then push this cell in the front 
                if(cost == 0) dq.push_front({ni, nj});
                else dq.push_back({ni, nj});
            }
        }
    }

    return dist;
}

void solve(int n, int m, vector<string> &grid) {
    // apply bfs on 1s 2s 3s to get to each other by moving through '.'

    // dist array for each state stores the min roads to build to reach every cell 
    // APPLY 0-1 BFS using DEQUE

    /*  NOTE:
        instead of finding the distance from city A to city B and then city B to city C and build 2 roads 
        Rather than that we can have a better way => where we build 3 short roads where all the roads meet at a hub
        in the middle of nowwhere which can be more efficient */

    auto d1 = bfs(n, m, grid, 1);
    auto d2 = bfs(n, m, grid, 2);
    auto d3 = bfs(n, m, grid, 3);

    ll min_roads = inf;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(d1[i][j] == inf || d2[i][j] == inf || d3[i][j] == inf) continue;

            ll curr = d1[i][j] + d2[i][j] + d3[i][j];

            // if the meeting point is '.' then we counted '.' cell 3 times => we only need to build one road 
            if(grid[i][j] == '.') curr -= 2;

            min_roads = min(min_roads, curr);
        }
    }

    if(min_roads >= inf) cout << -1 << endl;
    else cout << min_roads << endl; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for(string &str: grid) 
        cin >> str;

    solve(n,m, grid);
}