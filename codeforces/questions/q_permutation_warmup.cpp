#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main() {
    int tt; 
    cin >> tt;
    while (tt--){
        ll n;
        cin>>n;
        ll k=n/2;
        if (n%2) cout << k*(k+1)+1 << endl;
        else cout << k*k+1 << endl;
    } 
}