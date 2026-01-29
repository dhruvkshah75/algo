
/*
**************************************************** B. Restore the Weather ***************************************************
                                                    time limit per test: 1 second
                                                    memory limit per test: 256 megabytes

You are given an array a containing the weather forecast for Berlandia for the last n days. That is, ai— is the estimated air 
temperature on day i (1≤i≤n).

You are also given an array b — the air temperature that was actually present on each of the days. 
However, all the values in array b are mixed up.

Determine which day was which temperature, if you know that the weather never differs from the forecast by more than k degrees. 
In other words, if on day i the real air temperature was c, then the equality |ai−c|≤k is always true.

For example, let an array a = [1,3,5,3,9] of length n=5 and k=2 be given and an array b = [2,5,11,2,4]. 
Then, so that the value of bi corresponds to the air temperature on day i, we can rearrange the elements of the array b
so: [2,2,5,4,11]. Indeed:
On the 1st day, |a1−b1|=|1−2|=1, 1≤2=k is satisfied;
On the 2nd day |a2−b2|=|3−2|=1, 1≤2=k is satisfied;
On the 3rd day, |a3−b3|=|5−5|=0, 0≤2=k is satisfied;
On the 4th day, |a4−b4|=|3−4|=1, 1≤2=k is satisfied;
On the 5th day, |a5−b5|=|9−11|=2, 2≤2=k is satisfied.
Input
The first line of input data contains a single integer t (1≤t≤104) — the number of test cases.
The description of the test cases follows.

The first line of each test case contains two integers n (1≤n≤105) and k (0≤k≤109) — 
the number of days and the maximum difference between the expected and actual air temperature on each day.

The second line of each test case contains exactly n integers — elements of array a (−109≤ai≤109).

The third line of each test case contains exactly n integers — elements of array b (−109≤bi≤109).

It is guaranteed that the sum of n over all test cases does not exceed 105, and that the elements of array b can always be 
rearranged so that the equality |ai−bi|≤k is true for all i.

Output
On a separate line for each test case, output exactly n numbers — 
the values of air temperature on each of the days in the correct order.

If there is more than one answer — output any of them.

*********************************************************************************************************************************
*/


// v.imp technique to restore the location of the elements in a vector which was later sorted.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>>a(n);             // storing a as a pair a[i].first are inputs and a[i].second = i is idetentifier
        vector<int>b(n);
        vector<int>ans(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }
        for(auto &i : b) cin >> i;
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++){
            ans[a[i].second] = b[i];
        }
        for(auto &i : ans) cout << i << ' ';
        cout << endl;
    };
}