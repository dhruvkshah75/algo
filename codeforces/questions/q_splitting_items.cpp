#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int sum1 = 0;
    int sum2 = 0;
    int used = 0;
    bool flag = false;
    int left = k;
    for(int i=0; i<n; i++){
        if(used == k) flag = true;
        if(i%2 == 0){
            sum1 += a[i];                // sum1 is the num picked by alice which are even turns starting from 0
        }
        if(!flag && i%2 != 0){           
            /*
                bob picks the next greatest element and then makes it equa to min(alices pick, a[i]+left) 
                where left is the num he can add to a[i] and change the value of used and left;
            */
            int add = min(a[i-1], a[i]+left);
            used = add-a[i];
            sum2 += add;
            left -= used;
        }
        if(flag && i%2 != 0){
            sum2 += a[i];
        }
    }

    cout << sum1 - sum2 << endl;
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