#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7

void solve(){
    int a, x, y;
    cin >> a >> x >> y;
    int dist_x = abs(x-a);
    int dist_y = abs(y-a);

    if((a<x && a<y) || (a>x && a>y)){
        if(dist_x > 1 || dist_y > 1){
            yes;
            return;
        }
        else{
            no;
            return;
        }
    }
    if((a>x && a<y) || (a<x && a>y)){   // that is a is in between of x and y
        no;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}