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

int upperBound(vector<int> &x, int m){
    int l = 0, r = x.size()-1, mid;
    while(r-l > 1){
        mid = (l+r)/2;
        if(x[mid] <= m) l = mid+1;
        else r = mid;
    }
    if(x[l] > m) return l;
    if(x[r] > m) return r;
    return -1;
}

void solve(){
    int n;
    cin >> n;
    vector<int> x(n);
    fx(i, n, 0){
        cin >> x[i];
    }
    sort(all(x));
    int q;
    cin >> q;
    while(q--){
        int m;
        cin >> m;
        int idx = upperBound(x, m);
        if(idx == -1) cout << n << endl;
        else if(idx == 0) cout << 0 << endl;
        else cout << idx << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();
}