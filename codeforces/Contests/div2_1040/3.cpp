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

struct S{
    int a, b, diff, idx;
};

struct DSU{
    int n;
    vector<int> a;
    DSU(int _n): n(_n), a(n+1){ 
        iota(all(a), 0); 
    }
    int find(int x){
        return a[x] == x ? x: a[x] = find(a[x]); 
    }
    bool unite(int w, int v){
        w = find(w); v = find(v);
        if(w == v) return false;
        a[v] = w;
        return true;
    }
};

void solve(){
    int n; cin >> n;
    vector<S> e(n);
    int mxNode = 0;
    fx(i, n, 0){
        cin >> e[i].a >> e[i].b;
        e[i].diff = e[i].b - e[i].a;
        e[i].idx = i+1;
        mxNode = max({mxNode, e[i].a, e[i].b});
    }

    sort(all(e), [&](auto &x, auto &y){
        return x.diff > y.diff;
    });

    DSU dsu(mxNode);
    vector<int> ans;
    for(auto &val: e){
        if(dsu.unite(val.a, val.b)){
            ans.pb(val.idx);
        }
    }
    cout << ans.size() << endl;
    for(int &x: ans){
        cout << x << " ";
    }
    cout << endl;
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