
/*
******************************************** B. Turtle Math: Fast Three Task ***************************************************
                                            time limit per test: 2 seconds
                                            memory limit per test: 256 megabytes
You are given an array a1,a2,…,an.

In one move, you can perform either of the following two operations:
Choose an element from the array and remove it from the array. As a result, the length of the array decreases by 1;
Choose an element from the array and increase its value by 1.
You can perform any number of moves. If the current array becomes empty, then no more moves can be made.

Your task is to find the minimum number of moves required to make the sum of the elements of the array a divisible by 3. 
It is possible that you may need 0 moves.

Note that the sum of the elements of an empty array (an array of length 0) is equal to 0.

Input
The first line of the input contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤105).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤104).

The sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output a single integer: the minimum number of moves.

***********************************************************************************************************************************
*/



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
        }
        int rem = sum%3;
        if(rem==0){
            cout << 0 << endl;
            continue;
        }
        
        bool can_remove = false;
        for(int i=0; i<n; i++){
            if(a[i]%3 == rem){
                can_remove = true;
                break;
            }
        }
        if(can_remove || rem == 2){
            cout << 1 << endl;
            continue;
        }

        if(rem == 1){
            cout << 2 << endl;
            continue;
        }
    }
}