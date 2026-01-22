
/*
    given n strings and q queries. in each query you are given a string print yes if the 
    string print yes if the string is present else print no. 
    N <= 1e6;
    |S| <=1 100
    Q <= 1e6
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<string> s;    
    // inside of a unoredered_set cannot be something complex as they use hash tables and for complex functions they are not inbuilt
    // accessing and inputting data is O(1)
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        s.insert(str);
    }
    int q;
    cin >> q;
    while(q--){
        string str;
        cin >> str;

        auto it = s.find(str);
        if(it == s.end()) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}