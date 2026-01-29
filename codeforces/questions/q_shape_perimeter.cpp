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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    f(i, n){
        cin >> a[i].first >> a[i].second; 
    }
    int total_perimeter = 4*n*m;
    int extra_perimeter = 0;
    for(int i=1; i<n; i++){
        int len = m-a[i].first;
        int breadth = m-a[i].second;
        if(len>0 && breadth>0) extra_perimeter += 2*(len+breadth);
        else if(breadth > 0 && len <=0) extra_perimeter += breadth;
        else if(len > 0 && breadth <= 0) extra_perimeter += len;
    }
    cout << total_perimeter - extra_perimeter << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}