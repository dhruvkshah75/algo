// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}
#define fx(i, n, a) for(int i=a; i<n; i++)
// #define debug_code
const int M = 1e9+7;

// Solution begins here: 

int smallestPrime(int n){
    for(int i=2; i*i<=n; ++i){
        if (n % i == 0) return i;
    }
    return n; // n is prime
}

void solve(){
    int n;
    cin >> n;
    // a+b = n
    if(n&1){
        int p = smallestPrime(n);
        cout << n/p << " " << n - n/p << endl;
    }
    else  cout << n/2 << " " << n/2 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug_code
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}