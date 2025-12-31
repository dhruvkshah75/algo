// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}

void solve(){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if(a == b){
        cout << 0 << endl;
        return;
    }
    if(a>b){
        int diff = a-b;
        if(a%2==0 || (a%2!=0 && diff > 1)){
            cout << -1 << endl;
            return;
        }
        if(a%2!=0 && diff==1){
            cout << y << endl;
            return;
        }
    }
    else{
        ll cost = 0;
        while(a!=b){
            if(a%2 == 0) cost += min(x, y);
            if(a%2!=0) cost += x;
            a++;
        }
        cout << cost << endl;
        return;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}