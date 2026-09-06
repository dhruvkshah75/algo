#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/1461/D
// 1600 Rated Codeforces Question => Very Important Question 
// Uses precomputation to generate all possible sums that can be formed by using 

class Solution {
public:
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

    void solve() {
        // left contains <= mid and right > mid 
        possible_sums.clear();

        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for(int i=0; i<n; i++) 
            cin >> a[i];

        sort(a.begin(), a.end());

        // make a prefix sum array 
        vector<long long> prefix(n);
        prefix[0] = a[0]*1LL;
        for(int i=1; i<n; i++) 
            prefix[i] = prefix[i-1] + a[i]*1LL;

        // we call the function that precomputes all the possible sums 
        generate(a, prefix, 0, n-1);
        
        while(q--) {
            int S;
            cin >> S;
            if(possible_sums.find(S) != possible_sums.end())
                cout << "Yes" << endl;
            else 
                cout << "No" << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s = Solution();

    int t;
    cin >> t;
    while(t--)
        s.solve();
}