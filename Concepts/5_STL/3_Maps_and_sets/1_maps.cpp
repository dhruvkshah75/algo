#include<bits/stdc++.h>
using namespace std;

// create a mapping between a key and its value in a sorted manner; --> red black trees -> is a data structure
// every element of a map is a pair key and its value
// but in unordered map store in a non sorted way

int main(){
    map<int,string> m;
    m[1] = "abc"; // 1 is the key and its value is "abc"
    m[5] = "cdc"; // O(log(n))
    m[3] = "acd";
    m.insert({4, "afg"});
    m[6];  // this also takes O(log(n));
    map<int,string>::iterator it;
    for(it= m.begin(); it!=m.end(); it++){
        cout << it->first << " " << it->second << endl;
    } // it will print in a sorted order.

    // directly printing without using iterators
    for(auto &pr: m){    // time complexity of this loop is O(nlog(n))
        cout << pr.first << " " << pr.second << endl;     // to access anything from map is O(log(n))
    }
    cout << "size: " << m.size() << endl;

    // keys in a map are unique

// ************************ v.imp functions in maps ***************
    // very important use is m.find 
    auto it1 = m.find(3); // O(Log(n))   //--> this m.find() returns a iterator to the entire location
    if(it1 == m.end()) cout << "NO VALUE" << endl;
    else cout << it1->first << " " << it1->second << endl;

    m.erase(5);  // remove the element  // O(log(n))
    // can also do like m.erase(it1)  delete the element present at that iterator
    if(it1 != m.end()){
        m.erase(it1); // erases the data present at it1
    } // m.erase() only works it iterator is not m.end()

    // .clear is common function works for all containers
    //ex
    m.clear(); // clears all the data stored by the map;

    map<string, string> m1;
    m1["abcd"] = "abcd";   // insertion time depends on size of the key i.e. s.size()*log(n);
    

}