#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    map<int, int> need;     // Required operations (for a[i] != b[i])
    map<int, int> available; // Given operations (d[i])
    bool found_last = false;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) need[b[i]]++; // must be equal to b[i]
    }

    int m;
    cin >> m;
    vector<int> d(m);
    for(int i = 0; i < m; i++){
        cin >> d[i];
        available[d[i]]++;
    }

    // Last operation must be applicable to some b[i]
    for(int i = 0; i < n; i++){
        if(b[i] == d[m-1]){
            found_last = true;
            break;
        }
    }

    if(!found_last){
        no;
        return;
    }

    for(auto &[num, req_count] : need){
        if(available[num] < req_count){
            no;
            return;
        }
    }

    yes;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) solve();
}
