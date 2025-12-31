// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
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

void highest_lowest_Prime(vector<int> &lp, vector<int> &hp, int psize){
    vector<bool> prime(psize+1, 1);
    prime[0] = prime[1] = false;
    for(int i=2; i<=psize; i++){
        if(prime[i] == true){
            lp[i] = hp[i] = i;
            for(int j=2*i; j<=psize; j+=i){
                prime[j] = false;
                hp[j] = i;
                if(lp[j] == 0) lp[j] = i;
            }
        }
    }
}

vector<pair<int,int>> primefactorisation(vector<int> &lp, int x){  // can also use map to store cnt and the prime factor 
    vector<pair<int,int>> ans;
    while(x > 1){
        int prime = lp[x];
        int cnt = 0;
        while(x%prime == 0){
            cnt++;
            x /= prime;
        }
        ans.push_back({prime, cnt});
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    // to find the prime factorisation of n
    vector<int> lp(n+1, 0);
    vector<int> hp(n+1, 0);
    highest_lowest_Prime(lp, hp, n);
    vector<pair<int,int>> pf = primefactorisation(lp, n);
    for(int i=0; i<pf.size(); i++){
        int cnt = 0;
        while(cnt != pf[i].second){
            cout << pf[i].first << " ";
            cnt++;
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}