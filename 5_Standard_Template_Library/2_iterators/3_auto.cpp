#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,int>> v;
    v = {{1,2},{3,4},{5,6}};
    vector<pair<int,int>>::iterator it; 
    //or
     // auto detects the the datatype of it
    for(auto it=v.begin(); it!=v.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    for(auto &value: v){
        value.first++;
        value.second++;
    }
    for(auto value: v){
        cout << value.first << " " << value.second << endl;
    }
}