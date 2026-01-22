#include<bits/stdc++.h>
using namespace std;

// maps, multimaps, unordered maps

int main(){
    /*
        all the functions of a map and unordered map are same.
        major differences :
        1. inbuilt implementation -> uses hash tables
        2. Time complexity -> insertion and accessing data from u_map is o(1) because of the use of hash tables
        3. valid keys datatyes  ->
    */

    unordered_map<int, string> m;
    m[1] = "abc";   // O(1);
    m[5] = "cdc";
    m[3] = "acd";
    m[6] = "a";
    m[5] = "cde"; 
    auto it = m.find(7);   // O(1);
    if(it != m.end()){
        m.erase(it);    // O(1);    // removes that data at the iterator it
    }
    auto it1 = m.find(3);
    if(it1 == m.end()) cout << "NO VALUE" << endl;
    else cout << it->first << " " << it->second << endl;

    // unordered_map<pair<int,int>, string> m;  -->> this does not exist for unordered maps 
    // unordered maps only exists for basic things 
    // map<pair<int,int>, string> m    --->> this exists as it does not use hash tables 



    // multimap are similar to maps
    // so in a maps keys are uique example is line 15 and line 18 
    // but in multimap identical keys can exist 

    // so if u want to store multiple things for the same key u can just use a map like this:
    map<int,vector<string>> m1;
    // so for every key there is a array or vector of strings better than multimap
}