#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1292/A

// cant use DSU as we cant remove the edges 

void solve(int n, int q) {
    
    vector<vector<bool>> lava(3, vector<bool>(n+1, false));
    // [1][1] to [2][n]

    int badPairs = 0;

    auto countBad = [&](int r, int c) {
        int cnt = 0;

        // when r = 1 => [1][c] bad pair is formed by [2][c] or [2][c-1] or [2][c+1]
        int other = 3 - r;   // other = 2 when r = 1 or other = 1 and r = 2

        // check the three cells that can cause problem
        if(lava[other][c]) cnt++;   
        if(c > 1 && lava[other][c-1]) cnt++;
        if(c < n && lava[other][c+1]) cnt++;

        return cnt;
    };

    while(q--) {
        int r, c;
        cin >> r >> c;

        if(!lava[r][c]) {
            // convert this cell into lava
            badPairs += countBad(r, c);
            lava[r][c] = true;
        }
        else {
            // cell is lava => now convert it to ground 
            badPairs -= countBad(r, c);    
            lava[r][c] = false;
        }

        // now if bad pairs (blocking) are 0 then ans is yes 
        if(badPairs == 0) {
            yes;
        }
        else {
            no;
        }
    } 

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    solve(n, q);
}