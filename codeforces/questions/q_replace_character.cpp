// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
// #define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char,int> freq;
    fx(i, n, 0){
        freq[s[i]]++;
    }
    char mx = 0, mn = 0;
    int mx_cnt = -1, mn_cnt = 1e9;
    for(auto &[c, cnt]: freq){
        if(cnt > mx_cnt){
            mx = c;
            mx_cnt = cnt;
        }
        if(cnt < mn_cnt){
            mn = c;
            mn_cnt = cnt;
        }
    }
    //debug(mn_cnt); debug(mx_cnt); debug(mn); debug(mx);
    for(int i=0; i<n; i++){
        if(freq[s[i]] == mn_cnt){
            s[i] = mx;
            break;
        }
    }

    cout << s << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug_code
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}