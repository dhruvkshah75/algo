#include <bits/stdc++.h>
#include "./L1_Q2_solution.cpp"

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        vector<int> result = solve(nums);

        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i];
            if (i < result.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
