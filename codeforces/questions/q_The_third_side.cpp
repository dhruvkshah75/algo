
/*
********************************************************** B. The Third Side *************************************************************
                                                        time limit per test: 2 seconds
                                                        memory limit per test: 256 megabytes
The pink soldiers have given you a sequence a consisting of n positive integers.

You must repeatedly perform the following operation until there is only 1 element left.

Choose two distinct indices i and j.
Then, choose a positive integer value x such that there exists a non-degenerate triangle∗ with side lengths ai, aj, and x.
Finally, remove two elements ai and aj, and append x to the end of a.
Please find the maximum possible value of the only last element in the sequence a.

∗
A triangle with side lengths a, b, c is non-degenerate when a+b>c, a+c>b, b+c>a.

InputEach test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). 
The description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤2⋅105).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤1000) — the elements of the sequence a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output the maximum possible value of the only last element on a separate line.

************************************************************************************************************************************
*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> a;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        if(n==1){
            cout << a[0] << endl;
            continue;
        } 
        vector<int>::iterator it;
        it = (--a.end());
        while(true){
            int num1 = *it;
            auto it2 = (--it);
            int num2 = *it2;
            a.erase(it);
            a.erase(it2);
            a.push_back(num1+num2-1);
            it = (--a.end());
            if(it == a.begin()) break;
        }
        cout << a[0] << endl; 
    }
}