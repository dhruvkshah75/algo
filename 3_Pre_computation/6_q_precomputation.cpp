// ************************ GDC queries on codechef *********************//
// VERY IMPORTANT QUESTION
/*
    you are given an array of integers of size N. 
    you are given Q queries where each query is represented by two integers L, R. 
    You have to find the gcd of the array after excluding the part the part from the range L to R(inclusive) 1 based indexing
    you are guaranteed that that after excluding the part the array is non empty.

    input:
    first line is T no of test cases.
    for each test cases, first line contains two space separated integers N, Q.
    next line contians element of the arrays A
    and then next line L and R for each query

    Constraints: 
    subtask #1:
        2 <= T,N <= 100,
        1 <= Q <= N 
        1 <= A[i] <= 10^5
        1 <=L,R <= N, l<=R
    subtask #2:
        2 <= T,N <= 10^5,
        1 <= Q <= N 
        1 <= A[i] <= 10^5
        1 <=L,R <= N, l<=R
        sum of N over all test cases will be less than or equal to 10^6. // this ignores the complexity due to the test cases T

*/

// inbuilt function for gcd is __gcd(a,b) and its time complexity of O(log )

#include<bits/stdc++.h>
using namespace std;
#define SUBTASK2 = 2;
// #define Subtask = 0;

#ifdef Subtask
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        int a[n+10];
        for(int i=1; i<=n; i++){
            cin >> a[i]; 
        }

        while(q--){
            int l, r;
            cin >> l >> r;
            int gc = 0;
            for(int i=1; i<=l-1; i++){
                gc = __gcd(gc, a[i]);
            }
            for(int i=r+1; l<=n; i++){
                gc = __gcd(gc, a[i]);
            }
        }
    }
}
#endif


// for subtask 2 

// form two arrays stores the gcd of all the elements till ith in the forward direction 
// and a gc_backward array which will store the gcd of all the elements in the backward direction.

#ifdef SUBTASK2
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        int a[n+10];
        int *gc_f = new int[n+10];
        int *gc_b = new int[n+10];
        gc_f[0] = gc_b[n+1] = 0;

        for(int i=1; i<=n; i++){
            cin >> a[i];
            gc_f[i] = __gcd(gc_f[i-1], a[i]);   // filling the forwrd gcd array
            // for i=1 then gc_f[i-1] = 0
        }
        for(int i=n; i>=1; i--){
            gc_b[i] = __gcd(gc_b[i+1], a[i]);  // filling the backward array
            // for i=n gc_b[i+1] is 0 
        }

        while(q--){
            int l, r;
            cin >> l >> r;
            cout << __gcd(gc_f[l-1], gc_b[r+1]) << endl;
        }
        delete []gc_f;
        delete []gc_b;
    }
    return 0;
}
#endif