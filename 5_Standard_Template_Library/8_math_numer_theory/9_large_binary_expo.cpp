// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int M = 1e9+7;

// iterative binary exponentiation
ll binExpo(ll a, ll b){
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

int main(){
    // if b >= 1e9 in case of this binary exponentiation then what do 
    // condtion b <= 1e18 
    // the parameter of b is long long max it can have is 1e18 so how to pass higher numbers 
    // calculate (50^(64^32)) % M how to calculate this 
    // a, b are coprime if gcd(a, b) is 1
    /*
        N -->> count K 
        such that 1 <= k <= N such that k, N are coprime 
        count of all those k values is the value of euler toitent function
        phi(5) -->> is 4 as values of k are 1,2,3,4 
    */

    /*
        formula very important 
        phi(n) = n*multiplication of (1-1/p) where p are the prime factors of n

        to calculate (a^b)%M 
        Eulers Thereom says that
        a^b is congruent to a^(b mod phi(n)) mod n    --->> thereom says that (a^b) mod M == a^(b mod phi(n));
        a is congruent to b mod n means that a%n == b i.e. remainder of a/n is b

    */

    // ETF value of a prime no is n-1 where n is the prime number 


    /*
        final note:
        (a^b) % M == a^(b % phi(M)) % M -->> M is any number 
        (a^b) % M == a^(b % (M-1)) % M  -->> M is prime number 
    
    */

}