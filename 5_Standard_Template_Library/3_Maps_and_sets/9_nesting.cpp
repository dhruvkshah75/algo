// nesting in maps and sets 

#include<bits/stdc++.h>
using namespace std;

int main(){
    map<pair<int,int>,int> m;
    pair<int,int> p1, p2;
    p1 = {1, 2};
    p2 = {2, 3};
    cout << (p1 < p2) << endl;     //this will print 1 as p1<p2 as p1.first < p2.first
    // if both p1.first and p2.first are same then it will compare the seconds

    map<set<int>,int> m1;
    set<int> s1, s2;
    s1 = {1, 2, 3, 3, 4};
    s2 = {1, 2, 3, 5};
    // in this case it will compare the s1 and s2 in the same way as it did for pair 
    // first it will compare the first then second and then third and so on 
    // s2 > s1;
    // in similar ways in maps sets and vector<int> values are compared 

    map<pair<string,string>,vector<int>> m2;  // a nested map
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string fn, ln;
        int ct;
        cin >> fn >> ln >> ct;
        for(int j=0; j<ct; j++){
            int x;
            cin >> x;
            m2[{fn, ln}].push_back(x);         // m[{fn, ln}] is a vector so we can use all vector functions on it 
        }
    }


    for(auto &pr: m2){            // pr is a iterator for the map so pr.first denotes the pair and pr.second denotes the vector
        auto &full_name = pr.first;
        auto &list = pr.second;
        cout << full_name.first << " " << full_name.second << endl;
        for(auto &element: list){                 // for(int i=0; i<list.size(); i++)
            cout << element << " ";
        }
        cout << endl;
    }

    // use a map instead of multimap as map<vector<int>,int> m  --->> store multiple keys

}