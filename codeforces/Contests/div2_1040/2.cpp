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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    int sum = 0;
    unordered_map<int,int> freq;
    fx(i, n, 0){
        cin >> a[i];
        sum += a[i];
        freq[a[i]]++;
    }
    int left = s - sum;
    if(left < 0 || left == 1){
        bool flag = true;
        fx(i, freq[0], 0){
            if(!flag) cout << " ";
            cout << 0;
            flag = false;
        }
        fx(i, freq[2], 0){
            if(!flag) cout << " ";
            cout << 2;
            flag = false;
        }
        fx(i, freq[1], 0){
            if(!flag) cout << " ";
            cout << 1;
            flag = false;
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
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