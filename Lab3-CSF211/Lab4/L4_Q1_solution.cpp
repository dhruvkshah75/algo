#include<bits/stdc++.h>
using namespace std;

// VERY IMPORTANT Question 

int occurrenceRange(const vector<int>& indexes, int L, int R, int K) {
    // Find the first occurrence of P that appears at or after index L
    // lower_bound returns an iterator to the first element >= L
    auto it = lower_bound(indexes.begin(), indexes.end(), L);
    // Convert iterator to a vector index
    int start_pos = distance(indexes.begin(), it);
    
    // Jump to the K-th occurrence
    int target_pos = start_pos + (K - 1);
    
    // Does the K-th element exist in our list? Is it within the right boundary R?
    if (target_pos < indexes.size() && indexes[target_pos] <= R) {
        return indexes[target_pos];
    }
    
    return -1; // Not found or out of range
}

vector<int> solve(int n, int q, vector<int>& A, vector<vector<int>> &queries) {
    // The A is 1 based indexed 

    // we make a map<int,vector<int>> indexes where we store the indexes of each element
    // and then for each query we find the first index where greater than L and 
    // then check if the Kth occurrence of it exists and is less than R 
    
    map<int,vector<int>> indexes;
    for(int i=0; i<n; i++) {
        indexes[A[i]].push_back(i+1);
    }

    vector<int> ans;
    for(int i=0; i<q; i++) {
        int occurrence = occurrenceRange(
            indexes[queries[i][2]],
            queries[i][0],
            queries[i][1],
            queries[i][3]
        );

        ans.push_back(occurrence);

    }

    return ans;
}