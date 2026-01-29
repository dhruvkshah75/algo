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


void solve() {
    int n;
    cin >> n;
    vector<ll> pf(n+1);         // vector size is 1e5 and element size is 1e5 so overflow
    vector<pair<int,char>> s(n+1);
    f1(i, n){
        cin >> s[i].first;
        pf[i] = pf[i-1] + s[i].first*1LL;
    }
    f1(i, n){
        cin >> s[i].second;
    }

    int l=1, r=n;
    ll score = 0;
    while(l<r){
        if(s[l].second != 'L') l++;       
        if(s[r].second != 'R') r--;
        if(s[l].second == 'L' && s[r].second == 'R'){
            score += pf[r] - pf[l-1];
            l++;
            r--;
        }
    }
    cout << score << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}