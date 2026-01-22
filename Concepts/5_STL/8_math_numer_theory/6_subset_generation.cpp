#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


/*
    form a binaray no as the length of the array 
    eg 2 3 7 8 9
    subset [3, 8] in bitmask representation is 01010 where the ith bit is set means it contains the ith index element in the subset
    n sized array has 2^n no of subsets
    the subsets will have a bitmasks of no whose binary no ranges from nos 0 - 2^(n)-1
    eg array of 3 integers will have 8 subsets 
    bitmaks are binary representations of 0-7;
*/

vector<vector<int>> subsets(vector<int> &nums){
    int n = nums.size();
    int subset_ct = (1 << n);
    vector<vector<int>> subsets;
    for(int mask=0; mask<subset_ct; mask++){  // this is the bitmask representation of the subsets
        vector<int> s;
        for(int j=0; j<n; j++){
            if(mask & (1 << j) != 0){   // check if the jth bit is set or not 
                s.push_back(nums[j]);
            }
        }
        subsets.push_back(s);
    }
    return subsets;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<vector<int>> ans = subsets(a);
    for(auto &s: ans){
        for(auto &x: s){
            cout << x << " ";
        }
        cout << endl;
    }

}