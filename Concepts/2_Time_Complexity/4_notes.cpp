#include<bits/stdc++.h>
using namespace std;

/*
    given T test cases and an array of size N
    print sum of elements of the array in each test case
    constraints: 
    1 <= T <= 100000
    1 <= N <= 100000;
    1 <= a[i] <= 1000
    v.imp statement:: 
    note: sum over all test cases is < 10^7
*/


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sum = 0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            sum+=x;
        }
        cout << sum << endl;
    }
}

/*
    the last constraint change the time complexity from o(n^2) because:
    if t=0 takes n0 
       t=1 takes n1
       .
       .
       .
       t=t takes nt
       total no of iterations will be: n0 + n1 + n2 + ...... + nt < 10^7
       so time complexity becomes o(10^7) and will run in 1 sec
*/