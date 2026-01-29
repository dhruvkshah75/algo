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

#ifdef debug
void printBinary(int num){
    for(int i=31; i>=0; i--){
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
#endif

void solve(){
    int n, x;
    cin >> n >> x;
    #ifdef debug
        printBinary(x);
    #endif
    if(n == 1){
        cout << x << endl;
        return;
    }
    vector<int> ans;
    ans.push_back(0);
    ans.push_back(x);
    int set_bits = __builtin_popcount(n);
    int ct = 2;
    for(int i=1; i<=x; i++){
        if(ct >= n) break;
        if(__builtin_popcount(n | i) <= set_bits){
            ans.push_back(i);
            ct++;
        }
    }
    if(ct!=n){

    }
    for(auto &val: ans){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}