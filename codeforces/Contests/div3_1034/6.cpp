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
int hsh[N];

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        hsh[arr[i]]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// */

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}