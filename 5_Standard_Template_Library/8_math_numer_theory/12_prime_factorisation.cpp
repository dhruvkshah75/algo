
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int M = 1e9+7;

void primefactors(){
    int n;
    cin >> n;
    vector<int> prime_factors;
    for(int i=2; i*i<=n; i++){
        while(n%i == 0){
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if(n > 1){   // eg 24 removes all the 2s and 3 is left there is no prime no before sqrt of 3 so this condition is put 
        prime_factors.push_back(n);
    }
    // O(Sqrt(N)) -->> time complexity as n also decreases
}

void solve(){
    int n;
    cin >> n;
    bool isPrime = true;
    if(n == 1){
        cout << 0 << endl;
    }
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            isPrime = false;
            break;
        } 
    }
    cout << isPrime << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}