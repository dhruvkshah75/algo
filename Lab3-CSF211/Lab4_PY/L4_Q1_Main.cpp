#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "./L4_Q1_2024A7PS0499G.cpp" //Don't modify this line. Don't modify this program

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t > 0)
    {
        t--;
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }

        cout << solve(v) << endl;
    }
    return 0;
}
