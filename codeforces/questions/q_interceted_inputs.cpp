
/*  
********************************************************* B. Intercepted Inputs ******************************************************
                                                        time limit per test: 2 seconds
                                                        memory limit per test: 256 megabytes
To help you prepare for your upcoming Codeforces contest, Citlali set a grid problem and is trying to give you a n by m
grid through your input stream. Specifically, your input stream should contain the following:

The first line contains two integers n and m — the dimensions of the grid.The following n lines contain m
integers each — the values of the grid. However, someone has intercepted your input stream, 
shuffled all given integers, and put them all on one line! Now, there are k integers all on one line, 
and you don't know where each integer originally belongs. Instead of asking Citlali to resend the input, 
you decide to determine the values of n and m yourself.

Output any possible value of n and m that Citlali could have provided.

Input
The first line contains an integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains an integer k (3≤k≤2⋅105) — the total number of inputs in your input stream.

The following line of each test case contains k integers a1,a2,…,ak (1≤ai≤k) — the shuffled inputs of your input stream. 
It is guaranteed that n and m are contained within the k integers.

It is guaranteed that the sum of k over all test cases does not exceed 2⋅1e5.

Output
For each test case, output two integers, one possible value of n and m. If multiple possible answers exist, output any.

****************************************************************************************************************************************
*/



/*
    note: to get the rquired combination of i*j to be equal to int_left.  
    it would be possibe through a nested for loop but it would not work in this case 
    it is possible if we create a hash array to store the count of all the values and then just do 
    n*m = int_left m = int_left/n if it is a integer and its count should be 1 or more 
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int k;
        cin >> k;
        vector<int> a(k+10);
        vector<int> hsh(k+10, 0); // holds the count of every a[i]
        for(int i=1; i<=k; i++){
            cin >> a[i];
            hsh[a[i]]++;
        }

        int int_left = k-2;
        bool done = false;
        for(int i=1; i<=k && done == false; i++){
            if(a[i]*a[i] == int_left && hsh[a[i]] >=2){
                cout << a[i] << " " << a[i] << endl;
                done = true;
            }
        }
        if(done) continue;

        pair<int,int> ans;
        for(int j=1; j<=k && done == false; j++){
            double m = (double)int_left/j;
            int m1 = int_left/j;
            if(fabs(m1-m) < 1e-6 && hsh[m1] > 0 && j != m1){     // fabs(m1-m) for floating point error and j!=m1 --> j==m1 is the first case
                ans.first = j;
                ans.second = m1;
                done = true;
            }
        }
        cout << ans.first << " " << ans.second << endl;
    }
}