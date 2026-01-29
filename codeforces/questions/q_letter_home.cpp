#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


//  the person will first cover the min distance and then he will cover the entire track;
// s is where the person is so find the min of |s-x1| and |xn-1 - s| --> this distance will b first covered by him

void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> a;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << min(abs(a[0] - s) , abs(a[n-1] - s)) + (a[n-1] - a[0]) << endl;
    
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