// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

bool ok(int a1, int a2, int a3, int a4, int a5){
    if(a1 < a2 && a2 < a3 && a3 < a4 && a4 < a5) return true;
    if(a1 > a2 && a2 > a3 && a3 > a4 && a4 > a5) return true;
    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1);
    fx(i, n+1, 1){
        cin >> p[i];
    }
    bool flag = true;
    for(int i=1; i<=n-4; i++){
        if(!ok(p[i], p[i+1], p[i+2], p[i+3], p[i+4])) flag = false;
    }
    if(flag){
        fx(i, n, 0) cout << "L";
        cout << endl;
        return;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug_code
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}