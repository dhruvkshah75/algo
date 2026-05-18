#include<bits/stdc++.h>
using namespace std;

// question link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

// Solution for this question is actually very amazing 
// mat[i][j] = 1 this means that i knows j 

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        // we have n people at the party 
        stack<int> st;
        // store all the indices of the people in the party 
        for(int i=0; i<n; i++) {
            st.push(i);
        }
        // run this until the stack is empty or only one is left in it 
        while(st.size() > 1) {
            // pop out two indexes 
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if(mat[a][b] == 1) {
                // a knows b this means a is not the celebrity 
                st.push(b);
            }
            else {
                // mat[a][b] = 0 => this means a doesnt know b so b cant be the celebrity 
                // so remove a from the stack 
                st.push(a);
            }
        }
        // if one element reamins in the stack then we must verify if he is the celeb 
        if(st.empty()) return -1;
        
        int idx = st.top();

        for(int j=0; j<n; j++) {
            if(j == idx) continue;
            // the celeb shouldnt know anyone and everyone should know the celeb
            // so check the column of idx => mat[j][idx] should be 1 
            if(mat[idx][j] == 1 || mat[j][idx] == 0)
                return -1;
        }
        return idx;
        
    }
};

