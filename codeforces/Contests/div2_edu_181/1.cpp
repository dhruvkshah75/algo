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
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
//#define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

void solve(){
    string s;
    cin >> s;
    int cntT = 0, cntF = 0, cntN = 0;
    vector<char> rem;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'T') cntT++;
        else if(s[i] == 'F') cntF++;
        else if(s[i] == 'N') cntN++;
        else rem.pb(s[i]);
    }
    for(int i=0; i<cntT; i++){
        cout << 'T';
    }
    for(auto &c: rem){
        cout << c;
    }
    for(int i=0; i<cntF; i++){
        cout << 'F';
    }
    for(int i=0; i<cntN; i++){
        cout << 'N';
    }
    cout << endl;
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