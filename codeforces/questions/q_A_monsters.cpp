/* 
    ***************************************** A. Monsters (easy version) *****************************************************
                                            time limit per test4 seconds
                                            memory limit per test512 megabytes
        This is the easy version of the problem. In this version, you only need to find the answer once. In this version, hacks are not allowed.
        In a computer game, you are fighting against n monsters. Monster number i has ai health points, all ai are integers. 
        A monster is alive while it has at least 1 health point.

        You can cast spells of two types:
        Spell1: 
            Deal 1 damage to any single alive monster of your choice.
        Spell2: 
            Deal 1 damage to all alive monsters. If at least one monster dies (ends up with 0 health points) as a result of this action, 
            then repeat it (and keep repeating while at least one monster dies every time).
            Dealing 1 damage to a monster reduces its health by 1.

        Spells of type 1 can be cast any number of times, while a spell of type 2 can be cast at most once during the game.
        What is the smallest number of times you need to cast spells of type 1 to kill all monsters?

        Input
        Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1e4). 
        The description of the test cases follows.

        Each test case consists of two lines. The first line contains a single integer n(1≤n≤2⋅105) — the number of monsters.

        The second line contains n integers a1,a2,…,an (1≤ai≤n) — monsters' health points.

        It is guaranteed that the sum of n over all test cases does not exceed 2*1e5;
        
        Output
        For each test case, print a single integer — the smallest number of times you need to cast spells of type 1 to kill all monsters.
*/





#include <bits/stdc++.h>
using namespace std;

// very important logic ---->>

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());  // sort the array

        vector<int> b(n);   // make a new array which contians 1s 2s 3s and so on
        b[0] = 1;
        for (int i = 1; i < n; i++){
            b[i] = min(b[i - 1] + 1, a[i]);  // if in a two elements are same then ex 1, 1 in array a then array b must also have 1 and 1 
        }
        long long spells = 0;
        for (int i = 0; i < n; i++){
            spells += a[i] - b[i];
        }
        cout << spells << '\n';
    }
    return 0;
}