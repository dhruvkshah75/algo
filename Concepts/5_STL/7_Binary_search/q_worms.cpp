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
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}

const int N = 1e5+10;
int q[N];
int a[N];

int lower_bound(vector<int> &pf, int x){
    int l = 0, r = pf.size()-1;
    int mid;
    while(r-l>1){
        mid = (l+r)/2;
        if(pf[mid] < x) l = mid+1;
        else r = mid;
    }
    if(pf[l] >= x) return l;
    if(pf[r] >= x) return r;
    return -1;
}

void solve(){
    int n;
    cin >> n;
    vector<int> pf(n+1);
    f1(i, n){
        cin >> a[i];
        pf[i] = pf[i-1] + a[i];
    }
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> q[i];
    }
    for(int i=0; i<m; i++){
        cout << lower_bound(pf, q[i]) << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int tt;
    // cin >> tt;
    // while(tt--)
        solve(); 
}