
/*
********************************************************* A. Line Breaks ***************************************************************
                                                    time limit per test: 1 second
                                                    memory limit per test: 256 megabytes
Kostya has a text s consisting of n words made up of Latin alphabet letters. 
He also has two strips on which he must write the text. The first strip can hold m characters, while the second can hold as many as needed.

Kostya must choose a number x and write the first x words from s on the first strip,
while all the remaining words are written on the second strip. 
To save space, the words are written without gaps, but each word must be entirely on one strip.

Since space on the second strip is very valuable, Kostya asks you to choose the maximum possible number x such that all words s1,s2,…,sx
fit on the first strip of length m.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains two integers n and m (1≤n≤50; 1≤m≤500) 
— the number of words in the list and the maximum number of characters that can be on the first strip.

The next n lines contain one word si of lowercase Latin letters, where the length of si does not exceed 10.

Output
For each test case, output the maximum number of words x such that the first x words have a total length of no more than m

****************************************************************************************************************************************.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int tt;
    cin >> tt;
    while (tt--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,string>> input;
        for(int i = 0; i < n; i++){
            string str;
            cin >> str;
            input.push_back({str.size(), str});
        }

        int len = 0;
        int count = 0;
        auto it = input.begin();
        if(input[0].first > m) cout << count << endl;      // if the first str is not enough to fit inside the first strip
        else{                   
            for(int i=0; i<n; i++){
                len += input[i].first;
                int len_next = input[i+1].first;
                int check_len = len + len_next;
                count++;
                if(check_len > m) break;
            }
            cout << count << endl;
        }
    }
}
