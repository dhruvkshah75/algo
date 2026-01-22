#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
        queue - fifo --->> first in first out
        main operations
            1. push -->> to add element after the first element
            2. pop -->> to remove the element from the start 
            3. front -->> to get the value of first data;
    */
    queue<string> q;
    q.push("abc");
    q.push("bcd");
    q.push("cde");
    q.push("def");
    q.push("ghi");
    while(!q.empty()){    // q.empty() returns true if the the queue is empty
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

}