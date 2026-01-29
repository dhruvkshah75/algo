// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
// template<typename T>
// typedef tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    fc(i, n, a);
    fc(i, n, b);

    if(a[n-1] != b[n-1]){
        no; return;
    }

    unordered_map<int,int> len;
    int i = 0;
    while(i < n){
        int j = i;
        while(j < n && a[j] != b[j]) j++;
        len[i] = j;
        i = j+1;
    }

    for(auto &[i, j]: len){
        cerr << i << " " << j << endl;
    }
    
    for(auto &[i, j]: len){
        for(int k = i; k<j; k++){
            if((a[k] ^ a[k+1]) == b[k] || (a[k] ^ b[k+1]) == b[k]) a[k] = b[k];
        }
    }

    for(int i=0; i<n; i++){
        if(a[i] != b[i]){
            no; return;
        }
    }
    yes;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}