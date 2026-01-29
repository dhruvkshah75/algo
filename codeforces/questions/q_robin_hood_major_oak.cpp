#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

ll getOdd(const ll n){
    return (n + 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        ll n, k;
        cin >> n >> k;
        ll cnt = getOdd(n);
        if(n >= k){
            cnt -= getOdd(n - k);
        }
        // Check if the number of odd i^i is even
        if(cnt%2 == 0){
            yes;
        }
        else{
            no;
        }
    }   
}
