#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "./L9_Q1_solution.cpp"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t; //Number of Testcases
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> edges;
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            vector<int> temp={u,v};
            edges.push_back(temp);
        }
        vector<int> topoSort;
        while(n--)
        {
            int t;
            cin>>t;
            topoSort.push_back(t);
        }
        vector<int> result=solve(edges,topoSort);
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i];
            if(i==result.size()-1)
                cout<<endl;
            else
                cout<<" ";
        }
    }
    return 0;
}