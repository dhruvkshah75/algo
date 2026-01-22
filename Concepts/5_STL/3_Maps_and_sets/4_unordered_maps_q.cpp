/*
    given N strings and Q queries. in each query and are given a string
    print the frquency of that string
    constraints:
    N <= 1e6;
    |S| <= 100;
    Q <= 1e6;
*/

// cant use maps as inputting and outputting data has a higher time complexity

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<string,int> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        m[str]++;
    }

    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        auto it = m.find(s);
        if(it == m.end()) cout << "No value" << endl;
        else cout << it->second << endl;
    }
}