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

double square_root(double x){
    double l = 0, r = x, mid;
    while(r-l>eps){         // cannot use r-l > 1 as square root has decimal places
        mid = (r+l)/2;
        if(mid*mid < x) l = mid;
        else r = mid;
    }
    cout << setprecision(10) << l << " " << r << endl;              // since eps is 1e-6 so l and r will be same till 5 precession
    return l;
}

void solve(){
    double x;
    cin >> x;
    cout << square_root(x) << endl;
    cout << pow(x, 1.0/2) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int tt;
    // cin >> tt;
    // while(tt--)
        solve();
    
}