#include<bits/stdc++.h>
using namespace std;

// question link: https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

// we must check if arr represents a correct maxHeap 
bool isMaxHeap(vector<int> &arr) {
    // check if every element is arr[parent(i)] >= arr[i];
    int n = arr.size();

    for(int i=1; i<n; i++) {
        int curr = arr[i];
        // the parent of i is floor((i-1)/2) => 0 based indexing 
        if(!(arr[(i-1)/2] >= arr[i])) 
            return false;
    }

    return true;
}

