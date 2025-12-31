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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> freq(n+2, 0);
    fx(i, n, 0){
        cin >> a[i];
        freq[a[i]]++;
    }

    if(freq[0] >= 2){
        if(k&1){
            int ans = 0;
            while(freq[ans] > 0) ans++;
            cout << ((k == 1) ? ans*n : n) << endl;
        }
        else cout << 0 << endl;
        return;
    }

    ll sum_i = 0;
    int mex_all = 0;
    while(freq[mex_all] > 0) mex_all++;

    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        if (a[i] < mex_all && freq[a[i]] == 1){
            ans[i] = a[i];
            sum_i += a[i]*1LL;
        } 
        else{
            ans[i] = mex_all;
            sum_i += mex_all*1LL;
        } 
    }

    if(freq[0] == 1 || k == 1){
        cout << sum_i << endl;
    }
    else{
        ll sum_f = 0;
        vector<int> freq_ans(n+2, 0);
        for(int i=0; i<n; i++){
            freq_ans[ans[i]]++;
        }
        if(freq_ans[0] >= 2){
            if(k&1){
                int ans = 0;
                while(freq_ans[ans] > 0) ans++;
                cout << ((k == 1) ? ans*n : n) << endl;
            }
            else cout << 0 << endl;
            return;
        }

        int mex_all_ans = 0;
        while(freq_ans[mex_all_ans] > 0) mex_all_ans++;

        for(int i = 0; i < n; i++){
            if (ans[i] < mex_all_ans && freq_ans[ans[i]] == 1) sum_f += ans[i]*1LL;
            else sum_f += mex_all_ans*1LL;  
        }
        cout << sum_f << endl;
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