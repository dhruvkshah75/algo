#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include <sstream>
#include "./L7_Q2_solution.cpp"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t; //Number of Testcases

    while(t--)
    {
        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k to handle getline properly
    
        vector<vector<int>> nums(k);
        
        for (int i = 0; i < k; i++) {
            string line;
            getline(cin, line); // Read the entire line
            stringstream ss(line);
            int num;
            
            while (ss >> num) {
                nums[i].push_back(num); // Store numbers in the 2D vector
            }
        }
        vector<int> ans=solve(nums);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i];
            if(i==ans.size()-1)
                cout<<endl;
            else
                cout<<" ";
        }
    }

    return 0;
}
