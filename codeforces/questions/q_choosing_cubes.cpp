#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define maybe cout << "MAYBE" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279

//#define DEBUG = 0

bool cmp(int a, int b){
    if(a>b) return true;
    return false;
}

void solve(){
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n+1);
    unordered_map<int,int> freq;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    int fav = a[f];
    sort(a.begin()+1, a.end(), cmp);

    #ifdef DEBUG
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    #endif
    bool rem = false;
    int count = 0;
    for(int i=1; i<=k; i++){
        if(fav == a[i]){
            rem = true;
            count++;
        } 
    }

    if(rem && (freq[fav] == 1 || freq[fav] == count)){
        yes;
        return;
    }
    else if(rem && freq[fav] > 1 && freq[fav] != count){
        maybe;
        return;
    }
    else if(rem == false){
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