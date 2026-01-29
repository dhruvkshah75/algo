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

void solve(){
    int n, k;
    cin >> n >> k;
    string str1;
    cin >> str1;
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    vector<int> hsh(26, 0);
    for(int i=0; i<n; i++){
        hsh[(int)(str1[i] - 'a')]++;
    }
    if(hsh[(int)(str1[0] - 'a')] == n){
        no; return;
    }
    if(str1 == str2 && k == 0){
        no; return;
    }
    if(k==0){
        for(int i=0; i<n; i++){
            if(str1[i] < str2[i]){
                yes; return;
            }
            if(str1[i] == str2[i]) continue;
            if(str1[i] > str2[i]){
                no; return;
            }
        }
    }
    yes;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef online_judge
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}