#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> freq_a;
    for(int i=0; i<n; i++){
        cin >> a[i];
        freq_a[a[i]]++;
    }
    vector<int> b(n);
    unordered_map<int,int> freq_b;
    for(int i=0; i<n; i++){
        cin >> b[i];
        freq_b[b[i]]++;
    }

    int unique1 = freq_a.size();
    int unique2 = freq_b.size();
    if((unique1 <= 2 && unique2 <= 1) || (unique1 <= 1 && unique2 <=2)){
        no;
        return;
    }
    yes;
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