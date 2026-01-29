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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    unordered_set<int> q;
    f(i, m) cin >> a[i];
    f(i, k){
        int x; cin >> x;
        q.insert(x);
    }

    if(k+1<n){
        f(i, m) cout << 0;
        cout << endl;
        return;
    }
    if(k==n){
        f(i, m) cout << 1;
        cout << endl;
        return;
    }
    else{
        vector<int> ans(m);
        f(i, m){
            int list = a[i];
            auto it = q.find(list);
            if(it == q.end()) ans[i] = 1;
            else ans[i] = 0;
        }
        for(auto &x: ans) cout << x;
        cout << endl;
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--)
        solve();
    
}