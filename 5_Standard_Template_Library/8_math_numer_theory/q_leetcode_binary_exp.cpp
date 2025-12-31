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
const int M = 1e9+7;

// Euclid algorithm to calculate gcd
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}

/*
 * Euler's Theorem for Modular Inverse (when M is prime)
 * a^b % M == a^(b % phi(M)) % M, where phi(M) = M - 1 if M is prime
*/
ll phi(ll n){ //Euler's Totient Function  O(Sqrt(N))
    ll result = n;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1){
        result -= result / n;
    }
    return result;
}

// solution begins here
const int mod = phi(1337); 

// iterative binary exponentiation
int binExpo(int a, int b, int m){
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans * 1LL * a) % m;
        a = (a * 1LL * a ) % m;
        b = b >> 1;
    }
    return ans;
}

int superPow(int a, vector<int> &b){
    int bmod = 0;
    for(int i=0; i<b.size(); i++){
        bmod = (bmod*10 + i) % mod;
    }
    return binExpo(a, bmod, 1337);
}

void solve(){ 
    int a, n;
    cin >> a >> n;
    vector<int> b(n);
    fc(i, n, b);
    cout << superPow(a, b) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int tt;
    // cin >> tt;
    // while (tt--)
        solve();
}