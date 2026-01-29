
/*
******************************************************** D. GCD-sequence ****************************************************************
                                                    time limit per test: 2 seconds
                                                    memory limit per test: 256 megabytes
GCD (Greatest Common Divisor) of two integers xand y is the maximum integer z by which both x and y are divisible. 
For example, GCD(36,48)=12, GCD(5,10)=5, and GCD(7,11)=1.

Kristina has an array a consisting of exactly n positive integers. 
She wants to count the GCD of each neighbouring pair of numbers to get a new array b, called GCD-sequence.

So, the elements of the GCD-sequence b will be calculated using the formula bi=GCD(ai,ai+1) for 1≤i≤n−1.

Determine whether it is possible to remove exactly one number from the array a so that the GCD sequence b is non-decreasing 
(i.e., bi≤bi+1 is always true).

For example, let Khristina had an array a = [20,6,12,3,48,36]. If she removes a4=3 from it and counts the GCD-sequence of b, she gets:
b1=GCD(20,6)=2
b2=GCD(6,12)=6
b3=GCD(12,48)=12
b4=GCD(48,36)=12
The resulting GCD sequence b = [2,6,12,12] is non-decreasing because b1≤b2≤b3≤b4.

Input
The first line of input data contains a single number t (1≤t≤104) — he number of test cases in the test.

This is followed by the descriptions of the test cases.

The first line of each test case contains a single integer n (3≤n≤2⋅105) — the number of elements in the array a.

The second line of each test case contains exactly n integers ai (1≤ai≤109) — the elements of array a.

It is guaranteed that the sum of n over all test case does not exceed 2⋅105.

Output
For each test case, output a single line:
"YES" if you can remove exactly one number from the array a so that the GCD-sequence of b is non-decreasing; "NO" otherwise.
You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will all be recognized as a positive answer).

******************************************************************************************************************************************
*/

#include <bits/stdc++.h>
using namespace std;
 
bool good(vector<int>&b){
    int g = __gcd(b[0], b[1]);
    for(int i = 1; i < int(b.size()) - 1; i++){
        int cur_gcd = __gcd(b[i], b[i + 1]);
        if(g > cur_gcd) return false;
        g = cur_gcd;
    }
    return true;
}
 
void  solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    int g = -1;
    int to_del = -1;           // a flag to check if th gcd array is already in the ascending order;
    for(int i = 0; i < n - 1; i++){
        int cur_gcd = __gcd(a[i], a[i + 1]);
        if(cur_gcd < g){
            to_del = i;
            break;
        }
        g = cur_gcd;
    }
    if(to_del == -1){
        cout << "YES" << endl;
        return;
    }
    vector<int>b0 = a, b1 = a, b2 = a;         // creating three copies to remove i_del=i so checking by removing i, i-1, i+1;
    if(to_del > 0) b0.erase(b0.begin() + to_del - 1);  //Removes the element just before the to_del index (if to_del > 0).
    b1.erase(b1.begin() + to_del);                      //Removes the element at to_del itself.
    if(to_del < n - 1) b2.erase(b2.begin() + to_del + 1);  //Removes the element just after the to_del index (if to_del < n - 1).
    if(good(b0) || good(b1) || good(b2) ){
        cout << "YES" <<endl;
        return;
    }
    cout << "NO" << endl;
}
 
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}