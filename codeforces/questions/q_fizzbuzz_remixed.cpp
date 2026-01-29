#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    ans += (int)ceil((double)n/15);
    int add1 = (int)ceil((double)(n-1)/15);
    if(add1 >= 0) ans += add1;
    int add2 = (int)ceil((double)(n-2)/15);
    if(add2 >= 0) ans += add2;
    if((n-1)%15 == 0 || (n-2)%15 == 0 || n%15 == 0) ans+=1;  
    // this step is needed because if a n-1, n-2, n is a multiple of 15 it skips the no because of ceil

    cout << ans << endl;
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