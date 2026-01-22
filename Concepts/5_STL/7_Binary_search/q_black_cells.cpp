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


bool isSufficient(vector<ll> &a, ll x){   //-->> predicate function which gives a series of FFFFTTTT  false for smaller values of x and then gives true;
    int n = a.size();                     
    if(n%2==0){
        int ct=0;
        for(int i=0; i<n-1; i+=2){
            if(abs(a[i]-a[i+1]) <= x) ct++;
        }
        if(ct == n/2) return true;
        else return false;
    }
    else{
        int ct = 0;
        for(int i=0; i<n-1;){
            if(abs(a[i]-a[i+1]) <= x){
                i+=2;
                ct++;
            }
            else i++; 
        }
        if(ct == n/2) return true;
        else return false;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    f(i, n){
        cin >> a[i];
    }

    if(n==1){    
        cout << 1 << endl;
        return;
    }
    // function will give FFFFFFTTTTTTT 
    ll l = 0, r = 1e18, mid;        // to find the occurrence of first true as that would be the min value 
    while(r-l>1){
        mid = (l+r)/2;
        if(isSufficient(a, mid)) r=mid;
        else l = mid+1;
    }
    if(isSufficient(a, l)) cout << l << endl;   // first check l as it is smaller than r so l could be the first occurence of true;
    else cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}



// time complexity of the code is O(tt*n*Log(1e18)); O(tt*n*60);