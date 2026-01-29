// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}


void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<char> a(n + 2);
    a[0] = a[n + 1] = 'S';  
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (m >= n+1){  
        yes;
        return;
    }
    int l = 0;  
    while (l <= n) {
        while (l <= n && (a[l] == 'L' || a[l] == 'S')) l++;  
        int last_safe = l - 1;  // last log/shore position
        int r = l;
        while (r <= n && a[r] == 'W') r++;  // find end of water
        int swim_len = r - l;
        int jump_len = r - last_safe;

        if (a[r] == 'C'){
            if (jump_len <= m && swim_len <= k) {
                no;
                return;
            }
        }

        if (jump_len > m && swim_len > k) {
            no;
            return;
        }
        if (jump_len <= m){
            l = r;  
        } 
        else if(swim_len <= k){
            k -= swim_len;
            l = r;  
        } 
        else{
            no;
            return;
        }
    }

    yes;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}