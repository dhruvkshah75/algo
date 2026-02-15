#include <bits/stdc++.h>
using namespace std;

set<long long> possible_sums;

void generate(vector<int>&A, vector<long long>&prefix, int left, int right) {
   
    long long curr_sum = prefix[right] - ((left > 0) ? prefix[left - 1] : 0);
    possible_sums.insert(curr_sum);

    // cannot further break
    if(A[left] == A[right])
        return;
    
    int mid_val = (A[left] + A[right]) / 2;

    auto it = upper_bound(A.begin() + left, A.begin() + right + 1, mid_val);
    int mid_index = distance(A.begin(), it);

    generate(A, prefix, left, mid_index - 1);
    generate(A, prefix, mid_index, right);
}

std::vector<int> solve(int n, std::vector<int> &A, int q, std::vector<int> &queries) {
    possible_sums.clear();

    sort(A.begin(), A.end());

    // n is the length of the array and q is the total no of queries 
    vector<long long> prefix(n);
    prefix[0] = (long long)A[0];
    for(int i=1; i<n; i++) {
        prefix[i] = prefix[i-1] + (long long)A[i];
    }

    // precompute all the possible sums for this question 
    generate(A, prefix, 0, n-1);

    vector<int> ans(q, 0);
    for(int i=0; i<q; i++) {
        if(possible_sums.find(queries[i]) != possible_sums.end())
            ans[i] = 1;
    }

    return ans;
}