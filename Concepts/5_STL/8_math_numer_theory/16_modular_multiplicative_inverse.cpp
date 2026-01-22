/*
    NOTE:
    (A/B) % M = ((A % M) * (B-1 % M))%M;
    B-1 % M is called the modular multiplication inverse of B
    use binexpo(B, M-2, M) -->> to get MMI of A is B-1

*/
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

ll binExpo(ll a, ll b, int M){  // iterative binary expo (calculate (a^b)%M )
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans * a) % M;
        a = (a * a) % M;
        b = b >> 1;
    }
    return ans;
}

void solve(){
    /*
        (A/B) % M = ((A % M) * (B-1 % M))%M;
        B-1 % M is called the modular multiplication inverse of B
        if (A*B) % M = 1 then A is multiplicative inverse of A 
        1 <= B <= M-1
        to find B in such a case run a loop from 1 -->> M-1 (a*b)%M = 1 and get the value of b O(M)
        so MMI of A with M is O(M);
        MMI of A wrt to M is only defined if A and M are coprime __gcd(A, M) is 1;
        using fermett's liitle theorem 
        (A^(M-1) % M = 1  --->> A to the power of M-1 % M is 1   -->> M is prime and A is not multiple of M

        (A^(M-2)) % M = A-1  -->> A-1 is the mmi of A with respect to M -->> M has to prime an A is not a multiple of M

    */

    int a;
    cin >> a;
    binExpo(a, M-2, M);  // -->> this gives MMI of A wrt to M
}

/*
    question:
    there N children and K toffees (K<N)
    count the no of ways to distribute toffee among N students
    N < 1e6, K < N < 1e6  M = 1e9+7
    -->> ans = NCK -->> nCk combination
    formula n!/(n-r)!*r!
*/

// solution of this 
const int N = 1e6+10;
// precompute all values of factorial
vector<int> fact(N);
void factorial(int M){
    fact[0] = 1;
    for(int i=1; i<N; i++){
        fact[i] = (fact[i-1]*1LL* i) % M;
    }
}

int nCr(int n, int k, int M){
    int denomintor = (fact[n-k] * 1LL * fact[n]) % M;
    int ans = (fact[n] * 1LL * binExpo(denomintor, M-2, M)) % M;
    return ans;
}

int main(){
    // calculate nCk
    int q;
    cin >> q;
    factorial(M);
    while(q--){
        int n, k;
        cin >> n >> k;
        nCr(n, k, M);
    }
    solve();
}