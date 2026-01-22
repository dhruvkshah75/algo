#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    int ct=0, sum=0;   // to get no of divisors and sum of divisors
    for(int i=1; i*i<=n; i++){  // O(Sqrt(N))   
        if(n%i == 0){
            ct++; sum += i;
            if(i!=n/i){
                ct++;    // as the loop runs till sqrt(n) we have to get both the divisors from this step
                sum += n/i;
            }
        }
    }


    /*
        v.imp 
        this method is also slow so we can calculate this by using a formula based on prime factorisation
        eg 36 = 2^2 * 3^2  --->> [2, 2, 3, 3]
        any divisor will be a subset of this prime factorisation
        x = p1^n1 * p2^n2 * p3^n3 * ...
        total no of divisors = (n1+1)*(n2+1)*(n3+1)*....
        sum of divisors = ((p1^(n1+1)-1)/(p1-1)) * ((p2^(n2+1)-1)/(p2-1)) * ....

    */
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}