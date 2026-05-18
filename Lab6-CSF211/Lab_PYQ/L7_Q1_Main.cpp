#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "./L7_Q1_solution.cpp"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t; //Number of Testcases

    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> nums;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            nums.push_back(num);
            
        }
        vector<int> ans=solve(nums,k);
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