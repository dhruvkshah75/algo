#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279


/*
    in this question a b c are given 
    maximum_remove from c would be equal to c-b;
    diff = b-a;
    solve simple three equations are:
    z-->> amount added to the contianer b
    z + diff -->> amount added to container a 
    x is the amount removed from c
    x <= max_r
    y is the amount present in a, b, c after the operation
    and x = z + diff + z --->>> x = 2z + diff
    a + 2z + diff = y ------> 1
    b + z = y --------------> 2
    c - 2z - diff = y ------> 3
    on solving these 3 conditions we get the required 3 conditions

*/
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    // int max_r = c - b;
    // int diff = b - a;
    if((c-2*b+a)%3 == 0 && (a+b+c)%3 == 0 && (c+a-2*b) >= 0){
        yes;
        return;
    }
    no;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}