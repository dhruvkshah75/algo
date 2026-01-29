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

int upper_bound(vector<int> &v, int x){
    int l=0, r=v.size()-1, mid;
    while (r-l>1) {
        mid = (l+r)/2;
        if (v[mid] <= x) l = mid+1;
        else r = mid;
    }
    if (v[l] > x) return l;
    if (v[r] > x) return r;
    return -1;
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    fx(i, n, 0){
        cin >> a[i];
    }
    vector<int> k(q);
    fx(i, q, 0){
        cin >> k[i];
    }
    vector<ll> pf(n);
    vector<int> pmax(n);
    pf[0] = a[0]; pmax[0] = a[0];
    fx(i, n, 1){
        pf[i] = pf[i-1] + a[i]*1LL;
        pmax[i] = max(pmax[i-1], a[i]);
    }

    vector<ll> ans;
    fx(i, q, 0){
        int index = upper_bound(pmax, k[i]);
        if(index == -1) ans.pb(pf[n-1]);
        else if(index == 0) ans.pb(0);
        else{
            ans.pb(pf[index-1]);
        }
    }

    for(ll &x: ans){
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