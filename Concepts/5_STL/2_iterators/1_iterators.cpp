// in case of maps they dont hve indexes so to access the elements of it we use iterators

#include<bits/stdc++.h>
using namespace std;

/*
    note: vector<int> v; v.begin() is a iterator that points the first element nd v.end() 
    points to the next thing after the last element
*/

int main(){
    vector<int> v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<int>::iterator it;   // syntax for defining iterator
    it = v.begin();
    cout << *(it+1) << endl;
    // print all the elements by using iterators 
    for(it = v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    // for maps and sets they are not continues in memory so it+1 does not work but it++ works

    vector<pair<int, int>> v_p = {{1,2},{2,3},{3,4}};
    vector<pair<int, int>>::iterator it_p;
    for(it_p = v_p.begin(); it_p != v_p.end(); it_p++){
        cout << it_p->first << " " << it_p->second << endl;    // (*it_p).first or (*it_p).second
    }


}