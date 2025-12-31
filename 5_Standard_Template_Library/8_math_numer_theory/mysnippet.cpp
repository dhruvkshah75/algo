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

ll gcd(ll a, ll b){ // Euclid algorithm to calculate gcd
    if(b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}

ll binExpo(ll a, ll b){  // iterative binary expo (calculate (a^b)%M )
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans * a) % M;
        a = (a * a) % M;
        b = b >> 1;
    }
    return ans;
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

void preComputePrime(vector<bool> &primes, int len){  // Sieve Algorithm
    primes[0] = primes[1] = false;
    for(int i=2; i<len; i++){
        if(primes[i] == true){
            for(int j=2*i; j<len; j+=i){
                primes[i] = false;
            }
        }
    }
}

const int L = 1e7+10;
vector<int> lp(L, 0), hp(L, 0);
void highest_lowest_Prime(vector<bool> &prime){ 
    prime[0] = prime[1] = false;
    for(int i=2; i<L; i++){
        if(prime[i] == true){
            lp[i] = hp[i] = i;
            for(int j=2*i; j<L; j+=i){
                prime[j] = false;
                hp[j] = i;
                if(lp[j] == 0) lp[j] = i;
            }
        }
    }
}


// Solution begins here: 

void solve(){
    
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