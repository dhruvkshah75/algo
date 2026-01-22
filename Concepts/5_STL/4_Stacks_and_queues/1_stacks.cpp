#include<bits/stdc++.h>
using namespace std;

/*
    NOTES: stacks are used in recursion 
    balanced parenthisis and next greater element can only be solved using stack;
    stacks are lifo last in first out 
*/

int main(){
    // only top element and stack size can be accessed
    // push operation, pop operation, top operation, top is to view, pop is remove and push is to insert;
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    while(!s.empty()){      // s.empty() returns true if s is empty
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}