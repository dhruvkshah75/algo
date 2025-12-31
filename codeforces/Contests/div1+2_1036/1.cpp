// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
    fc(i, n, a);
    vector<int> s = a;
    sort(all(s));
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (a[i] != s[i]) {
            b.push_back(a[i]);
        }
    }

    if (b.empty()) {
        no;
    } 
    else {
        yes;
        cout << b.size() << endl;
        for (int &val : b){
            cout << val << " ";
        } 
        cout << endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}