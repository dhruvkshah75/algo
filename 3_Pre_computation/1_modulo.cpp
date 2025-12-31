// many questions show print the answer modulo M?
/************************* MODULAR ARITHMETIC ********************/
/*
    (a+b)%M = (a%M + b%M)%M
    (a*b)%M = (a%M * b%M)%M
    (a-b)%M = (a%M - b%M + M)%M
    (a/b)%M = (a%M * (b-1)%M)%M      i.e. a modulo M * b inverse modulo M whole modulo M


*/


/*
    given a number N print its factorial 
    1 <= N <= 100
    print answer module M
    where M = 47
    in many question M is given as 10^9 + 7; this value is very close INT_MAX and this value is a prime number 
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int M = 1e9+7;  // i.e. 10^9+7
    long long fact = 1;
    for(int i=2; i<=n; i++)
        fact = (fact*i)%M;   // taking modulo works in every step
    cout << fact << endl;   // possiblity of overflow as factorial is very big for higher numbers
}