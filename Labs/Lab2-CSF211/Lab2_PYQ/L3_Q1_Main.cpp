#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "./L3_Q1_solution.cpp"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, K;
    cin>>t; //Number of Testcases

    while(t--)
    {
        cin >> n >> K; // For each Testcase, read array size
        vector<int> A(n);    
        for (int i=0; i<n; i++)
        {
            cin >> A[i]; // Read array elements
        }

        cout << solve(n, K, A); //Solve testcase
        cout << endl;
    }

    return 0;
}
