
/*
************************************************************* A. Twice ***************************************************************
                                                    time limit per test: 1 second
                                                    memory limit per test:256 megabytes
Kinich wakes up to the start of a new day. He turns on his phone, checks his mailbox, and finds a mysterious present. 
He decides to unbox the present.

Kinich unboxes an array a with n integers. Initially, Kinich's score is 0. He will perform the following operation any number of times:

Select two indices i and j (1≤i<j≤n) such that neither i nor j has been chosen in any previous operation and ai=aj. Then, add 1
to his score. Output the maximum score Kinich can achieve after performing the aforementioned operation any number of times.

Input
The first line contains an integer t (1≤t≤500) — the number of test cases.

The first line of each test case contains an integer n (1≤n≤20) — the length of a.

The following line of each test case contains n space-separated integers a1,a2,…,an (1≤ai≤n).

Output
For each test case, output the maximum score achievable on a new line.

*****************************************************************************************************************************************
*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> arr(n+10, 0);
        for(int i=1; i<=n; i++){
            cin >> arr[i];
        }
       
        // neither i nor j can be repaeted even if its swapped
        // i=1, j=2 is used so i=2 and j=3 is not allowed -> 
        //  since pair(1, 2) was used so (2, 3) cannot be used
        set<int> used;
        int score = 0;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                auto it1 = used.find(i);
                auto it2 = used.find(j);
                if(it1 != used.end() || it2 != used.end()){
                    continue;
                }
                if(arr[i] == arr[j]){
                    score++;
                    used.insert(i);
                    used.insert(j);
                }
            }
        }
        cout << score << endl;
    }
}