// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()

void solve(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int sum = a + b + c;
    int ans = 3*(n/sum);       
    int rem = n%sum;             

    if(rem == 0) cout << ans << endl;
    else if(rem <= a) cout << ans + 1 << endl;
    else if(rem <= a + b) cout << ans + 2 << endl;
    else cout << ans + 3 << endl; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--)
        solve();
    
}