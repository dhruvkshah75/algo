#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void preComputePrime(vector<bool> &primes, int len){
    primes[0] = primes[1] = false;
    for(int i=2; i<len; i++){
        if(primes[i] == true){
            for(int j=2*i; j<len; j+=i){
                primes[i] = false;
            }
        }
    }
}
// O(nLog(Log(n))) -->> time complexity

int main(){
    const int N = 1e7+10;
    vector<bool> prime(N, 1);
    preComputePrime(prime, N);
}