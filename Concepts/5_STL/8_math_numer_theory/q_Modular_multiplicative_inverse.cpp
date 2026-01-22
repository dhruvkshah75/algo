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

/*
    Question:  UNLOCK the door
    Our friend Monk has finally found the Temple of programming secret. However the door of the temple is firmly locked. Now, as per the rules of the temple,
    monk needs to enter a secret password in a special language to unlock the door. this language, unlike english consists of K alphabets. The properties of this
    secret password:
    1. it has length of N charachters
    2. it is composed only of the k characters belonging to the special language.
    3. Each character belonging to the special language has been used at max once int the secret code.
    Now, monk has no idea about what the ideal password may be and needs you help. You need to help monk find the total no of distinct candidate string for it 
    modulo 1e9+7
    Input format:
    the first line contains T test cases each contains two integers n and k denoting length of the secret password and number of characters of the special language to be used respectively
    K and N lie in the range of 1e5


*/
const int M = 1e9+7;

ll binExpo(ll a, ll b, int m){  // iterative binary expo (calculate (a^b)%M )
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return ans;
}
// O(Log(N))

const int N = 1e5+10;
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

// Solution begins here: 
void solve(){
    // alphabet -->> K symbols, N size password, K > N
    // kCn for choosing the n letters and then arranging them in n! ways 
    // ans is kCn * n! this is actually equal to kPn 
    int k, n;
    cin >> k >> n;
    factorial(M);
    cout << (nCr(k, n, M)*fact[n]*1LL) % M << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--)
        solve();
}
