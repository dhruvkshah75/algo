#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int ct = 0;
    vector<int> b(n+1);
    unordered_map<int,int> freq_b;
    unordered_set<int> diff;
    for(int i=1; i<=n; i++){
        cin >> b[i];
        freq_b[b[i]]++;
        if(a[i] != b[i]){
            ct++;
            diff.insert(b[i]);
        } 
    }

    int m;
    cin >> m;
    vector<int> d(m+1);
    for(int i=1; i<=m; i++){
        cin >> d[i];
    }
    if(ct > m){
        no;
        return;
    }
    else if(ct == m){
        for(int i=1; i<=m; i++){
            if(freq_b[d[i]] == 0 || diff.find(d[i]) == diff.end()){
                no;
                return;
            }
        }
        yes;
        return;
    }
    else if(m > ct){
        unordered_map<int, int> freq_d;
        for(int i = 1; i <= m; i++){
            freq_d[d[i]]++;
        }


        for(auto x : diff){
            if(freq_d[x] < 1){
                no;
                return;
            }
        }
        bool last_can_be_applied = false;
        for(int i = 1; i <= n; i++){
            if(b[i] == d[m]){
                last_can_be_applied = true;
                break;
            }
        }
        if(!last_can_be_applied){
            no;
            return;
        }
        yes;
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