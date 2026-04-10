#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "./L10_Q2_solution.cpp"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, m, a, b, c;
    cin>>t; //Number of Testcases

    while(t--)
    {
        cin >> n >> m; // For each Testcase, read array size
        vector<vector<int>> flights(m, vector<int>(3));
        
        for(int i = 0; i < m; i++) {
            // scanf("%d %d %d", &flights[i][0], &flights[i][1], &flights[i][2]);
            cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
        }
        
        
        vector<long long> ans = solve(n, m, flights);
        for(auto it: ans) {
            cout << it << " ";
        }
        cout << endl;

        // vector<long long> ans = solve(n, m, flights);
        // printf("%lld %lld %lld %lld \n", ans[0], ans[1], ans[2], ans[3]);
    }


    return 0;
}
