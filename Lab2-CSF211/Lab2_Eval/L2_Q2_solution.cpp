#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> pow2(41);
int how_many_rights = 0; 

char recursion(ll k, ll n) {
    int len = pow2[n] - 1;
    if(n == 1) return '0';
    if(k == len/2) return '1';
    
    // lies in the left half 
    if(k < len/2) {
        return recursion(k, n-1);
    }
    else {
        how_many_rights += 1;
        // Mirror the index: k becomes (len - 1 - k) and shift the it back to the right array
        return recursion(len - 1 - k, n - 1);
    }
}

char solve(ll n, ll k) {
    how_many_rights = 0;
    // we store the first 40 powers of two in an array
    pow2[0] = 1;
    for(int i=1; i<41; i++) {
        pow2[i] = pow2[i-1] * 2LL;
    }
    // the length of Sn is 2^n - 1;
    ll len = pow2[n] - 1;
    // note: len/2  => (pow2[n] - 1) / 2 gives the middle index 
    // we have to find the k - 1 th index 
    char ans = recursion(k-1, n);
    
    if(how_many_rights & 1) {
        return (ans == '1') ? '0' : '1';
    }
    return ans;
}
