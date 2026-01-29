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
// #define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

void solve(){
    // mapie -->> cnt = 1 insted of 2
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    if(n < 3){
        cout << cnt << endl;
        return;
    }
    for(int i=0; i<n-2; ){
        if(i <= n-5 && s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p' && s[i+3] == 'i' && s[i+4] == 'e'){
            cnt++;
            i += 5;
        }
        else if(s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p'){
            cnt++;
            i += 3;
        } 
        else if(s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e'){
            cnt++;
            i += 3;
        }
        else i++;
    }
    cout << cnt << endl;
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