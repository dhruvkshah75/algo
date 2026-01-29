#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7

void solve(){
    int n, l, t;
    ll P;
    cin >> n >> P >> l >> t;
    int tasks = (int)ceil((double)(n-1)/7);
    // no days left after all lessons unlocked 
    int left = n-(7*(tasks-1)+1);
    ll sum = 0;
    int count = 0;   // counts the no of days used 
    ll add = P/(l+2*t);
    ll days_used = (P%(l+2*t) == 0)?add:(add+1);
    if(days_used > left){
        int diff = days_used - left;
        
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