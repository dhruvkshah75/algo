
/*
************************************************ B. 378QAQ and Mocha's Array ****************************************************
                                                time limit per test: 1 second
                                                memory limit per test: 256 megabytes
Mocha likes arrays, so before her departure, 378QAQ gave her an array a consisting of n positive integers as a gift.

Mocha thinks that a is beautiful if there exist two numbers i and j (1≤i,j≤n, i≠j) such that for all k (1≤k≤n), ak
is divisible† by either ai or aj.

Determine whether a is beautiful.
†
 x is divisible by y if there exists an integer z such that x=y⋅z.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). 
The description of the test cases follows.

The first line of each test case contains a single integer n (3≤n≤105) — the length of the array a
.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array a
.

It is guaranteed that the sum of n over all test cases does not exceed 105
.

Output
For each test case, output "Yes" if array a is beautiful, and output "No" otherwise.

You can output "Yes" and "No" in any case (for example, strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive response).

*******************************************************************************************************************************************

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// check the divisibility by min then make a new array of all those not divisible 

void solve(){
    int n;
    cin >> n;
    bool check1 = false;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] == 1) check1 = true;
    }
    if(check1){
        cout << "YES" << endl;
        return;
    }

    int min = *min_element(a.begin(), a.end());
    vector<int> non_div;
    int count1 = 0;
    for(int i=0; i<n; i++){
        if(a[i]%min != 0) non_div.push_back(a[i]);
        else count1++;
    }

    if(count1 == n){
        cout << "YES" << endl;
        return;
    }
    else{
        int min2 = *min_element(non_div.begin(), non_div.end());
        for(int j=0; j<non_div.size(); j++){
            if(non_div[j]%min2 != 0){
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
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