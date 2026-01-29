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


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> freq;
    ff(i, n, a, freq);
    if(freq[0] == n){
        cout << 0 << endl;
        return;
    }
    if(freq[0] == 0){
        cout << 1 << endl;
        return;
    }

    int l = 0, r = n-1;
    bool flag1 = true, flag2 = true;
    while(l<r){
        if(a[l] == 0 && flag1) l++;
        if(a[l] != 0) flag1 = false;
        if(a[r] == 0 && flag2) r--;
        if(a[r] != 0) flag2 = false;
        if(flag1 == false && flag2 == false) break;
    }
    bool isContiguous = true;
    for(int i=l; i<=r; i++){
        if(a[i] == 0) isContiguous = false;
    }
    if(isContiguous){
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
}

int main() {
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