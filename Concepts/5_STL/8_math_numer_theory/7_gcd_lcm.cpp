#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

// Euclid algorithm to find gcd
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}

int main(){
    // gcd of three numbers is taken like gcd(c, gcd(a, b));
    // find the minimum fraction of this 12/18
    // find the gcd(12, 18) and then divide the numerator and denominator by the gcd 
    // 12/6 = 2 and 18/6 = 3 -->> 2/3 is the minimum fraction
}
