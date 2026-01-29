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
    vector<ll> a(n);
    unordered_map<ll, int> freq;
    for(int i=0; i<n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }

    if(freq[a[0]] == n){
        yes; return;
    }

    bool isMultiple = false;
    for(int i=0; i<n; i++){
        if(a[i] % 5 == 0){
            isMultiple = true;
        }
    }

    for(int i=0; i<n; i++){
        if(a[i]%10 == 1 || a[i]%10 == 3 || a[i]%10 == 7 || a[i]%10 == 9 || a[i] % 10 == 5){
            a[i] += a[i] % 10;
        }
    }

    if(isMultiple){
        bool allEqual = true; 
        for(int i = 1; i < n; i++){
            if(a[i] != a[0]){
                allEqual = false;
                break;
            }
        }
        if(allEqual){ yes; return;}
        else{ no; return;}
    }

    else{
        sort(all(a));
        // 2 -->> 4 -->> 8 -->> 6 -->> so on
        for(int i=0; i+1<n; i++){
            ll diff = a[n-1] - a[i];
            ll temp = a[i] + 20*(diff/20);
            bool ok = false;
            while(temp <= a[n-1]){
                int rem1 = temp % 10;
                if(temp == a[n-1]) {
                    ok = true;
                    break;
                }
                if(rem1 == 0) break; 
                temp += rem1;
            }
            if(!ok){
            no; return;
            }
        }
        yes;
    }
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