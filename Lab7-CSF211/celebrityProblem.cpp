#include<bits/stdc++.h>
using namespace std;

// question link: https://www.geeksforgeeks.org/dsa/the-celebrity-problem/

int solve(vector<vector<int>> &mat) {
    int n = mat.size();
    // celebrity is the one who doesnt knows 0 people and n-1 people know him 
    // mat[i][j] = 1 means i knows j => outdegree[i]++ and indegree[j]++

    vector<int> indegree(n, 0), outdegree(n, 0); 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1) {
                indegree[j]++;
                outdegree[i]++;
            }
        }
    }

    // now get the celebrity => indegree[i] = n - 1 =>  all know him and outdegree[j] = 0 => he knows no one 
    for(int i = 0; i < n; i++) {
        if(indegree[i] == n - 1 && outdegree[i] == 0)
            return i;
    }

    return -1;
}