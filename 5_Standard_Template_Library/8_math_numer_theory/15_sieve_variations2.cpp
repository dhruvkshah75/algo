#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

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

int main(){
    // divisor variation of sieve 
    const int N = 1e7+10;
    vector<int> divisors[N];
    for(int i=2; i<N; i++){
        for(int j=i; j<N; j+=i){
            divisors[j].push_back(i);
        }
    }
    // O(nLog(n));

    for(int i=1; i<10; i++){
        for(int div: divisors[i]){
            cout << div << " ";
        }
        cout << endl;
    }
}