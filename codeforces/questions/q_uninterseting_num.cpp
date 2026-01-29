
/*
********************************************************* C. Uninteresting Number **********************************************************
                                                        time limit per test: 2 seconds
                                                        memory limit per test: 256 megabytes
You are given a number n with a length of no more than 105.

You can perform the following operation any number of times: choose one of its digits, square it, 
and replace the original digit with the result. The result must be a digit (that is, if you choose the digit x, then the value of x2
 must be less than 10).

Is it possible to obtain a number that is divisible by 9 through these operations?

Input
The first line contains an integer t (1≤t≤104) — the number of test cases.

The only line of each test case contains the number n, without leading zeros. The length of the number does not exceed 105.

It is guaranteed that the sum of the lengths of the numbers across all test cases does not exceed 105.

Output
For each test case, output "YES" if it is possible to obtain a number divisible by 9 using the described operations, and "NO" otherwise.

You can output each letter in any case (lowercase or uppercase). 
For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

*************************************************************************************************************************************
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string str;
    cin >> str;
    vector<int> hsh(10);
    ll sum = 0;
    for (int i = 0; i < str.size(); i++){
        sum += (int)(str[i] - '0');
        hsh[(int)(str[i] - '0')]++;
    }
    int count2 = hsh[2];
    int count3 = hsh[3];
    int rem = sum % 9;
    int flag = 0;
    for (int i = 0; i <= count2; i++){
        for (int j = 0; j <= count3; j++){
            if ((sum + 2 * i + 6 * j) % 9 == 0){  // on squaring 2 -> 4 so value increased by 2 and for 3 -> 9 so value increases by 6
                cout << "YES" << endl;  // so 2*count2+6*count3+sum should be a multiple of 9 so it should count2 and count3 go in a loop
                flag = 1;
                return;
            }
        }
    }
    cout << "NO" << endl;
}


int main(){
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}