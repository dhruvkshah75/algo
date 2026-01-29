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


void query(string &s){
    int i;
    char v;
    cin >> i >> v;
    s[i-1] = v;
    int len = s.size();
    if(len < 4){
        no;
        return;
    }
    for(int j=0; j<len-3; j++){
        if(s[j] == '1' && s[j+1] == '1' && s[j+2] == '0' && s[j+3] == '0'){
            yes;
            return;
        }
    }
    no;
}

void solve(){
    string s;
    cin >> s;
    int q;
    cin >> q;
    while(q--){
        query(s);
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