#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
// MEDIUM Leetcode Question

// Time Complexity: O(n*log(n)*log(m)) 


/*
    Algorithm: 
        We apply binary search on the answer that is what will the Kth element be 
        so we apply binary search from the min of the matrix to the max of the matrix 
        Then we apply a predicate function which returns FFFFFTTTTTT
        The T and F depends on how many elements are smaller than the x 
        We return T if there are more or equalt to k elements => find the first occurrence of T 
        We find how many elements are smaller than or equal to x in O(n*log(n))
*/

class Solution {
public:
    // predicate function that returns FFFFTTTT 
    // => we return true if more than k or equal to k elements are greater than x
    // we apply binary search on x => which is the ans 
    bool predicate(vector<vector<int>>& matrix, int k, int x) {
        int n = matrix.size();
        int ctr = 0;
        for(int i=0; i<n; i++) {
            if(matrix[i][0] <= x) {
                int l = 0, r = n-1;
                // simple upperbound implementation
                while(l <= r) {
                    int mid = l + (r - l) / 2;
                    if(matrix[i][mid] <= x) l = mid + 1;
                    else r = mid - 1;
                }
                ctr += l;
            }
            else break;
        }
        return ctr >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(predicate(matrix, k, mid)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution s = Solution();

    cout << s.kthSmallest(mat, k) << endl;
}

