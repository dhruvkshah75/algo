#include<bits/stdc++.h>
using namespace std;

// vectors are similar to arrays they are arrays with dynamic size whose size can vary but arrays have a fixed size

// pass vectors by refernce as passing by a value is expensive as it has time complexity of O(n);

void print_Vec(vector<int> &v){
    cout << "size: " << v.size() << endl;  // time complexity of v.size() is O(1);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v;  // right now its size is 0 as it has nothing
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);   // time complexity of push_back is O(1) // adds x at the end of vector 
    }
    print_Vec(v);

    vector<int> v1(10);  // all values will be initialised to 0
    v1.push_back(7); // since the have dynamic length so 7 will be the 11th element 
    print_Vec(v1);

    vector<int> v2(10, 3);   // all the values be initialised to 3
    v2.push_back(11);   // adds element at the last 
    v2.pop_back();      // removes element from the last
    print_Vec(v2);

    vector<int> v3 = v;  //  time complexity is O(n)   // this is only copying (by value)  
    // vectors can directly be assigned but arrays cannot be 
    v3.push_back(10);
    print_Vec(v3);
    print_Vec(v);
    // time compleity of .push_back() and .pop_back() is O(1);

    vector<int> &v4 = v;
    v4.push_back(10);
    print_Vec(v4);



}


// locally declared vector can have a limit of the order of 1e5 elements. 
// globally declared vectors can have a limit of the order of 1e7 elements.
// as both store elements continously 