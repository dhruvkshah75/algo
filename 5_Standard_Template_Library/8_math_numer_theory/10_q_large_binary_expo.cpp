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

// iterative binary exponentiation
ll binExpo(ll a, ll b, int m){
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return ans;
}

/*
    Euler's theorem to calculate large binary exponentiation
    (a^b) % M == a^(b % phi(M)) % M -->> M is any number phi(M)=M-1 if M is a prime no
*/
ll phi(ll n){ // Euler's Totient Function  O(Sqrt(N)) 
    ll result = n;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0)
                n /= i;
            result -= result/i;
        }
    }
    if(n > 1){
        result -= result/n;
    }
    return result;
}

void solve(){
    // calculate 50^64^32
    // M = 1e9+7 -->> is prime so phi(M) = M-1
    //cout << binExpo(50*1LL, binExpo(64*1LL, 32*1LL, M-1), M);   // if b is very large 
    /*
        eg M = 1337
        b is very large and is given in form of array [4, 3, 3, 8, 5, 2]  -->> currosponds to 433852
        (a^b) % M (by using Euler's theorem) = (a^(b%phi(M))) % M
        phi(1337) = 1140 so we can do that 
        2*10^0 % 1440 + 5*10^1 % 1440 + ... 
    */
   cout << phi(1337) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}