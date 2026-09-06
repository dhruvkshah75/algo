#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "./L4_Q2_2024A7PS0499G.cpp" //Don't modify this line. Don't modify this program

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector< pair<int,int> > farm(m);
    for (int i=0; i<m; i++) {
        cin >> farm[i].first >> farm[i].second;
    }

    cout << solve(n, m, farm) << endl;

    return 0;
}
