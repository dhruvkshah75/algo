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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> h(n+1);
    fx(i, n+1, 1){
        cin >> h[i];
    }
    int curr_h = h[k];

    sort(all(h));
    int idx = -1;
    for(int i=1; i<=n; i++){
        if(h[i] == curr_h){
            idx = i;
            break;
        }
    }
    int w = 1;
    for(int i = idx+1; i<=n; i++){
        int time = 0;
        int nxt_h = h[i];
        if(nxt_h == curr_h) continue;
        time = abs(nxt_h - curr_h);
        w += time - 1;  // water level just before teleporting
        if(curr_h < w){
            no; return;
        }
        w++;
        curr_h = nxt_h;
    }
    yes;
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