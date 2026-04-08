#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;


void solve(int n, int m, vector<vector<uint8_t>> &grid) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<uint8_t>> grid(n, vector<uint8_t>(m));
        // uint8_t => 8 bits unsigned int

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                cin >> grid[i][j];

        solve(n, m, grid);
        
    }
}