/******************************************* The Monk and the class marks **********************************************/
/*
    given input is N no of students whose marks are given with it in the same line. 
    print the data of the students such that the marks are in a decreasing order, if two students have same marks 
    then print their names and marks in a lexicographically way

    Sample input:
    3
    Eve 78
    Bob 99
    Alice 78

    Sample output:
    Bob 99
    Alice 78
    Eve 78

**************************************************************************************************************************

*/

// the error can be caused is as two students with same name can exist and can also have the same name and it will be igored 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,multiset<string>> data;             // nesting is better as marks --->> set of names stored in a lexicographically order.
    for(int i=0; i<n; i++){
        string name;
        int marks;
        cin >> name >> marks;
        data[marks].insert(name);         // data[marks] is a set
    }
    map<int,multiset<string>>::iterator it;
    it = (--data.end());
    while(true){
        for(auto &s: it->second){
            cout << s << " " << it->first << endl;
        }
        if(it == data.begin()) break;
        it--;
    }
}


/*
    for(auto &it: map){
    
    } -> this loop always works in the forward manner so to print it in the reverse direction we can store the negative of the marks 
     and then print them through this loop it will print in the reverse direction

*/