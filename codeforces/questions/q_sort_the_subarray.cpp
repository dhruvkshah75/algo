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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }

    int l, r;
    for(int i=1; i<=n; i++){
        if(a[i] != b[i]) {
            l = i;
            break;
        }
    }
    for(int j=n; j>0; j--){
        if(a[j] != b[j]) {
            r = j;
            break;
        }
    }
    // these two loops gives the minimum values of the l, r
    vector<int> temp(r-l+1);
    int k=0;
    for(int i=l; i<=r; i++){
        temp[k++] = a[i];
    }
    int min_ele = *min_element(all(temp));
    int max_ele = *max_element(all(temp));
    debug(min_ele); debug(max_ele)
    while(l-1 >= 1 && a[l-1] <= min_ele){
        min_ele = a[l-1];
        l--;
    }
    while(r+1 <= n && a[r+1] >= max_ele){
        max_ele = a[r+1];
        r++;
    }

    cout << l << " " << r << endl;
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