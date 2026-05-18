// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(x) cerr << #x << " = " << x << endl;

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 
vector<int> power2(31);

int power2count(ll x) {
    int power = 0;
    while (x % 2 == 0) {
        power++;
        x /= 2;
    }
    return power;
}

int upperbound(vector<int> &v, int element) {
    int l = 0, r = (int)v.size() - 1;
    int mid;
    while (r - l > 1) {
        mid = (r + l) / 2;
        if (v[mid] <= element) l = mid + 1;
        else r = mid;
    }
    if (v[l] > element) return l;
    if (v[r] > element) return r;
    return -1;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<int> x(q);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> x[i];
    }

    sort(all(x));

    vector<ll> pf_add(q);
    pf_add[0] = 1LL * power2[x[0] - 1];
    for (int i = 1; i < q; i++) {
        pf_add[i] = pf_add[i - 1] + 1LL * power2[x[i] - 1];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] & 1) continue;  
        int power = power2count(a[i]);
        int idx = upperbound(x, power);

        if (idx == -1) {
            a[i] += pf_add[q - 1];        
        } else if (idx > 0) {
            a[i] += pf_add[idx - 1];      
        }
    }

    for(auto &x: a){
        cout << x << " ";
    }
    cout << endl;
    
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

    power2[0] = 1;
    for(int i=1; i<31; i++){
        power2[i] = power2[i-1]*2;
    }

    while (tt--)
        solve();
}