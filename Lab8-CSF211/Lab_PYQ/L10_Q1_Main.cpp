#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "./L10_Q1_solution.cpp"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, m;
    cin>>t; //Number of Testcases

    while(t--)
    {
        cin >> n; // For each Testcase, read array size
        cin >> m;
        vector<vector<int>> moveTime(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> moveTime[i][j];
            }
        }

        int ans = solve(moveTime); //Solve testcase

        cout << ans << endl;
    }

    return 0;
}