/*
    Standard problems in dp:
    --> coin change
    --> edit distance
    --> Rod cutting
    --> longest increasing subsequence 
    --> Knapsack -> subset problem
    most problems are based on this or a version of this 

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


/*
    NOTES:
    question on fibonacci numbers 
    series is 0 1 1 2 3 5 8 // the next no is the sum of the previous no 

*/

int fibonacci(int n){  // returns the nth number of the fionacci
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

void solve(){
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}