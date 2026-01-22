// to calculate a^b -->> divide and conquer
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int M = 1e9+7;

// recursive binary exponentiation
ll binExpoRecur(ll a, ll b){               // to calculate a^b % M
    if(b==0) return 1;
    ll res = binExpoRecur(a, b/2);
    if(b&1) return (a*((res*res) % M)) % M;
    else return (res*res) % M;
}

// faster than recursive
// iterative binary exponentiation
ll binExpo(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans*a) % M;
        }
        a = (a*a) % M;     // tracks the current power of a 
        b = b >> 1;  // right shift to b
    }
    return ans;
}

int main(){
    // pow(x, y) -->> returns double value -->> so dont use this
    // 2^16  can be calculate by using divide and conquer
    /*
        2^16 = 2^8 * 2^8
        2^8 = 2^4 * 2^4
        2^4 = 2^2 * 2^2
        2^2 = 2^1 * 2^1
        // O(log(b)) b is the power

        for odd power 
        3^13 = 3^1 * 3^12 now use divide and conquer for 3^12 
        3^12 = 3^6 * 3^6
        3^6 = 3^3 * 3^3
        3^3 = 3^1 * 3^2
        3^2 = 3^1 * 3^1
    */
   int a = 2, b = 13;
   ll ans = binExpoRecur(a*1LL, b*1LL);
   cout << ans << endl;

   /*
    int a = 2 an b = 13 
    write the binary of 13 -->> (1101)2 
    ------------------->> 2^(8+4+0+1) -->> 2^8 * 2^4 * 2^0 * 2^1

   */
}


