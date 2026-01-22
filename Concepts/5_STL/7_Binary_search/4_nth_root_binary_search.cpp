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

double eps = 1e-6;

double multiply(double num, int n){
    double ans = 1.0;
    f(i, n){
        ans *= num;
    }
    return ans;
}

double nth_root(double x, int n){
    double l = 0, r = x, mid;
    while(r-l>eps){
        mid = (l+r)/2;
        if(multiply(mid, n) < x) l = mid;
        else r = mid;
    }
    return l;
    // O(p*Log(N*10^d)) // d is the no of decimals to which its accuracy where p is the pth root
}

void solve(){
    double x;
    int n;
    cin >> x >> n;
    cout << nth_root(x, n) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--)
        solve();
    
}