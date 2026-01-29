/***************************************************** MOVE TO THE END ****************************************************************
                                                    time limit per test: 2 seconds
                                                    memory limit per test: 512 megabytes
You are given an array a consisting of n integers.

For every integer k from 1 to n, you have to do the following:

choose an arbitrary element of a and move it to the right end of the array (you can choose the last element, then the array won't change);
print the sum of k last elements of a;move the element you've chosen on the first step to its original position 
(restore the original array a).
For every k, you choose the element which you move so that the value you print is the maximum possible.

Calculate the value you print for every k.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer n (1≤n≤2⋅105);
the second line contains n integers a1,a2,…,an (1≤ai≤109).
Additional constraint on the input: the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, print n integers. The i-th of these integers should be equal to the maximum value you can print if k=i.

****************************************************************************************************************************************
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279

/*
    if u would find the max element from begining to end-k 
    then it would turn out to O(n^2) so create a pmax array
    contianing the max element of the array till the kth.
*/ 

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> pf(n+1);
    vector<ll> pmax(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
        pf[i] = pf[i-1] + a[i];
        pmax[i] = max(pmax[i-1], a[i]);
    }

    for(int k=1; k<=n; k++){
        ll max = pmax[n-k];
        if(max >= a[n-k+1] && k!=n){
            ll ans = pf[n] - pf[n-k] - a[n-k+1] + max;
            cout << ans << " ";
        }
        else{
            ll ans = pf[n] - pf[n-k];
            cout << ans << " ";
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}