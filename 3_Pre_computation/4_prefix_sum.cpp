// ************************** PREFIX SUM ********************
/*
    Given an array a of N integers. Given Q queries and in each query given L and R 
    print sum of array elements from index L to R (l, R included)

    Constraints:
    1 <= N <= 10^5
    1 <= a[i] <= 10^9
    1 <= Q <= 10^5
    1 <= L,R <= N
*/

/*
    Notes: this can be counted with the help of pre-computation
    the prefix sum array will store sum of all the previous sums so 
    ex the ith index element will store sum of all the indexes to the ith element
    prefix_sum[i] stores sum from 1-->i 
    given l and r so the required sum would be prefix_sum[r] - prefix_sum[l-1] as l and r both inclusive


*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N];
long long pf[N];  // array of prefix_sum 

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        pf[i] = pf[i-1] + a[i]*1LL;  
        // for i=1 pf[i-1] = 0 as it is globally declared array
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << pf[r] - pf[l-1] << endl;
    }
}

// time complexity of the above code is O(N) + O(Q) = O(N) = 2*10^5 iterations 








/*
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        long long sum = 0;
        for(int i=l; i<=r; i++){
            sum += a[i];
        }
        cout << sum << endl;
    }
}
*/