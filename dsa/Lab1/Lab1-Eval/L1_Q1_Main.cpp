#include <bits/stdc++.h>
#include "./L1_Q1_solution.cpp"

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> intervals(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            cin >> intervals[i][0] >> intervals[i][1];
        }

        vector<vector<int>> result = solve(intervals);

        for (const auto& interval : result)
        {
            cout << interval[0] << " " << interval[1] << endl;
        }
    }

    return 0;
}