
/*
******************************************************* B. Colourblindness *****************************************************************
                                                    time limit per test: 1 second
                                                    memory limit per test: 256 megabytes
Vasya has a grid with 2 rows and n columns. He colours each cell red, green, or blue.

Vasya is colourblind and can't distinguish green from blue. 
Determine if Vasya will consider the two rows of the grid to be coloured the same.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤100) — the number of columns of the grid.

The following two lines each contain a string consisting of n
characters, each of which is either R, G, or B, representing a red, green, or blue cell, respectively — the description of the grid.

Output
For each test case, output "YES" if Vasya considers the grid's two rows to be identical, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

*****************************************************************************************************************************************
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<string> v;
    for(int i=0; i<2; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }
    // RGB
    int count=0;
    for(int i=0; i<n; i++){
        if(v[0][i] == v[1][i]) count++;
        else if((v[0][i] == 'G' && v[1][i] == 'B') || (v[0][i] == 'B' && v[1][i] == 'G')) count++;
        else{
            cout << "NO" << endl;
            return;
        }
    }
    if(count == n) cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}