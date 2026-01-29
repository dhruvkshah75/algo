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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    unordered_map<int,int> freq;
    fx(i, n, 0){
        cin >> v[i];
        freq[v[i]]++;
    }
    int score = 0;
    for(int i=0; i<n; i++){
        if(freq.count(k-v[i]) && freq[k-v[i]] > 0 && freq[v[i]] > 0){
            if(k-v[i] == v[i] && freq[v[i]] <= 1){
                if(freq.count(k-v[i])) freq[k-v[i]]--;
                freq[v[i]]--;
            }
            else{
                score++;
                if(freq.count(k-v[i])) freq[k-v[i]]--;
                freq[v[i]]--;
            } 
        }
    }
    cout << score << endl;
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