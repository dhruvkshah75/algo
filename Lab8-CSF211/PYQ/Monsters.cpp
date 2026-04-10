#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;


void solve(int n, int m, vector<string> &grid) {
    // initially apply multi source bfs on monsters to get the min time taken by the monster to reach [i][j] cell 
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for(int i = 0; i < n; i++) 
        cin >> grid[i];

    solve(n, m, grid);
}