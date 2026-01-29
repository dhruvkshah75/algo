/*
    ****************************************************** A. Divan and a Store *************************************************
                                                        time limit per test: 1 second
                                                        memory limit per test: 256 megabytes
    Businessman Divan loves chocolate! Today he came to a store to buy some chocolate. Like all businessmen, Divan knows the value of money, 
    so he will not buy too expensive chocolate. At the same time, too cheap chocolate tastes bad, so he will not buy it as well.

    The store he came to has n different chocolate bars, and the price of the i-th chocolate bar is ai dollars. 
    Divan considers a chocolate bar too expensive if it costs strictly more than r dollars. 
    Similarly, he considers a bar of chocolate to be too cheap if it costs strictly less than l dollars. 
    Divan will not buy too cheap or too expensive bars.

    Divan is not going to spend all his money on chocolate bars, so he will spend at most k dollars on chocolates.

    Please determine the maximum number of chocolate bars Divan can buy.

    Input
    Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). 
    Description of the test cases follows.

    The description of each test case consists of two lines. The first line contains integers n, l, r, k (1≤n≤100, 1≤l≤r≤109, 1≤k≤109)
    — the lowest acceptable price of a chocolate, the highest acceptable price of a chocolate and Divan's total budget, respectively.

    The second line contains a sequence a1,a2,…,an (1≤ai≤109) integers — the prices of chocolate bars in the store.

    Output
    For each test case print a single integer — the maximum number of chocolate bars Divan can buy.

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long l, r, k;
        cin >> n >> l >> r >> k;
        vector<long long> arr;
        for(int i=0; i<n; i++){
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());

        long long count = 0;
        long long int total = 0;
        for(int i=0; i<n; i++){
            if(arr[i] >= l && arr[i] <= r){
                total+=arr[i];
                if(total <= k){
                    count++;
                }
                else break;
            }
        }
        cout << count << endl;
    }
}