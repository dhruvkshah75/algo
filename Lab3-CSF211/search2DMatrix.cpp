#include<bits/stdc++.h>
using namespace std;

// question link: 

/*
    Algorithm: 
    Convert the 2d array into a single array with new indices and then we get a pattern

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m*n - 1;
        // make a single array 0,0 to 0,n-1 ... 
        // each index is i * n + j
        while(r-l>1) {
            int mid = l + (r - l)/2;
            int j = mid % n;
            int i = mid/ n;
            if(matrix[i][j] < target) {
                l = mid;
            }
            else r = mid;
        }
        int r1 = l % n, l1 = l / n;
        int r2 = r % n, l2 = r / n;
        if(matrix[l1][r1] == target) return true;
        else if(matrix[l2][r2] == target) return true;
        else return false;
    }
};

int main() {
    int n, m, target;
    cin >> n >> m >> target;
    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution s = Solution();
    bool ans = s.searchMatrix(matrix, target);

    string str = (ans) ? "true" : "false";

    cout << str << endl;
}