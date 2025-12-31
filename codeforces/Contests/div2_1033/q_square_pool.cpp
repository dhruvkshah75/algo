#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279

void solve(){
    int n, s;
    cin >> n >> s;
    vector<pair<int,int>> d(n);
    vector<pair<int,int>> p(n);
    for(int i=0; i<n; i++){
        cin >> d[i].first >> d[i].second >> p[i].first >> p[i].second; 
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(p[i].first == p[i].second  && ((d[i].first == 1 && d[i].second == 1) || (d[i].first == -1 && d[i].second == -1))) count++;
        else if(p[i].first+p[i].second == s && ((d[i].first == 1 && d[i].second == -1) || (d[i].first == -1 && d[i].second == 1))) count++;
    }

    cout << count << endl;
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