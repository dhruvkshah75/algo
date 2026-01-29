
/*
*********************************************** C. Vlad Building Beautiful Array ********************************************************
                                                time limit per test: 1 second
                                                memory limit per test: 256 megabytes
Vlad was given an array a of n positive integers. Now he wants to build a beautiful array b of length n from it.

Vlad considers an array beautiful if all the numbers in it are positive and have the same parity. 
That is, all numbers in the beautiful array are greater than zero and are either all even or all odd.

To build the array b, Vlad can assign each bi either the value ai or ai−aj, where any j from 1 to n
 can be chosen.

To avoid trying to do the impossible, Vlad asks you to determine whether it is possible to build a beautiful array b of length n
using his array a.

Input
The first line of input contains an integer t (1≤t≤104) — the number of test cases.

Then follow the descriptions of the test cases.
The first line of each case contains a single integer n (1≤n≤2⋅105) — the length of the array a.

The second line of each case contains n positive integers a1,a2,…,an (1≤ai≤109) — the elements of the array a.

It is guaranteed that the sum of n over all cases does not exceed 2*1e5.

Output
Output t strings, each of which is the answer to the corresponding test case. 
As the answer, output "YES" if Vlad can build a beautiful array b, and "NO" otherwise.

********************************************************************************************************************************
*/


/*
    note:
    odd - even = odd and odd-odd = even 
    if all elements are even or odd then array is already beuatiful 
    if an even integer is present at the start of the array then it cannot be made into a beautiful array
*/


#include<bits/stdc++.h>
using namespace std; 

int main(){
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        vector<int> a(n);
        int count_odd = 0;
        int count_even = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i] > 0){
                if(a[i]%2 == 0) count_even++;
                else count_odd++;
            } 
        }
        sort(a.begin(), a.end());
        if(count_even == n || count_odd == n){
            cout << "YES" << endl;
        }
        else{
            if(a[0]%2 == 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }

    }
    
}