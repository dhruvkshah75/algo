#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "./L4_Q1_solution.cpp"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, q, l, r, p, k;
    cin>>t; //Number of Testcases

    while(t--)
    {
        cin >> n; // For each Testcase, read array size
        cin >> q;
        vector<int> A(n);   
        vector<vector<int>> queries(q); 

        for (int i=0; i<n; i++)
        {
            cin >> A[i]; // Read array elements
        }

        for(int i = 0; i < q; i++) {
            cin >> l >> r >> p >> k;  // Read queries
            queries[i] = {l, r, p, k};  
        }

        vector<int> ans = solve(n, q, A, queries); //Solve testcase

        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
        }
    }

    return 0;
}