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
// #define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 
struct coin{
    int l, r, real;
};

bool cmp(const coin &a, const coin &b){
    return a.l < b.l;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<coin> casino(n);
    fx(i, n, 0){
        cin >> casino[i].l >> casino[i].r >> casino[i].real;
    }
    int coins = k;  
    sort(all(casino), cmp);

    fx(i, n, 0){
        if(coins >= casino[i].l && coins <= casino[i].r){
            coins = max(coins, casino[i].real);
        }
    }
    cout << coins << endl;
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