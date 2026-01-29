// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
// #define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

ll area(pair<int,int> &min_x, pair<int,int> &min_y, pair<int,int> &max_x, pair<int,int> &max_y){
    int len = abs(max(max_x.first, max(min_y.second, max_y.second)) - min(min_x.first, min(min_y.second, max_y.second)))+1;
    int breadth = abs(max(max_y.first, max(max_x.second, min_x.second)) - min(min_y.first, min(max_x.second, min_x.second)))+1;
    return len*1LL*breadth;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a_x;
    vector<pair<int,int>> a_y;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        a_x.pb({x, y});
        a_y.pb({y, x});
    }
    sort(all(a_x));
    sort(all(a_y));
    if(n == 1) cout << 1 << endl;
    if(n == 2) cout << 2 << endl;
    if(n == 3){
        ll area1 = (abs(a_x[0].first-a_x[1].first)+1)*1LL*(abs(a_x[0].second-a_x[1].second)+1);
        ll area2 = (abs(a_x[0].first-a_x[2].first)+1)*1LL*(abs(a_x[0].second-a_x[2].second)+1);
        ll area3 = (abs(a_x[1].first-a_x[2].first)+1)*1LL*(abs(a_x[1].second-a_x[2].second)+1);
        ll min_area = min(area1, min(area2, area3));
        if(min_area == 2){
            cout << 3 << endl;
            return;
        }
        cout << min_area << endl;
    }
    if(n >= 4){
        ll area1 = area(a_x[1], a_y[0], a_x[n-1], a_y[n-1]);
        ll area2 = area(a_x[0], a_y[1], a_x[n-1], a_y[n-1]);
        ll area3 = area(a_x[0], a_y[0], a_x[n-2], a_y[n-1]);
        ll area4 = area(a_x[0], a_y[0], a_x[n-1], a_y[n-2]);
        cout << min(area1, min(area2, min(area3, area4))) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug_code
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}