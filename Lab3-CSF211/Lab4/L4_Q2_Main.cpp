#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "./L4_Q2_solution.cpp"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, q;
    cin>>t; //Number of Testcases

    while(t--)
    {
        cin >> n >> q; // For each Testcase, read array size
        vector<int> A(n);    
        vector<int> queries(n);    
        for (int i=0; i<n; i++)
        {
            cin >> A[i]; // Read array elements
        }
        for(int i = 0; i < q; i++) {
            cin >> queries[i];
        }

        vector<bool> ans = solve(n, q, A, queries); //Solve testcase

        for(int i = 0; i < ans.size(); i++) {
            if (ans[i]) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
            cout << (i == ans.size() - 1 ? "\n" : " ");
        }
    }

    return 0;
}
