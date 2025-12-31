// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}

bool canFormTriangle(double a, double b, double c) {
    return (a + b > c) && (b + c > a) && (a + c > b);
}

void solve(){
    int n;
    cin >> n;
    int p1, p2, q1, q2;
    cin >> p1 >> p2 >> q1 >> q2;
    vector<int> a(n);
    f(i, n){
        cin >> a[i];
    }
    if(n == 1){
        double dist = sqrt(pow(p1-q1, 2)+pow(p2-q2, 2));
        if(abs(a[0] - dist) < 1e-6){
            yes; return;
        }
        no; return;
    }
    if(n == 2){
        if(p1 == q1 && p2 == q2){
            if(a[0] == a[1]){
                yes; return;
            }
            no; return;
        }
        if(p1 == q1){
            double dist = sqrt(pow(p2-q2, 2));
            if(abs(a[0]+a[1]-dist) < 1e-6){
                yes; return;
            }
        }
        if(p2 == q2){
            double dist = sqrt(pow(p1-q1, 2));
            if(abs(a[0]+a[1]-dist) < 1e-6){
                yes; return;
            }
        }
        double dist = sqrt(pow(p1-q1, 2)+pow(p2-q2, 2));
        if(canFormTriangle(dist, (double)a[0], (double)a[1])){
            yes; return;
        }
        no; return;
    }
    if(n >= 3){
        double dist = sqrt(pow(p1-q1, 2)+pow(p2-q2, 2));
        ll total_dist = 0;
        for(int i=0; i<n; i++){
            total_dist += a[i]*1LL;
        }
        if(total_dist < dist){
            no; return;
        }
        yes;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}