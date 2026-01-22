/*
    Given N strings, print unique strings in lexigraphical order with their frequency 
    N <= 1e5;
    |S| <= 100; 
    eg input:
    8
    abc
    def
    abc
    ghj
    jkl
    ghj
    ghj
    abc
*/

// this question uses maps it cant be used for large contraints as putting data and accessing data from map has higher time complexity than O(1);
// ex map<string,int> m; -->> m[s] = k has time compexity of O(s.size()*log(n));

// this type of question can be easily be solved with the help of maps as it stores data in order of the key 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> m;  

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        m[s]++;   // this thing also has a time complexity as it first compares its string     
                  // index is the string and this adds to it frequency
    }

    for(auto &value: m){
        cout << value.first << " " << value.second << endl;
    }

}