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

const int N = 1e5+10;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    fc(i, n, a);
    vector<int> s(n+10);
    s[a[0]]++;
    for(int i=1; i<n; i++){
        s[a[i]]++;
        if(s[a[i]+1] == 0 && s[a[i]-1] == 0){
            no;
            return;
        }
    }
    yes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}