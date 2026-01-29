
/*
******************************************************** A. Two Vessels **************************************************************
                                                    time limit per test: 1 second
                                                    memory limit per test: 256 megabytes
You have two vessels with water. The first vessel contains a grams of water, and the second vessel contains b grams of water. 
Both vessels are very large and can hold any amount of water.

You also have an empty cup that can hold up to c grams of water.

In one move, you can scoop up to c grams of water from any vessel and pour it into the other vessel. 
Note that the mass of water poured in one move does not have to be an integer.

What is the minimum number of moves required to make the masses of water in the vessels equal? 
Note that you cannot perform any actions other than the described moves.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). 
The description of the test cases follows.

Each test case consists of a single line containing three integers a
, b
, and c
 (1≤a,b,c≤100
) — the mass of water in the vessels and the capacity of the cup, respectively.

Output
For each test case, output a single number — the minimum number of moves required to make the masses of water in the vessels equal. It can be shown, that it is always possible.
*/

#include<bits/stdc++.h>
using namespace std; 

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == b){
            cout << 0 << endl;
            continue;
        }
        else{
            int big = max(a, b);
            int small = min(a, b);
            int count = 0;
            while(true){
                if(big == small) break;
                if(big - small <= c && big-small > 0){
                    count++;
                    break;
                }
                else if(big - small <=c && big-small < 0) break;    // this line is for tt like 1 4 2 
                big -= c;
                small += c;
                count ++;
            }
            cout << count << endl;
        }
    }
}