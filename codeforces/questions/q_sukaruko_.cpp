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
    string name = "Sakurako";
    int x = 0;
    for(int i=1; ;i++){
        if(abs(x) > n) break;
        if(i%2 != 0){  // sakurako's turn  -->> -ve direction
            int pos = abs(2*i-1);
            x -= pos;
            name = "Sakurako";
        }
        else{
            int pos = abs(2*i-1);
            x += pos;
            name = "Kosuke";
        }
    }
    cout << name << endl;
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