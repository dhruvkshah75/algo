// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        cin >> a[i];

    }
    vector<int> pmin(n);
    vector<int> pmax(n);
    pmin[0] = a[0];
    pmax[0] = a[0];
    for(int i=1; i<n; i++){
        pmin[i] = min(a[i], pmin[i-1]);
        pmax[i] = max(a[i], pmax[i-1]);
    }
    int max = *max_element(all(a));
    int min = *min_element(all(a));
    for(int i=0; i<n; i++){
        if(a[i] == min || a[i] == max){
            ans[i] = 1;
            continue;
        }
        if(i!= n-1 && pmax[n-1]!=a[i] && pmin[i]==a[i]){
            ans[i] = 1;
        }
        if(i==n-1 && pmin[i-1]!=a[i]){
            ans[i]=1;
        }
    }
    for(auto &val: ans){
        cout << val;
    }
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}