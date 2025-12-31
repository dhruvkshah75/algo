#include<bits/stdc++.h>
using namespace std;

// write iterators in short (not my first choice)

int main(){
    vector<int> v = {2, 3, 5, 6, 7};
    vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    for(int value: v){   //pass by value the elements by copying 
        cout << value << " ";
    }
    cout << endl;
    for(int &value: v){  // the value of elements are passed by reference 
        value++;
    }
    for(int value: v){
        cout << value << " ";
    }
    cout << endl;

    vector<pair<int,int>> v_p = {{1,2}, {3,4}};
    for(pair<int,int> &value: v_p){
        value.first++;
        value.second++;
    }
    for(pair<int,int> &value: v_p){
        cout << value.first << " " << value.second << endl;
    }
}

/*
    to directly print the values of elements of the vector without using iterators

    vector<int> v;
    for(int value: v){
        cout << value << " ";
    }
    vector<pair<int,int>> v1;
    for(pair<int,int> &value: v1){   // pass by reference
        cout << value.first << " " << value.second << endl;
    }

*/