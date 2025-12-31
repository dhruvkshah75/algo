// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}

void solve(){
    ull n, l, r, k;
    cin >> n >> l >> r >> k;
    if(n%2!=0 || n==1){
        cout << l << endl;
        return;
    }
    else{
        // in an array where n is even the xor mostly turns 0 so and should also be zero
        if(n == 2){
            cout << -1 << endl;
            return;
        }
        ull s = l;
        while(true){
            bool flag = true;
            for(int i=0; i<64; i++){
                ull bit = 1ULL << i;
                if(l&bit && s&bit){
                    flag = false;
                    s += bit;
                    s &= ~(bit-1);
                    break;
                }
            }
            if(flag) break;
        }
        if(s > r){
            cout << -1 << endl;
            return;
        }
        else{
            if(k <= n-2){
                cout << l << endl;
                return;
            }
            else{
                cout << s << endl;
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}