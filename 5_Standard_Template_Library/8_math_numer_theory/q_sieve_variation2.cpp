/*
Problem: Hacking Decyrpting messages
Alex has started hacking websites, and also started learning encryption and decryption of messages. Once he faced an interesting issue, 
where he needs to decrypt the message in a different way.
Initially, he will be given an array A of N integers, and has to decrypt Q messages. 
In each message he will get an integer X, and if X can be converted into product of two different or same prime numbers, 
then the real message is "YES" (without quotes), otherwise the message is "NO" (without quotes).

To convert X, he can choose one element from array say Y (X should be divisible Y), and can divide X by Y any number of times 
(till X is divisible by Y). Help Alex in decrypting the messages.

Input Format:
First line will contain an integer N and Q,, denoting the number of elements in the array and number of encrypted messages respectively.
Next line will contain N space-separated integers representing the elements of the array.
In next Q lines, each line will contain an integer X , representing an encrypted message.

Output Format:
For each encrypted message, output the decrypted message in new line.

Constraints:
1 <= N <= 1e5;
0 <= a[i] <= 1e6
1 <= q <= 1e6;
0 <= X <= 1e6;


*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
// #define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 
const int N = 2e6+10;
vector<int> lp(N);
void lowestPrime(){
    for(int i=2; i<N; i++){  
        if(lp[i] == 0){
            for(int j=i; j<N; j+=i){
                if(lp[j] == 0) lp[j] = i;
            }
        }      
    }
}

vector<int> distinctPF(int x){
    vector<int> ans;
    while(x > 1){
        int prime = lp[x];
        while(x%prime == 0){
            x /= prime;
        }
        ans.pb(prime);
    }
    return ans;
}

int canRemove[N];

void solve(){
    int n, q;
    cin >> n >> q;
    unordered_set<int> a(n);
    fx(i, n, 0){
        int x;
        cin >> x;
        a.insert({x});
    }
    // mark all the numbers in the set and its powers -->> based on sieve logic 
    for(int i=2; i<N; i++){
        if(a.find(i) != a.end()){
            for(ll j=i; j<N; j *=i){
                canRemove[j] = 1;
            }
        }
    }

    // if the number is continuously divided from the num is it possible to form the given divided num as a product of two primes 
    while(q--){
        int num;
        cin >> num;
        vector<int> pf = distinctPF(num);
        bool isPossible = false;
        for(int i=0; i<pf.size(); i++){
            for(int j=i; j<pf.size(); j++){
                int product = pf[i]*pf[j];
                if(i == j && num % product != 0) continue;
                int to_remove = num/product;
                if(canRemove[to_remove] == 1 || to_remove == 1){
                    isPossible = true;
                    break;
                }
            }
            if(isPossible) break;
        }
        cout << ((isPossible) ? "YES" : "NO") << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lowestPrime();
    solve();
}
