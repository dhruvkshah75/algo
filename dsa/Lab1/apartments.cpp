// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for(int i=0; i<m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, ans = 0;
    // a simple two pointer approach 
    while (i < n && j < m) {
        // case when the apartment is too small then move to the next apartment
        if (b[j] < a[i] - k) j++;
        // case when the apartment is too big then move to the next person
        else if (b[j] > a[i] + k) i++;
        // this is the reuquired condition
        else {
            ans++; i++; j++;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}

