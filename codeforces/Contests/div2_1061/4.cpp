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

ll lcm(ll a, ll b){
    return (a*b)/__gcd(a,b);
}

ll binExpo(ll a, ll b, int m){  // iterative binary expo (calculate (a^b)%M )
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return ans;
}

/*
 * Euler's Theorem
 * a^b % M == a^(b % phi(M)) % M, where phi(M) = M - 1 if M is prime
*/
ll phi(ll n){ //Euler's Totient Function  O(Sqrt(N))
    ll result = n;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0)  n /= i;
            result -= result / i;
        }
    }
    if(n > 1) result -= result / n;
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

void lowest_highest_Prime(vector<int> &lp, vector<int> &hp, int psize){
    vector<bool> prime(psize+1, 1);
    prime[0] = prime[1] = false;
    for(int i=2; i<=psize; i++){
        if(prime[i] == true){
            lp[i] = hp[i] = i;
            for(int j=2*i; j<=psize; j+=i){
                prime[j] = false; hp[j] = i;
                if(lp[j] == 0) lp[j] = i;
            }
        }
    }
}

vector<pair<int,int>> primefactorisation(vector<int> &lp, int x){
    vector<pair<int,int>> ans;
    while(x > 1){
        int prime = lp[x];
        int cnt = 0;
        while(x%prime == 0){
            cnt++; x /= prime;
        }
        ans.push_back({prime, cnt});
    }
    return ans;
}

const int N = 1e6+10;
// precompute all values of factorial
vector<int> fact(N);
void factorial(int m){
    fact[0] = 1;
    for(int i=1; i<N; i++){
        fact[i] = (fact[i-1]*1LL* i) % m;
    }
}

// based on modular multiplicative inverse
int nCr(int n, int r, int m){
    int denomintor = (fact[n-r] * 1LL * fact[n]) % m;
    int ans = (fact[n] * 1LL * binExpo(denomintor, m-2, m)) % m;
    return ans;
}

int smallestPrime(int n){  // easy calculation for a single num
    for(int i=2; i*i <= n; i++){
        if(n % i == 0) return i;
    }
    return n;  // n is prime
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