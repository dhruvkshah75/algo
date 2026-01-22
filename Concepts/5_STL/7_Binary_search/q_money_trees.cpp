// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}



const int N = 200'000;
 
int n, k;
int a[N+5], h[N+5], pref[N+5], length[N+5];
 
bool get(int dist){
    bool found = false;
    for(int i=0; i < n-dist+1; i++){
        if(length[i] < dist)continue;
        int sum = pref[i+dist]-pref[i];
        if(sum <= k)
        {
            found = true;
            break;
        }
    }
    return found;
}
 
void solve(){
    pref[0] = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i+1] = pref[i]+a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    length[n-1] = 1; // at last position only one element is there
    for(int i = n-2; i >= 0; i--){
        if(h[i]%h[i+1] == 0){
            length[i] = length[i+1]+1;
        }
        else{
            length[i] = 1;
        }
    }
    int l = 1, r = N;
    while(l <= r){
        int mid = (l+r)/2;
        if(get(mid)){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}