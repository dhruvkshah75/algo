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

struct point{
    int x, y, idx;
};

bool cmp1(const point &a, const point &b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool cmp2(const point &a, const point &b){ // y ascending
    return a.y < b.y;
}

bool cmp3(const point &a, const point &b){  // y descending
    return a.y > b.y;
}

void solve(){
    int n;
    cin >> n;
    vector<point> pts(n);
    for(int i=0; i<n; i++){
        cin >> pts[i].x >> pts[i].y;
        pts[i].idx = i+1;
    }

    sort(all(pts), cmp1);
    int t = n/2;
    vector<point> lft(pts.begin(), pts.begin() + t);
    vector<point> rgt(pts.begin()+t, pts.end());

    sort(all(lft), cmp2);
    sort(all(rgt), cmp3);

    for(int i=0; i<t; i++){
        cout << lft[i].idx << " " << rgt[i].idx << endl;
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