#include<bits/stdc++.h>
using namespace std;

void print(set<string> &s){
    for(auto value: s){
        cout << value << endl;
    }
    cout << endl;
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << endl;
    }
}

int main(){
    // collections of items are caled sets
    // sets, unordered_sets, multiset

    set<string> s;   //stores in sorted order 
    s.insert("abc");  // similar to maps inserting and accsessing the data is O(log(n));
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("abc");  // only stores unique values
    set<string>::iterator it;
    // auto it;
    it = s.find("abc");
    if(it == s.end()) cout << "No value" << endl;
    else cout << *it << endl;

    // s.erase(it) or s.erase("abc") also works and deletes that element.

    print(s);


    unordered_set<string> s1;
    // does not store in sorted order all the functions to this set becomes O(1) same as the unordered_map
    // this is used when u dont have to store in a sorted order 
    // all the functions remain same 

}