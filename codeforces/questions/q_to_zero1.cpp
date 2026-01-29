#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279

void solve(){
        int n;
        int k;
        cin >> n >> k;
        int count = 0; 
            while(n>0){
                long int x;
                if(n%2==0)
                    x = k-1;
                else
                    x = k;
                n-=x;
                count++;
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
