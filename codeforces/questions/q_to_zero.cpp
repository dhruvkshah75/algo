#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279

// odd - odd -->> even and even - even -->> even 

void solve(){
    int n, k;
    cin >> n >> k;   // k is always odd
    int ans = 0;
    if(n%2 != 0){
        n -= k;
        ans = 1;
    }
    k -= 1;
    ans += (int)ceil((double)n/(k));        // so the no after one operation will become even or if the no is even then it will remain even
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