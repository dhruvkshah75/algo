// ************************************ NEXT GREATER ELEMENT USING STACKS **********************************
// V.IMP CONCEPT    

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


/*
    given element 4 5 2 25 7 8
    NGE array     5 25 25 -1 8 -1
    traverse thru the array check if the ith element can be next greater element if not put in the stack;
    if the stack contains some element compare it with the next elements in the array if it bigger 
    then the element then fill that element in the nge array
*/
// stack is filled with indexes rather than values as this would make the code much easier.

void solve(vector<int> &a){

    stack<int> st;
    vector<int> nge(a.size());
    for(int i=0; i<a.size(); i++){
        while(!st.empty() && a[i] > a[st.top()]){
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nge[st.top()] = -1;
        st.pop();
    }

    for(int i=0; i<a.size(); i++){
        cout << a[i] << " " << ((nge[i] == -1)?-1:a[nge[i]]) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    solve(arr);
}