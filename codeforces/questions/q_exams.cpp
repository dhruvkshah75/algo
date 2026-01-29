#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> m ={2, 3, 4, 5};
    int n, k;
    cin >> n >> k;
    if(k<3*n) cout << 3*n-k << endl;
    else if(k<=5*n && k >= 3*n) cout << 0 << endl;
    

}