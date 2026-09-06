#include "bits/stdc++.h"
#include "./L9_Q2_solution.cpp"
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        vector<int> wells(n);
        for(int i = 0; i < n; i++) cin >> wells[i];

        vector<vector<int>> pipes(m, vector<int>(3));
        for(int i = 0; i < m; i++) cin >> pipes[i][0] >> pipes[i][1] >> pipes[i][2];

        int ans = solve(n, m, wells, pipes);
        cout << ans << endl;
    }
}


