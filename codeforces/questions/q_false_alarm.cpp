
/*
*************************************************** A. False Alarm ***************************************************************
                                                time limit per test: 1 second
                                                memory limit per test: 256 megabytes
Yousef is at the entrance of a long hallway with n doors in a row, numbered from 1 to n. He needs to pass through all the doors from 1
to n in order of numbering and reach the exit (past door n).

Each door can be open or closed. If a door is open, Yousef passes through it in 1 second.
 If the door is closed, Yousef can't pass through it.

However, Yousef has a special button which he can use at most once at any moment. This button makes all closed doors become open for x seconds.

Your task is to determine if Yousef can pass through all the doors if he can use the button at most once.

Input
The first line of the input contains an integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains two integers n,x (1≤n,x≤10) — the number of doors and the number of seconds of the button, respectively.

The second line of each test case contains n integers a1,a2,...,an (ai∈{0,1})
 — the state of each door. Open doors are represented by '0', while closed doors are represented by '1'.

It is guaranteed that each test case contains at least one closed door.

Output
For each test case, output "YES" if Yousef can reach the exit, and "NO" otherwise.
You can output the answer in any case (upper or lower). 
For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses

******************************************************************************************************************************************
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, x;
        cin >> n >> x;
        vector<int> d(n+1);
        vector<int> hsh(2);
        for(int i=1; i<=n; i++){
            cin >> d[i];
            hsh[d[i]]++;
        }
        if(hsh[0] == n){
            cout << "YES" << endl;
            continue;
        }
        int index = 0;
        for(int i=1; i<=n; i++){
            if(d[i] == 1){
                index = i;
                break;
            } 
        }
        int l_index = 0;
        for(int i=n; i>0; i--){
            if(d[i] == 1){
                l_index = i;
                break;
            }
        }

        int left = l_index - index + 1;
        if(left <= x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}