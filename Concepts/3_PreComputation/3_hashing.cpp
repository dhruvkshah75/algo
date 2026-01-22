// ****************************** HASHING ************************//

/*
    given array a of N integers. Given Q queries and in each query given a number X, 
    print count of that number in array.
    Constraints:
    1 <= N <= 10^5
    1 <= a[i] <= 10^7
    1 <= Q <= 10^5

*/

// caan be solved with the help of hashing- a pre computation technique

#include<bits/stdc++.h>
using namespace std;

const int S = 1e7+10;
int hsh[S];  // any global array is initialised to 0

// hash array consists count of all elements where the indices are the elements and the the value it stores is the count.

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int j=0; j<n; j++){
        cin >> a[j];
        hsh[a[j]]++;  // hsh is a global array so the initial value is 0;
    }

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << hsh[x] << endl;   // count.
    }
    // time complexity is O(N) + O(Q) = O(N) = 2*10^5
}

/*
    if the inputted array contains negative no such that -10^5 <= a[i] <= 10^5 then 
    hash array cannot store negative counts as no negative indices 
    so we can make the range of a[i] positive by adding 10^5 to every element of the inputted array. 
*/



/*
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        int ctr = 0;
        for(int i=0; i<n; i++){
            if(a[i] == x){
                ctr++;
            }
        }
        cout << ctr << endl;
    }
}
*/

/*  the time complexity of the above code is 
    O(N) + O(Q*N) = O(N^2) = 10^10 iterations cannot occur in 1 sec 

*/