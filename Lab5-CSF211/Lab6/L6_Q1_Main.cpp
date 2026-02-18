#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "./L6_Q1_solution.cpp"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> temperatures(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temperatures[i];
    }

    vector<int> result = solve(temperatures);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
