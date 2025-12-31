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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int count1 = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='1') count1++;
    }
    if(count1 <= k){
        cout << "Alice" << endl;
        return;
    }
    bool k_z = false;
    int zero = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='0') zero++;
        else zero = 0;
        if(zero >= k){
            k_z = true;
            break;
        }
    }
    if(k_z){
        cout << "Bob" << endl;
    }
    else if(2*k <= n){
        cout << "Bob" << endl;
    }
    else{
        cout << "Alice" << endl;
    }
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