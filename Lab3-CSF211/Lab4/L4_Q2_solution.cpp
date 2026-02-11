#include <vector>
#include <iostream>
#include <map>
#include <set>
#include<algorithm>
using namespace std;


set<long long> possible_sums;    // we precompute all the possible sums 

// we calculate all the possible sums of left and right arrays on splitting 
void generate(vector<int>&a, vector<long long>&prefix, int l, int r) {

    long long curr_sum = prefix[r] - ((l > 0) ? prefix[l-1] : 0);
    possible_sums.insert(curr_sum);

    // if the left and the right elements are same then we cannot split the array into left and right arrays 
    if(a[l] == a[r]) return;

    // now we find the mid element => technically the element just greater than mid element 
    int mid = (a[l] + a[r])/2;   
    auto mid_it = upper_bound(a.begin(), a.end(), mid);
    int mid_index = distance(a.begin(), mid_it);      // the distance method gives the index of the mid element 

    // recursively calling the function 
    generate(a, prefix, l, mid_index-1);
    generate(a, prefix, mid_index, r);
}
     
vector<bool> solve(int n, int q, vector<int>& A, vector<int> &queries) {
    possible_sums.clear();

    sort(A.begin(), A.end());

    vector<long long> prefix(n);
    prefix[0] = A[0]*1LL;
    for(int i=1; i<n; i++) 
        prefix[i] = prefix[i-1] + A[i]*1LL;

    // we call the function that precomputes all the possible sums 
    generate(A, prefix, 0, n-1);
    
    vector<bool> ans;
    for(int i=0; i<q; i++) {
        if(possible_sums.find(queries[i]) != possible_sums.end()) 
            ans.push_back(true);
        else 
            ans.push_back(false);
    }

    possible_sums.clear();

    return ans;

}